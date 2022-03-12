#include "DHT.h";
#define DHTPIN 4
#define DHTTYPE DHT22
  DHT dht(DHTPIN, DHTTYPE);

int buzzer = 13;
int led1 = 12;
int led2 = 11;
int led3 = 10;
double suhu;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  suhu = dht.readTemperature();

  if (suhu > 65){
    digitalWrite(led1, HIGH); //Led merah menyala
    digitalWrite(buzzer, HIGH); //Alarm kebakaran menyala
    delay(1000);
    digitalWrite(buzzer, LOW);
    digitalWrite(led2, LOW); //Led kuning mati
    digitalWrite(led3, LOW); //Led hijau mati
    delay(500);
  }
  if (suhu < 65 && suhu > 35){
    digitalWrite(led2, HIGH); //Led hijau nyala
    digitalWrite(led1, LOW); //Led merah mati
    digitalWrite(led3, LOW); //Led kuning mati
    digitalWrite(buzzer, LOW); //Alarm kebakaran mati
    delay(500);
  }
  if (suhu < 35){
    digitalWrite(led3, HIGH); //led hijau nyala
    digitalWrite(led1, LOW); //led merah mati
    digitalWrite(led2, LOW); //led kuning mati
    digitalWrite(buzzer, LOW); //Alarm kebakaran mati
    delay(500);
  }

  //Serial yang ditampilkan
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" *C\t");
}
