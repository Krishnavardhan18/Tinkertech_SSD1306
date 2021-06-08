# ssd1306
The code is written such that the data is collected from the serial monitor for unlimited strings and characters that are displayed on the SSD1306. The code supports contents to scroll down to the next line once the character/ string reaches the end of the width and length of the screen. Here we have chosen SSD1306x64. The code is modified from the default examples of Adafruit of ssd1306 which is the library of the i2c Oled screen 128x64.
However, there is a modification to be done in the header file which is in our libraries location. 

The project aims to display the content read from the software serial. Here we use Arduino IDE as the software and the hardware components are; 1. Arduino Pro mini or Arduino UNO and the i2c OLED screen which is SSD1306(x64 in my case).
The connections are as follows:
1. VCC to arduino 5v 
2. GND to arduino GND 
3. SCL to arduino pin A5 
4. SDA to arduino pin A4

