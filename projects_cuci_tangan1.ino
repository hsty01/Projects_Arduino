/*Project pencuci tangan otomatis dengan pompa elktrik*/

#include <Servo.h>
Servo myservo;
int pos = 0;

int trig = 11;
int echo = 12;
long durasi, jarak;
int pompa = 5;

void setup() {
  myservo.attach(9);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pompa, OUTPUT);
  myservo.write(25);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  
  durasi = pulseIn(echo, HIGH);
  jarak = (durasi * 0.034) / 2;
  Serial.print("jarak pertama = ");
  Serial.println(jarak);
  
  if (jarak <= 15) {
    digitalWrite (pompa, LOW); //pompa mati
    delay (1500);
    digitalWrite (pompa, HIGH); //pompa nyala
    delay (5000);
    digitalWrite (pompa, LOW); //pompa mati
    delay (2000);
    
    for(pos = 25; pos < 110; pos += 1) { //derajat putar servo
      myservo.write(pos);
      delay(15);
    }
    delay(500);
    for(pos = 110; pos>=25; pos-=1) {
      myservo.write(pos);
      delay(15);
    }
    delay (5000);
  
    digitalWrite (pompa, HIGH); //menyala membilas tangan
    delay (5000);
    digitalWrite (pompa, LOW); //menyala membilas tangan
    delay (3000);
    }
}    