# Gas-Leakage-Detection-System
A smart IoT-based system for detecting LPG/Butane gas leakage and providing real-time alerts using ESP32, MQ sensors, and safety mechanisms.
🔥 Gas Leakage Detection & Alerting System

A smart IoT-based system for detecting LPG/Butane gas leakage and providing real-time alerts using ESP32, MQ sensors, and safety mechanisms.

📌 Overview

This project monitors gas levels using an MQ-series sensor (MQ-2 / MQ-6).
When gas leakage is detected, the system triggers:

🔊 Alarm (buzzer)

💡 Visual alert (LED)

🔒 Automatic gas valve shutdown via relay

📲 Optional notifications via WiFi or SMS (SIM800L)

🧩 Components

ESP32 microcontroller

MQ-2 or MQ-6 gas sensor

Relay module (5V or 12V)

Buzzer

LED (optional)

Solenoid gas valve

Power supply

Optional GSM: SIM800L

🔧 System Architecture
[Gas Sensor MQ] → [ESP32 ADC] → 
    ├── Buzzer Alarm  
    ├── LED Alert  
    ├── Relay → Gas Valve  
    └── WiFi / SMS Notification  

📡 Features

✔ Continuous gas monitoring
✔ Adjustable thresholds
✔ Automatic gas shutoff
✔ Real-time notification options
✔ Low-cost & scalable design

🛠 ESP32 Code

➡️ The full code will be added soon under /src folder.

🧪 Testing & Calibration

Preheat MQ sensor for 24h (first use)

Record clean-air baseline

Adjust thresholds according to environment

Perform controlled gas test safely

⚠ Safety Notice

This project is for educational purposes.
Never test gas leaks in a closed or unsafe environment.
Always follow safety protocol.

📷 Project Images

![Wiring Diagram](diagrams/wiring.png1)

📁 Project Structure
Gas-Leakage-Detection-System/
│
├── README.md
├── src/
│   └── code.ino   (ESP32 code)
├── diagrams/
│   └── wiring.png
└── assets/
    └── project-photos/

🚀 Author

Created by: Aya Agili
Project type: IoT / Embedded Systems / Safety Engineering
