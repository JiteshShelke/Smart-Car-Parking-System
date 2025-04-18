# 🚗💡Smart Car Parking System

**Smart Car Parking** is a smart car parking solution that automates parking slot management using **Arduino UNO** and **NodeMCU ESP8266**.  
It detects cars using **IR sensors**, controls a **servo motor gate**, displays availability on an **LCD**, and sends live updates to the **Blynk IoT** app.

---

## 👨‍💻 Developer

**🧑‍🔬 Jitesh Santosh Shelke**  
🎓 *M.Sc. Data Analytics* — Pillai College of Arts, Commerce and Science (Autonomous)  
🛠 Passionate about **IoT**, **AI**, **Machine Learning**, and **Smart Infrastructure**  
🌐 [GitHub](https://github.com/JiteshShelke) • [LinkedIn](https://linkedin.com/in/jitesh-shelke-702745286/)

---

## 📌 Features

- 🟢 IR-based vehicle detection (Entry/Exit)
- 🚧 Automatic barrier gate using Servo motor
- 📟 Real-time parking status on 16x2 LCD
- 📡 Sends data to **Blynk Cloud** using NodeMCU ESP8266
- 📱 Live slot updates on mobile via Blynk IoT app
- ✅ Tracks 3 individual parking slots

---

## 🎥 Watch the Demo

[![Smart Car Parking System](https://img.youtube.com/vi/UcszXU9vbh8/0.jpg)](https://www.youtube.com/watch?v=UcszXU9vbh8)



## 🛠️ Hardware Components

| 🔧 Component             | 📦 Quantity |
|-------------------------|-------------|
| Arduino UNO             | 1           |
| NodeMCU ESP8266         | 1           |
| IR Sensors              | 5 (2 for gate, 3 for slots) |
| Servo Motor (SG90)      | 1           |
| 16x2 LCD with I2C       | 1           |
| Jumper Wires            | —           |
| Breadboard              | 1           |
| Power Supply (5V/9V)    | 1           |

---

## 💻 Software Requirements

- 🔌 Arduino IDE
- 📲 Blynk IoT App (Android/iOS)
- 📚 Blynk Libraries for ESP8266
- ⚙️ ESP8266 Board Package for Arduino IDE

---

## ⚙️ Circuit Overview

- **IR1**: Detects vehicle at entrance  
- **IR2**: Detects vehicle at exit  
- **IR3 - IR5**: Monitors 3 parking slots  
- **Servo Motor**: Opens/closes entry gate  
- **LCD**: Displays available slots  
- **NodeMCU**: Sends updates to Blynk app

---

## 📥 Arduino Code (`arduino_parking_controller.ino`)

- Controls gate barrier with Servo
- Tracks slot availability
- Displays status on LCD
- Sends slot data to NodeMCU using SoftwareSerial

---

## 📡 NodeMCU Code (`nodemcu_parking_blynk.ino`)

- Receives data from Arduino via Serial
- Pushes slot info to Blynk Cloud
- Updates Virtual Pins **V0**, **V1**, **V2**

---

## 📲 Blynk Setup

1. Install **Blynk IoT** app  
2. Create new project → Select **ESP8266**  
3. Add 3 **Value Display** widgets  
4. Link widgets to **V0**, **V1**, **V2**  
5. Paste your **Auth Token** in NodeMCU sketch

---

## 🔌 Pin Connections

### Arduino UNO

| Sensor/Device     | Pin  |
|------------------|------|
| IR1 (Entry)       | D8   |
| IR2 (Exit)        | D9   |
| Slot 1 IR         | D5   |
| Slot 2 IR         | D6   |
| Slot 3 IR         | D7   |
| Servo             | D10  |
| TX → NodeMCU RX   | D2   |
| RX ← NodeMCU TX   | D3   |

### NodeMCU ESP8266

| Device         | Pin     |
|----------------|---------|
| RX ← Arduino TX | D7     |
| TX → Arduino RX | D8     |

> ⚠️ Use voltage divider/logic level shifter between Arduino TX and NodeMCU RX.

---

## 🖥 LCD Output

- Displays: `Available: X`
- If full: `Parking Full`
- Gate logic is synced with slot availability

---

## 📱 Blynk App Output

- V0: Slot 1 status (Free/Occupied)  
- V1: Slot 2 status  
- V2: Slot 3 status  
- Real-time updates with each car entry/exit

---

## 🚦 Gate Logic

| Condition                      | Action        |
|-------------------------------|---------------|
| 🚘 Vehicle at Entry & Slot Free | Gate Opens    |
| ✅ Car Parked                  | Slot Occupied |
| 🚗 Vehicle at Exit            | Slot Released |
| ❌ No Slot Available          | Gate Closed   |

---

## 📝 Future Improvements

- 💳 Add payment gateway
- 📷 License Plate Recognition (LPR)
- 📊 Firebase or custom dashboard integration
- 🧠 Ultrasonic sensors for better accuracy
- 🔍 AI-based analytics and insights

---

## 🖼️ Optional UI Add-ons

- 🚗 Car entry/exit animation (GIF)
- 📱 Blynk app UI mockup
- 🧭 Dashboard with live monitoring
- 📸 Camera sensor extensions (future)

---

## ✅ Summary

**PARKEASE** is an efficient, low-cost smart parking system using IoT components.  
Ideal for college, office, or small mall parking automation.  
Get real-time updates and enjoy smart infrastructure benefits with minimal investment.

---
