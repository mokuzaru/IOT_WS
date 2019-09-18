# IOT

Esta es la guia sobre com iniciar en el uso de la tarjeta de desarrollo esp8266. En este caso usaremos la version 12 llamada NodeMCU.

### Requerimientos
----
Para este proyecto usaremos los siguientes software/hardware

#### Software
- Arduino IDE

#### Hardware
- ESP8266 (E-12 NodeMCU)
- USB micro B
- PC

#### Acounts

##### Blynk

[blynk Android](https://play.google.com/store/apps/details?id=cc.blynk&hl=en_US)

[blynk IOS](https://apps.apple.com/us/app/blynk-iot-for-arduino-esp32/id808760481)

### Configurar entorno Arduino IDE para usar NodeMCU
Ir a:

Archivo -> Preferencias -> Gestor de URL:

Copiar este link:

http://arduino.esp8266.com/package_esp8266com_index.json

Click en : Ok

## Conexión con la nube

Para ahorrar tiempo usaremos una libreria para conectar la placa nodeMCU a una base de datos y que luego se pueda mostrar en una app. La libreria se llaman [blynk](https://blynk.io/).

![Blynk logo](/img/node+blynk.jpg)

## Tecnología en la nube
Para el manejo de los datos enviados a la nube, blynk tambien tiene la solución para no liar con servers, endpoints, base de datos, etc.
Para esto descargamos la app blynk (playstore, appstore), luego de registrarse, ingresamos las credenciales e iniciamos con la configuración de los botones/displays en nuestra app.

![Blynk conec](/img/node+blynk2.jpg)

## Hardware

De esta forma habiendo configurado la conexión entre la app y nuestro nodeMCU, podemos proceder a leer datos de sensores y activar actuadores.

![Blynk final](/img/node+blynk+sensors.jpg)
