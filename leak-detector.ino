/**************************************************************************/
/* JC72 leak detector */
/* stops pumps (pin 5 & 6)  + blinks LED (pin7) when liquid is detected using non contact sensor 
/**************************************************************************/

int Liquid_level=0;

/* declare variable */
int liquidsensor_pin= 3;
int pump1_pin= 5;
int pump2_pin= 6; 
int ledPin= 7; 

int ledState = LOW; 
long previousMillis = 0;       
long interval = 100;     

void setup() {
 Serial.begin(9600);

 pinMode(liquidsensor_pin,INPUT);
 pinMode(pump1_pin, OUTPUT); 
 pinMode(pump2_pin, OUTPUT);
 pinMode(ledPin, OUTPUT);
}

void loop() {
Liquid_level=digitalRead(3);
Serial.println(Liquid_level,DEC);

if (Liquid_level >= 1) {  
  digitalWrite(pump1_pin, HIGH); 
  digitalWrite(pump2_pin, HIGH); 
  Serial.println(Liquid_level,DEC);

  unsigned long currentMillis = millis(); // stocke la valeur courante de la fonction millis()
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
  ledState = LOW;
  digitalWrite(ledPin, ledState);

  Serial.println(Liquid_level,DEC);
  }
delay(100);
}
