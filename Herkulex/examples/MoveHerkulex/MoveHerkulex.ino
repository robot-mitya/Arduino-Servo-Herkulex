#include "Herkulex.h"

int n=0xfd; //motor ID - verify your ID !!!!

void setup()
{
  //long baud = 115200;
  long baud = 57600;
  
  delay(2000);  //a delay to have time for serial monitor opening
  Serial.begin(baud);    // Open serial communications
  Serial.println("Begin");
  Herkulex.begin(baud, 10, 11); //open serial with rx=10 and tx=11 
  Herkulex.reboot(n); //reboot first motor
  delay(500); 
  Herkulex.initialize(); //initialize motors
  delay(200);

  Serial.print("Stat:");
  Serial.println(Herkulex.stat(n));
  Serial.print("Model:");
  Serial.println(Herkulex.model());
  Serial.println();

  Herkulex.writeRegistryRAM(n, 47, 0);

  for (int i = 0; i < 1; i++)
  {
    Serial.println("Move Angle: -100 degrees");
    Herkulex.moveOneAngle(n, -100, 1000, LED_BLUE); //move motor with 300 speed  
    delay(1200);
    Serial.print("Get servo Angle:");
    Serial.println(Herkulex.getAngle(n));
    Serial.print("Get servo Position:");
    Serial.println(Herkulex.getPosition(n));
    Serial.println();

    Serial.println("Move Angle: 100 degrees");
    Herkulex.moveOneAngle(n, 100, 1000, LED_BLUE); //move motor with 300 speed  
    delay(1200);
    Serial.print("Get servo Angle:");
    Serial.println(Herkulex.getAngle(n));
    Serial.print("Get servo Position:");
    Serial.println(Herkulex.getPosition(n));
    Serial.println();
  }

  Serial.println("Move Angle: 0 degrees");
  Herkulex.moveOneAngle(n, 0, 1000, 0);
  delay(1200);
//  Serial.print("Get servo Angle:");
//  Serial.println(Herkulex.getAngle(n));
//  Serial.print("Get servo Position:");
//  Serial.println(Herkulex.getPosition(n));

//  long colorDelay = 100;
//  Herkulex.setLed(n, LED_GREEN);
//  delay(colorDelay);
//  Herkulex.setLed(n, LED_BLUE);
//  delay(colorDelay);
//  Herkulex.setLed(n, LED_CYAN);
//  delay(colorDelay);
//  Herkulex.setLed(n, LED_RED);
//  delay(colorDelay);
//  Herkulex.setLed(n, LED_GREEN2);
//  delay(colorDelay);
//  Herkulex.setLed(n, LED_PINK);
//  delay(colorDelay);
//  Herkulex.setLed(n, LED_WHITE);
//  delay(colorDelay);
//  Herkulex.setLed(n, 0);
//  delay(colorDelay);

//  Herkulex.torqueOFF(n);
}

void loop()
{
}
