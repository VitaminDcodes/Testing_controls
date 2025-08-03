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
![WhatsApp Image 2025-08-03 at 3 11 52 PM](https://github.com/user-attachments/assets/7de610da-9532-4b70-a234-ebb527899216)



## How It Works

1. Connect ESP32 to MD10C.
2. Load firmware using PlatformIO.
3. ESP32 connects to your Wi-Fi or becomes an access point.
4. Use the RemoteXY mobile app to control the motor wirelessly.




