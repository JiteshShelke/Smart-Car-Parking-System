# 🚘 Smart Car Parking System (PARKEASE)

An IoT-powered, real-time Smart Car Parking System using **Arduino UNO**, **ESP8266 NodeMCU**, **IR sensors**, and the **Blynk App**. This project automates parking slot detection, gate control, and real-time slot monitoring to reduce congestion, fuel consumption, and user frustration — paving the way for smarter cities 🚦🌆.

---

## ✨ Features

- 🔍 **Real-time Parking Slot Detection** using IR Sensors  
- 🧠 **Automated Entry/Exit Control** via Servo Motors  
- 📟 **LCD Display** to show available slots  
- 📲 **Live Parking Data on Mobile** (via Blynk IoT App)  
- ☁️ **Cloud Integration** with Blynk Server  
- 🔋 **Energy Efficient** and Scalable for smart cities  

---

## 🧰 Tech Stack & Components

### 💡 Hardware
- 🔌 Arduino UNO  
- 🌐 ESP8266 NodeMCU  
- 👁 IR Sensors  
- 📟 16x2 LCD Display  
- ⚙️ Servo Motors  

### 🛠 Software & Platforms
- 💻 Arduino IDE  
- 📱 Blynk IoT App  
- 📊 Blynk Cloud Dashboard  
- 🔁 SoftwareSerial for UART communication  

---

## 🔋 System Architecture & Flow

📶 **Sensor Input** → 🧠 **NodeMCU Decision** → 🚦 **Gate Control** → 📲 **Mobile Notification**

> *(Insert your block diagram or circuit image here)*

---

## 📷 Screenshots

📸 *Add images from your setup here:*  
- IR sensor in action  
- LCD showing available slots  
- Blynk app dashboard  

---

## 🔢 How It Works

```c
// Arduino: IR + Servo + LCD + Serial
// NodeMCU: Serial In + Send to Blynk
// Blynk: V1/V2/V3 for slots, V4 for total count
```

1. Car is detected by entry IR sensor  
2. Slot availability checked via 3 internal IR sensors  
3. If available → Servo opens gate, LCD updates slot  
4. NodeMCU sends data to Blynk app (via UART)  
5. App updates user in real-time 📲  

---

## 📈 Results

| Test Scenario                     | Expected Result       | Status ✅ |
|----------------------------------|------------------------|-----------|
| Vehicle enters with slot         | Gate opens             | ✅ Pass   |
| Vehicle enters when full         | Gate stays closed      | ✅ Pass   |
| Slot is vacated                  | Slot updates on LCD    | ✅ Pass   |
| Remote app shows slot status     | Accurate & real-time   | ✅ Pass   |

---

## 🚀 Future Scope

- 🤖 ML for predictive parking & reservation  
- 🔐 License Plate Detection for Security  
- 🔋 Solar-powered sensors for sustainability  
- 🧠 Voice-based smart assistance for users  

---

## 👨‍💻 Developer

**Jitesh Santosh Shelke**  
🎓 M.Sc. Data Analytics — Pillai College of Arts, Commerce and Science (Autonomous)  
🛠 Passionate about IoT, AI, ML, and Smart Infrastructure  

---

## 🔗 Resources

- [Arduino](https://www.arduino.cc/)  
- [ESP8266](https://www.espressif.com/en/products/socs/esp8266)  
- [Blynk IoT](https://blynk.io/)  
- [Infrared Sensor Guide](https://www.electronicshub.org/infrared-sensor/)  

---

## 📫 Connect with Me

[![LinkedIn](https://img.shields.io/badge/-LinkedIn-blue?style=flat-square&logo=linkedin)](https://www.linkedin.com/in/jitesh-shelke-702745286/)  
[![GitHub](https://img.shields.io/badge/-GitHub-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/JiteshShelke)

---

> 🚗 **"Smart parking today, smarter cities tomorrow."**  
> — *Made with ❤️ by Jitesh Shelke*
