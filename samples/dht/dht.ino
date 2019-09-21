/*
 * Script ejemplo para usar el modulo dht11
 * 
 * Primero descargar e instalar la libreria dht
 * 
 * Conectar:
 * El pin Vcc al pin VV de la placa esp8266
 * El pin GND a cualquien pin con la letra G
 * El pin DATA al pin D2 de la placa esp8266
 *
 * link repo: https://github.com/mokuzaru/IOT_WS
 * 
 */
#include <DHT.h>

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin (9600);
  Serial.println("DHT11 test!");

  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(isnan(h) || isnan (t)){
    Serial.println(F("Fallo!! Shiit!!"));
    return;
  }
  Serial.print("temp: ");
  Serial.println(t);
  Serial.print("hum: ");
  Serial.println(h);
}
