
/* Kegerator Control: arduino based fridge temperature controller
 *  stage one including:
 *  - Arduino Uno clone
 *  - lcd display
 *  - rotary encoder for changing temperature
 *  - two temperature probes DS18B20 using one wire bus
 *  - relay for turning compressor on and off
 *  --
 *  stage two including:
 *  - logging using ESP-01 and Ai Thinker commands over hardware serial
 *  stage three including:
 *  - full control and status via ESP-01
 * 
 * The LCD circuit for the LCD HelloWorld. We will use the same pin configuration:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
#include <OneWire.h>            //to enable the DS18B20s
#include <DallasTemperature.h>  //to manipulate the DS18B20s
#include <LiquidCrystal.h>      //to set up the LCD

// #define constants
#define ONE_WIRE_BUS 10
#define TEMPERATURE_PRECISION 11
#define LCD_RS 12
#define LCD_Enable 11
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2

// #define global variables
float upperTempC=0, lowerTempC=0;

//initializations
LiquidCrystal lcd(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7); //set up the LCD as per the notes above regarding pins

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
// arrays to hold device addresses
DeviceAddress upperThermometer, lowerThermometer;

void setup() {
  Serial.begin(9600); //init serial communication  
  sensors.begin();    //start the DallasTemp sensors

  //set initial thermometer addresses
  if (!sensors.getAddress(upperThermometer, 0)) Serial.println("Unable to find address for Device 0"); 
  if (!sensors.getAddress(lowerThermometer, 1)) Serial.println("Unable to find address for Device 1"); 
  
  sensors.setResolution(upperThermometer, TEMPERATURE_PRECISION);
  sensors.setResolution(lowerThermometer, TEMPERATURE_PRECISION);

  
}

void loop() {
  
}
