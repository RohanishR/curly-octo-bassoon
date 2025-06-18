# curly-octo-bassoon
# 🎯 Arduino-Based Motion-Tracking Turret

A smart servo-powered turret that detects nearby objects and "locks on" using an ultrasonic sensor, laser diode, LED, and buzzer. Built using the Arduino UNO R4 Minima and designed for DIY robotics, automation, and embedded systems exploration.

---

## ✨ Features

- 🟢 **Motion detection** using HC-SR04 (ultrasonic sensor)
- 🎯 **Target tracking** with SG90 servo motor
- 🔴 **Laser diode** stays ON while scanning, blinks when locked on
- 💡 **LED indicator** activates on detection
- 🔊 **Buzzer alert** synchronized with laser blinking
- 🔁 **Smooth scanning motion** resumes when no object is in range
- 🧠 **Intelligent movement**—servo halts during lock, no jitter

---

## 🧰 Components Used

| Component                   | Quantity |
|----------------------------|----------|
| Arduino UNO R4 Minima      | 1        |
| HC-SR04 Ultrasonic Sensor  | 1        |
| SG90 Servo Motor           | 1        |
| 650nm Laser Diode Module   | 1        |
| LED + 220Ω Resistor        | 1        |
| Buzzer (Active/Passive)    | 1        |
| Jumper Wires, Breadboard   | as needed |

---


---

## 🧠 Logic Overview

- Servo sweeps continuously when no object is detected (range > 30 cm).
- When an object comes within 30 cm:
  - Servo halts and locks to its mapped angle.
  - Laser and buzzer blink rapidly.
  - LED stays lit to indicate target presence.
- When object disappears:
  - System resumes sweeping.
  - Laser returns to steady ON; buzzer stops; LED turns off.

---

## 🚀 Getting Started

1. Upload the `.ino` sketch to your Arduino UNO R4 Minima.
2. Connect the components using the wiring above.
3. Power the Arduino (USB or external 5V supply).
4. Watch it scan and lock onto targets like a smart sentry!


Made by [Rohanish Raman]

