/*Greetings,
 * This is Krishna vardhan. This code is modified from the default examples of Adafruit of ssd1306 which is the library of the Oled screen 128x64.
 * However, there is a modification to be done in the header file which is in our libraries location. 
 */

#include <SPI.h>      //including header libraries like serial peripheral(spi),wire               
#include <Wire.h>
#include <Adafruit_GFX.h> //This is the core graphics library for all our displays, providing a common set of graphics primitives such as points, lines, circles, etc.
#include <Adafruit_SSD1306.h> // This is a library for our Monochrome OLEDs based on SSD1306 drivers. 
#include <Adafruit_I2CDevice.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0 //defining the x & y positions to our led
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH 16

static const unsigned char PROGMEM logo16_glcd_bmp[] = 
{
  B00000000, B11000000, B00000001, B11000000,
  B00000001, B11000000, B00000011, B11100000, 
  B11110011, B11100000, B11111110, B11111000,
  B01111110, B11111111, B00110011, B10011111,
  B00011111, B11111100, B00001101, B01110000,
  B00011011, B10100000,B00111111, B11100000, 
  B00111111, B11110000, B01111100, B11110000,
  B01110000, B01110000, B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
Serial.begin(9600);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3D (for the 128x64)
display.display(); 
//delay(2000);
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(10, 0);
display.clearDisplay();
display.println("INPUT YOUR TEXT HERE: ");

// Inverting the display

display.invertDisplay(true);
display.invertDisplay(false);
display.display();
display.clearDisplay(); }

void loop() {

while (1) {

display.setTextSize(1);
display.setTextColor(WHITE);  //color can be changed and the text size as well. however we can change our fonts as well but we have not done that in this project.
display.setCursor(10, 0);
display.clearDisplay();
display.println("input:");
printText();
display.display();

}

}

void printText(void) {
String s;
if (Serial.available()) {

s = Serial.readString(); //getting string input in variable "s"
display.println(s); //display in serial monitor
Serial.println(s);  // display in ssd1306
display.display();
display.println("\n"); // after every lock position, go to new line

}

delay(4000);

}
