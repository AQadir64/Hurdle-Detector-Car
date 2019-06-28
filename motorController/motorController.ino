int motor1_left=4;
int motor_1_left=5;
int motor2_right=6;
int motor_2_right=7;
int trigpin=8;
int echopin=9;
void setup() 
{  
  pinMode(motor1_left,OUTPUT);
  pinMode(motor_1_left,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(motor2_right,OUTPUT); 
  pinMode(motor_2_right,OUTPUT);
  Serial.begin(9600);
}
long duration,distance;
void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration*0.0343) /2;
  Serial.println(distance);
  if (distance<15)
  { 
      
      stop1();
      delay(2000);    
      right();
      delay(500);
}
 else if (distance>15)
 {
  forward();

  }
}
void forward()
{ analogWrite(10,100);
analogWrite(3,100);
 digitalWrite(motor1_left,HIGH);
 digitalWrite(motor2_right,HIGH);
 digitalWrite(motor_2_right,LOW);
 digitalWrite(motor_1_left,LOW);  
}
void stop1()
{ analogWrite(2,120);
analogWrite(3,150);
 digitalWrite(motor1_left,LOW);
 digitalWrite(motor2_right,LOW);
 digitalWrite(motor_2_right,LOW);
 digitalWrite(motor_1_left,LOW);  
}
void right()
{ analogWrite(10,100);
analogWrite(3,100);
 digitalWrite(motor1_left,LOW);
 digitalWrite(motor2_right,HIGH);
 digitalWrite(motor_2_right,LOW);
 digitalWrite(motor_1_left,HIGH);  
}
