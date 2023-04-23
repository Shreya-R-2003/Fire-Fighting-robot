/*------ Arduino Fire Fighting Robot Code by hobby project---- */
 
#include <Servo.h>  //include servo.h library
Servo myservo;
 
int pos = 0;    
boolean fire = false;
 
#define Left 9      // left sensor
#define Right 10    // right sensor
#define Forward 8   //front sensor

#define LM1 2       // left motor
#define LM2 3       // left motor
#define RM1 4       // right motor
#define RM2 5       // right motor
#define pump 7  // modified from 6 to 7
 
void setup()
{
   //Serial.begin(9600);
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);
 
  myservo.attach(11);
  myservo.write(120); 
}
 
void put_off_fire()
 {
 // Serial.print("put off fire.. ");
    //delay (500);
 
    // brake all wheels and stop vehicle
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);

    delay(500);
    
  digitalWrite(pump, HIGH); // start water flow
    delay(100);
    digitalWrite(pump,LOW); // turn off water pump
    digitalWrite(pump,LOW); 
    // turn jet left to right
    for (pos = 50; pos <= 130; pos += 1) { 
    myservo.write(pos);
    delay(20);  
  }
  // turn jet right to left
  for (pos = 130; pos >= 50; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
  
  // digitalWrite(pump,LOW); // turn off water pump
  delay(50);
  myservo.write(90); // bring jet to centre
  
  fire=false;
}
 
void loop()
{
//  Serial.print("\n\ninLoop  \n");

  int l = digitalRead(Left);
  int r = digitalRead(Right);
  int m = digitalRead(Forward);

//  Serial.println(l);
//  Serial.println(r);
//  Serial.println(m);

 if(r == 0) // fire
  {
//  Serial.println("FIRE DETECTED!!\n");

    // move vehicle forward 1,0,1,0
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    delay(3000);

    put_off_fire();

  }
  else // no fire. stop vehicle
{
//Serial.println("NO FIRE\n");

    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);

}
delay(500);//change this value to increase the distance
     
}
