/**************************************************************************/
/* Leakdetector.ino */
/* stops pumps (pin 5 & 6) + flashes LED (pin7) when liquid is detected using non contact liquid sensor 
/**************************************************************************/

/* declare variable */
int liquidsensor_pin= 3;
int pump1_pin= 5;
int pump2_pin= 6; 
int ledPin= 7; 

/* init baseline values*/
int ledState = LOW; 
int Liquid_level=0;

long previousMillis = 0;       
long interval = 100;     

void setup() {
 pinMode(liquidsensor_pin,INPUT);
 pinMode(pump1_pin, OUTPUT); 
 pinMode(pump2_pin, OUTPUT);
 pinMode(ledPin, OUTPUT);
}

void loop() {

if (Liquid_level >= 1) {  
  digitalWrite(pump1_pin, HIGH); 
  digitalWrite(pump2_pin, HIGH); 
  Serial.println(Liquid_level,DEC);

  unsigned long currentMillis = millis(); 
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;  
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(ledPin, ledState);
  } 
} else {
  digitalWrite(pump1_pin, LOW); 
  digitalWrite(pump2_pin, LOW);
  digitalWrite(ledPin, ledState);
  ledState = LOW;
  }
  
delay(100);
}
