int moistPin1 = 0;
int moistPin2 = 1;
int moistVal1 = 0;
int moistVal2 = 0;
int motor = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(motor,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(motor,HIGH); 
}
void loop()
{
 digitalWrite(6,HIGH);
  moistVal1 = 0;
  for (int a =1;a<6;a++)
  {moistVal1 += analogRead(A0);
  }
  moistVal1 = moistVal1/5;
  digitalWrite(6,LOW);
  //moistVal2 = analogRead(moistPin2);
  //int moistVal = (moistVal1 +moistVal2)/2;
  Serial.print(moistVal1);
  Serial.println(" - analog value");
 // Serial.println(moistVal2);
  //Serial.print("average analog reading is ");
  //Serial.println(moistVal);
  
    //int percent1 = 2.718282 * 2.718282 * (0.008985 * moistVal1 + 0.207762);
    //int percent2 = 2.718282 * 2.718282 * (0.008985 * moistVal2 + 0.207762);
 //int percent = (percent1+percent2)/2;
 // Serial.println(percent);

 
  if(moistVal1<450)
  {
   
   Serial.println("Starting the motor");
   digitalWrite(motor,LOW);
   delay(2000);// if the sensor value is below 50%
   Serial.println("stopping the motor");
   digitalWrite(motor,HIGH);
  }
  else
  {
   Serial.println("water level is OK");
  }

  delay(1000*10); // for stability 
}
