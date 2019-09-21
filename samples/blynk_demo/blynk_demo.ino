/*
 * Ejemplo de como crear funciones para visualizar 
 * data en la app creada en blynk.
 * 
 * 
 * link: https://github.com/mokuzaru/IOT_WS
 */

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Ingresa el auth que llego a tu correo";

char ssid[] = "Nombre de la red";
char pass[] = "Pass de la red";

//Creamos widget para visualizarlo en la app

WidgetLED led1(V1);

//llamamos al evento timer

BlynkTimer timer;

//enviar data al pin virtual (app) 
BLYNK_WRITE(V2){
 int pinValue = param.asInt();
 Serial.print("V2 Slider value is: ");
 Serial.println(pinValue); 
}

BLYNK_READ(V9){
  Blynk.virtualWrite(V9, millis() / 1000);
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

//Enviamos el valor del componente al pin analogico apra ser visualizado en la app
void EventoTimer(){
  int b = analogRead(A0);
  Blynk.virtualWrite(V5,b);
}

void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, blinkLedWidget);
  timer.setInterval(1000L, EventoTimer);
}

void loop() {
  Blynk.run();
  timer.run();
}
