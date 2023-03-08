# Arduino-Matlab-Control

This project is a Matlab script that can control a Nema 17 stepper motor using an Arduino CNC Shield V3 and an A4988 driver.

## Installation and Usage

To use this project, you need to have Matlab and Arduino IDE installed on your computer. You also need to connect your Arduino board with the CNC shield  V3 (A4988 Driver) and the Nema 17 Stepper Motor via a USB cable.

1. Open the Arduino IDE and upload the sketch `arduino.ino` to your board. This sketch will receive commands from Matlab and move the stepper motor accordingly.
2. Install the MATLAB Support Package for Arduino Hardware² following this video tutorial³.
3. Open Matlab and run the script `matlab.m`. This script will establish a serial connection with your Arduino board and prompt you to enter commands.
4. Enter 1 to move up, 2 to move down, 3 to move right, 4 to move left, or 0 to stop and disconnect.

If you encounter any error messages such as "Port: COM Port is not available. No ports are available.", try running `fclose(instrfind);` in Matlab.

## Contributors and License

This project was created by [your name] as a personal project. You are free to use, modify, and distribute it as you wish.

## Contact and Feedback

If you have any questions or suggestions about this project, please feel free to contact me at [your email] or leave an issue on GitHub.
