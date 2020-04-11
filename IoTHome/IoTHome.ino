#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int buzzer = 11;      // selecciona el pin para el zumbador
int valorSensor = 0;  // variable para almacenar el valor proveniente del sensor

char ssid[] = "INFINITUM4813_2.4";
char pass[] = "WE1YJH16Be";

WidgetLED led1(V1);



BlynkTimer timer;


void setup() {
 //Seteo de la velocidad del puerto serial
 Serial.begin(9600);
 // declarar buzzer como una SALIDA:
  pinMode(buzzer, OUTPUT);
  
  Blynk.begin(auth, ssid, pass);


  timer.setInterval(1000L, blinkLedWidget);
}
void loop() {


  Blynk.run();
  timer.run();
  alarmaFuego();
    
 }

void alarmaFuego(){

  // leer el valor del sensor:
  valorSensor = analogRead(A0);
   Serial.println(valorSensor);
  // activa el buzzer
  if (valorSensor < 10){
   digitalWrite(buzzer, HIGH);
   delay(100);
  // Desactiva el buzzer
  digitalWrite(buzzer, LOW);
  delay(50);  
    }
  
  
}

void blinkLedWidget()
{
  if (led1.getValue()) {
    led1.off();
    Serial.println("LED on V1: off");
  } else {
    led1.on();
    Serial.println("LED on V1: on");
  }
}
