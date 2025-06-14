
int redLed = 12;
int greenLed = 11;

int smokeA0 = A5;
int sensorThres = 50;


int r_led = 5;
int g_led = 6;
int b_led = 7;



//ultrasonic

long readUltrasonicDistance(int triggerPin, int echoPin)
{
pinMode(triggerPin, OUTPUT); 
digitalWrite(triggerPin, LOW);
delayMicroseconds(2);

digitalWrite(triggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin, LOW);
pinMode(echoPin, INPUT);

return pulseIn(echoPin, HIGH);
}



void setup() {
  

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
 
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);


  // rgb led
  pinMode (r_led, OUTPUT);
  pinMode (g_led, OUTPUT);
  pinMode (b_led, OUTPUT);

}

void loop() {
  

  int analogSensor = analogRead(smokeA0);

  float distance = 0.01723 * readUltrasonicDistance(2, 3);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value

  
  if (analogSensor > sensorThres && distance > 5.7)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    

    analogWrite(r_led, 0);
    analogWrite(g_led, 0);
    analogWrite(b_led, 255);

delay(500); // Wait for 500 millisecond(s)
} 


if (analogSensor > sensorThres && distance < 5.7)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    

    analogWrite(r_led, 255);
    analogWrite(g_led, 0);
    analogWrite(b_led, 0);

delay(500); 
} 




if (analogSensor < sensorThres && distance < 5.7)
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    

    analogWrite(r_led, 255);
    analogWrite(g_led, 0);
    analogWrite(b_led, 0);

delay(500); 
} 




    
  
  
  if (analogSensor < sensorThres && distance > 5.7)
  
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);


    analogWrite(r_led, 0);
    analogWrite(g_led, 255);
    analogWrite(b_led, 0);

delay(500); 


    
    
  }
  delay(100);



  

}
