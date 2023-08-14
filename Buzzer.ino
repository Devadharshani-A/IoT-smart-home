int trigPin = 7;  
int echoPin = 6;
int buzzer = 8;
float new_delay; 


void setup() 
{
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
  
}


void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  new_delay= (distance *3) +30;
  Serial.print(distance);
  Serial.println("  cm");
  if (distance < 25)
  {
   tone(8, 5000, 10);
   delay(new_delay);
   digitalWrite(buzzer,LOW);
 
  }
  else
  {
    digitalWrite(buzzer,LOW);

  }
  
 delay(200);
}
