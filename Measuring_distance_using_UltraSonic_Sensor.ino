//DISTANCE MEASUREMENT USING ULTRASONIC SENSOR
//10 JULY 2020
//BY PRADEEP RAJ (M.P.R)
//          ------THIS CODE IS OPEN SOURCE FOR OUR SUBSCRIBERS------
//                         ------ THE FAUCETER ------

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,&Wire,OLED_RESET);

int trig = 6 ;
int echo = 7 ;

int distanceCm ;
int distanceInch ;

void setup() {

  pinMode(trig, OUTPUT) ; 
  pinMode(echo, INPUT) ;
  Serial.begin(9600) ; 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {

   digitalWrite(trig,LOW) ;
   delay(2);

   digitalWrite(trig,HIGH) ;
   delay(10);
   digitalWrite(trig,LOW);

   int duration = pulseIn(echo,HIGH);
   distanceCm = duration*0.034/2 ;
   distanceInch = duration*0.0133/2;

   Serial.print("Object at a Distance(in Cm) of : ");
   Serial.println(distanceCm);
   Serial.print("Object at a Distance(in Inch) of : ");
   Serial.println(distanceInch);
   oledcm();
   oledinch();
  
}

void oledcm(void) {
 display.clearDisplay();
  
  display.setTextSize(2);          
  display.setTextColor(SSD1306_WHITE);        
  display.setCursor(0,2);             
  display.println(" Distance   in Cm   ");
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(35,40);
  display.println(distanceCm);
  
  
  display.display();
  delay(1000); 
}

void oledinch(void) {
 display.clearDisplay();
  
  display.setTextSize(2);          
  display.setTextColor(SSD1306_WHITE);        
  display.setCursor(0,2);             
  display.println(" Distance   in Inch   ");
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(35,40);
  display.println(distanceInch);
  
  
  display.display();
  delay(1000); 
}
//---------------------------------------------------------------------------------THE FAUCETER----------------------------------------------------------------------------------------
