int ledPin1 = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:  
 digitalWrite(ledPin1, HIGH);
 delay(1000);
 digitalWrite(ledPin1, LOW);
 delay(1000);
}
