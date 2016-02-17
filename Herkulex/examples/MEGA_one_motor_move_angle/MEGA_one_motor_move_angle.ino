#include <Herkulex.h>
int n=0xfd; //motor ID - verify your ID (0xFD is default) !!!!

void setup()
{
  delay(2000);  //a delay to have time for serial monitor opening
  Serial.begin(115200);    // Open serial communications
  Serial.println("Begin");
  Serial1.begin(115200); //open serial port 1
  Herkulex.begin(&Serial1); // And pass a pointer to it to the API class
  Herkulex.reboot(n); //reboot first motor
  delay(500);
  Herkulex.initialize(); //initialize motors
  delay(200);
}

void loop(){
  Serial.print("Servo ");
  Serial.print(n, DEC);
  Serial.print(" status 0x");
  Serial.print(Herkulex.stat(n), HEX);
  Serial.println();
  Serial.println("Move Angle: -100 degrees");
  Herkulex.moveOneAngle(n, -100, 1000, LED_BLUE); //move motor with 300 speed  
  delay(1200);
  Serial.print("Get servo Angle:");
  Serial.println(Herkulex.getAngle(n));
  Serial.println("Move Angle: 100 degrees");
  Herkulex.moveOneAngle(n, 100, 1000, LED_BLUE); //move motor with 300 speed  
  delay(1200);
  Serial.print("Get servo Angle:");
  Serial.println(Herkulex.getAngle(n));
}
