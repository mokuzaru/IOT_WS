/*
 * Script ejemplo para usar el modulo hc-04
 *  
 * Conectar:
 * El pin Vcc al pin VV de la placa esp8266
 * El pin GND a cualquien pin con la letra G
 * El pin trig al pin D3
 * El pin echo al pin D4
 *
 * link repo: https://github.com/mokuzaru/IOT_WS
 * 
 */
long distancia;
long tiempo;
void setup(){
  Serial.begin(115200);
  pinMode(3, OUTPUT); /*activación del pin 3 como salida: para el pulso ultrasónico*/
  pinMode(4, INPUT); /*activación del pin 4 como entrada: tiempo del rebote del ultrasonido*/
}

void loop(){
  digitalWrite(3,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(3, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(4, HIGH); /* Función para medir la longitud del pulso entrante. 
  Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, 
  HIGH, hasta que deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  delay(1000);
}
