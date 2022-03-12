const int pinButton=4;
const int pinLED=13;
int kondisiButton=LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinButton, INPUT);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  kondisiButton=digitalRead(pinButton);

  if(kondisiButton==HIGH)
  {
    digitalWrite(pinLED, HIGH);
  }
  else
  {
    digitalWrite(pinLED, LOW);
  }
}
