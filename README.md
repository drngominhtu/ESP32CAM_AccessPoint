## Project Overview
This project configures the ESP32-CAM to function as a standalone Wi-Fi Access Point. Once powered on, the device broadcasts its own Wi-Fi network. Users can connect to this network using a smartphone or computer and view the live camera feed through a web browser.​

🧾 Repository Contents
main.ino: The primary Arduino sketch that initializes the camera, sets up the Access Point, and handles HTTP requests to serve the video stream.​

camera_pins.h: A header file defining the pin configuration for the ESP32-CAM module, ensuring correct communication with the camera hardware.​

🚀 Getting Started
Prerequisites
ESP32-CAM module​
GitHub

Arduino IDE with the ESP32 board support installed​

Installation
Clone this repository or download the ZIP file and extract it.​

Open main.ino in the Arduino IDE.​

Connect your ESP32-CAM module to your computer via USB.​

Select the appropriate board and port in the Arduino IDE:​

Board: "AI Thinker ESP32-CAM"​

Port: [Select the correct COM port]​

Upload the sketch to the ESP32-CAM module.​

Usage
After uploading, the ESP32-CAM will restart and create a Wi-Fi network named, for example, ESP32-CAM-AP.​

Connect your smartphone or computer to this Wi-Fi network.​

Open a web browser and navigate to http://192.168.4.1/.​

You should see the live video stream from the ESP32-CAM.​

⚠️ Disclaimer
This project is intended for educational and personal use only.
Do not use this project for illegal or unethical purposes, including but not limited to:

Unauthorized surveillance

Hidden or covert recording

Privacy invasion or any form of spying

Using this system to secretly record others without their consent may violate local laws and regulations. Always respect privacy and obtain permission when necessary.

Thanks for reading!
-Thomas-
