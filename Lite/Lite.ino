#include <Servo.h>
#include "OneButton.h"

Servo servo;
Servo servo2;
 
OneButton button1(2, true); 
OneButton button2(4, true);
OneButton button3(7, true); 
OneButton button4(12, true);

byte Mode = 0;
byte Mode1 = 0;

void setup()
{ Serial.begin(9600);   
  button1.attachClick(Click1);
  button2.attachClick(Click2);
  button3.attachClick(Click3);
  button4.attachClick(Click4);
  servo.attach(9);
  servo2.attach(10);
  
  Serial.println("Starting TwoButtons...");
}


void loop()
{
  button1.tick();
  button2.tick();
  button3.tick();
  button4.tick();
  servo.write(Mode*45);
  servo2.write(Mode1*45);
  delay(10);
}

void Click1()
{
  Mode++;
  if(Mode > 2) Mode = 1;
  Serial.println("Button 1 click.");
}

void Click2()
{
  Serial.println("Button 2 click.");
  Mode=0;
  
}
void Click3()
{
  Mode1++;
  if(Mode1 > 2) Mode1 = 1;
  Serial.println("Button 3 click.");
}
void Click4()
{
  Serial.println("Button 4 click.");
  Mode1=0;
  
}
