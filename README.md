# 🏠 Home Automation using ESP8266 & Sinric Pro  

## 📌 Project Overview  
This project is a **Smart Home Automation System** built with the **ESP8266 NodeMCU**, which allows you to control **Fan, LED, and Motor** using:  
- ✅ **Google Assistant (Voice Control)**  
- ✅ **Sinric Pro Mobile App (Cloud IoT)**  
- ✅ **Manual Push Buttons**  

It also provides **real-time device status monitoring** via the Serial Monitor.  

---

## ⚡ Features  
- Control appliances (Fan, LED, Motor) through **Wi-Fi**.  
- Works with **Google Assistant voice commands**.  
- Manual control using **physical push buttons**.  
- Relay-based switching for high-power devices.  
- Serial Monitor displays **device states & Wi-Fi status**.  

---

## 🛠️ Components Used  
- ESP8266 NodeMCU  
- 3 × Relay Module (5V)  
- 1 × Fan (AC/DC)  
- 1 × LED  
- 1 × Motor  
- 3 × Push Buttons (Input Pull-up)  
- Wi-Fi Router  

---

## 🔌 Circuit Connections  
- **D1 → Relay1 (Fan)**  
- **D2 → Relay2 (LED)**  
- **D3 → Relay3 (Motor)**  
- **D5 → Button1 (Fan Button)**  
- **D6 → Button2 (LED Button)**  
- **D7 → Button3 (Motor Button)**  
- **3.3V → ESP8266 & Buttons**  
- **5V → Relays**  
- **GND → Common Ground**  

*(Circuit diagram will be added in Circuit/ folder later)*  

---

## 💻 Code  
The Arduino `.ino` file is provided in the `Code/` folder.  
- Written in **Arduino IDE**.  
- Uses the **Sinric Pro library** for cloud connectivity.  
- Configurable with your **Wi-Fi SSID, Password, and Sinric Pro credentials**.  

---

## 🚀 How to Run  
1. Install Arduino IDE.  
2. Add ESP8266 board package.  
3. Install **Sinric Pro Arduino Library**.  
4. Open `Code/HomeAutomation.ino`.  
5. Enter your Wi-Fi and Sinric Pro credentials.  
6. Upload to NodeMCU.  
7. Test via Google Assistant, Sinric App, or buttons.  

---

## 📂 Repository Structure  
```
Home_Automation_ESP8266/
│── Code/
│    └── HomeAutomation.ino
│── Circuit/
│    └── Circuit_Diagram.png   (to be added)
│── Report/
│    └── Project_Report.pdf    (to be added)
│── Media/
│    └── Demo_Video.mp4        (to be added)
│── README.md
```

---

## 📷 Demo (optional)  
*(Upload images or video later here)*  

---

## 📜 License  
This project is open-source. You can use and modify it freely for educational and personal purposes.  
