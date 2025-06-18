#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int laserPin = 7;
const int ledPin = 6;
const int servoPin = 11;
const int buzzerPin = 12;

Servo tracker;

int sweepAngle = 0;
int sweepDirection = 1;
bool targetFound = false;
int lastAngle = -1;  // To store previous angle and prevent jitter

void setup() {
  Serial.begin(9600);
  tracker.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  digitalWrite(laserPin, LOW);
  tracker.write(90);  // Start centered
}

void loop() {
  long duration;
  int distance;

  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 20000);  // 20ms timeout
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 30) {
    int targetAngle = map(distance, 5, 30, 0, 180);
    targetAngle = constrain(targetAngle, 0, 180);

    if (!targetFound) {
      tracker.write(targetAngle);
      lastAngle = targetAngle;
      targetFound = true;
      digitalWrite(ledPin, HIGH);
    }

    // 🔁 Sync laser + buzzer blinking (every 100ms)
    bool blinkState = (millis() / 100) % 2;
    digitalWrite(laserPin, blinkState);
    digitalWrite(buzzerPin, blinkState);

  } else {
    // 🚨 Resume sweep, laser solid ON, buzzer off
    digitalWrite(ledPin, LOW);
    digitalWrite(laserPin, HIGH);
    digitalWrite(buzzerPin, LOW);

    if (targetFound) {
      targetFound = false;
      lastAngle = sweepAngle;
      delay(300);
    }

    tracker.write(sweepAngle);
    sweepAngle += sweepDirection;

    if (sweepAngle >= 180 || sweepAngle <= 0) {
      sweepDirection *= -1;
    }
  }
  delay(50);  // Adjust for smoother motion
}