# ESP32 Wi-Fi Remote Motor Controller

This project lets you wirelessly control a motor using an ESP32, MD10C motor driver, and a custom RemoteXY interface. Built for testing and demonstration of Wi-Fi-based remote control systems.

## Features

- Wi-Fi-based motor control
- RemoteXY GUI for easy interfacing
- Supports direction and speed control
- Custom motor driver logic (MD10C)
- Real-time wireless communication

## Hardware Used

- ESP32 (e.g., DevKit V1)
- Cytron MD10C motor driver
- DC motor
- Power supply
- Optional: battery, chassis, encoder

## Software Used

- [RemoteXY](https://remotexy.com/)
- PlatformIO / Arduino IDE
- ESP32 Wi-Fi libraries

## RemoteXY GUI Layout
![WhatsApp Image 2025-08-03 at 3 15 00 PM](https://github.com/user-attachments/assets/69c8dc65-ed22-463d-bcd0-585ad4caeaa4)

## 🕹 RemoteXY Control Modes

This ESP32 robot is controlled via **RemoteXY WiFi GUI**, where the text field (`edit_1`) is used to switch between control modes, and four buttons perform different actions depending on the selected mode.

| Mode (`edit_1`) | F/R                    |  B/L                   | </S                        | R/>                        | 
|-----------------|------------------------|------------------------|----------------------------|----------------------------|
| `move`          | Move Forward           | Move Backward          | Decrease Speed             | Increase Speed             |
| `spot`          | Spot Turn CW           | Spot Turn CCW          | Side Shift Left            | Side Shift Right           |
| `acer`          | Accelerate Forward     | Accelerate Reverse     | Steer Left                 | Steer Right                |
| `backacer`      | Accelerate Forward     | Accelerate Reverse     | Rear Steer Left            | Rear Steer Right           |
| `holomonic`     | Move Forward           | Move Backward          | Lateral Move Left          | Lateral Move Right         |
| `frs`           | Increase FR Speed      | Decrease FR Speed      | Rotate FR Left (DIR=0)     | Rotate FR Right (DIR=1)    |
| `fls`           | Increase FL Speed      | Decrease FL Speed      | Rotate FL Left (DIR=0)     | Rotate FL Right (DIR=1)    |
| `brs`           | Increase BR Speed      | Decrease BR Speed      | Rotate BR Left (DIR=0)     | Rotate BR Right (DIR=1)    |
| `bls`           | Increase BL Speed      | Decrease BL Speed      | Rotate BL Left (DIR=0)     | Rotate BL Right (DIR=1)    |


🔧 How to Use
Connect to ESP32 WiFi named: classic

Open the RemoteXY app with the preconfigured GUI.

In the text field, enter a mode keyword like:

move

acer

holomonic

Use the 4 buttons to perform actions listed above.

## How It Works

1. Connect ESP32 to MD10C.
2. Load firmware using PlatformIO.
3. ESP32 connects to your Wi-Fi or becomes an access point.
4. Use the RemoteXY mobile app to control the motor wirelessly.




