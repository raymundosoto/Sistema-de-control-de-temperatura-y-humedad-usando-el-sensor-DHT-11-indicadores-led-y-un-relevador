# Sistema-de-control-de-temperatura-y-humedad-usando-el-sensor-DHT-11-indicadores-led-y-un-relevador
En este repositorio se encuentran los archivos y documentos que permiten construir un sistema de control de tempertura y humedad usando un sensor DHT11 o DHT22 con indicadores led de valores u un relevador que sirve como actuador

# Objetivos
Construir el prototipo sistema de control de temperatura y humedad ambiental usando el sensor DHT11, el microcontrolador ESP32 y un actuador representado por un relay (relé o relevador). Relacionar los conocimientos sobre función de transferencia y aplicarlos en el control de sistemas.

# Marco teórico

Un sistema de control es un conjunto de elementos diseñados para gestionar y dirigir el comportamiento de un proceso o sistema. Su objetivo es mantener el funcionamiento del proceso dentro de los límites deseados y ajustar su comportamiento para alcanzar ciertos objetivos o metas.
Los sistemas de control se componen generalmente de tres partes principales:
- Sensor o medidor: Es el dispositivo encargado de medir y recoger información sobre el proceso o sistema que se quiere controlar. Este dispositivo puede medir una variedad de variables, como temperatura, presión, velocidad, nivel de fluidos, entre otras.
- Controlador: Es el componente que procesa la información recogida por el sensor y decide qué acciones tomar en función de la información recibida. El controlador puede ser un dispositivo electrónico o un programa de software.
- Actuador: Es el componente que se encarga de ejecutar las acciones ordenadas por el controlador. Este dispositivo puede ser una válvula, un motor, una bomba, un relay, entre otros.

Estas tres partes están conectadas entre sí y trabajan en conjunto para asegurar que el proceso o sistema se mantenga dentro de los límites deseados.
El diagrama de bloques de un sistema de control a lazo cerrado contiene los componentes mostrados en la figura 1.
 
![diagrama de control](https://user-images.githubusercontent.com/72757419/226203537-e3684348-74f0-43a7-ac80-956b4a884aa9.jpg)

Figura 1. Elementos de un sistema de control a lazo cerrado

Para esta práctica, El controlador ESP32 recopila la información del sensor DHT11, y el relé se encarga de activar o desactivar un dispositivo de enfriamiento o calefacción según los parámetros establecidos en el controlador. En el diagrama, se muestra cómo los diferentes componentes están conectados entre sí. El sensor DHT11 está conectado al controlador ESP32 a través de un pin de entrada digital, y el relé se conecta a un pin de salida digital en el controlador. El controlador ESP32 recopila la información de temperatura y humedad del sensor DHT11, y utiliza un algoritmo de control para determinar si el dispositivo de enfriamiento o calefacción debe activarse o desactivarse. Si la temperatura o la humedad están por encima del valor deseado, el relé se activa y enciende el dispositivo de enfriamiento o calefacción. Si la temperatura o la humedad están dentro de los valores deseados, el relé se desactiva y el dispositivo de enfriamiento o calefacción se apaga, en nuestro caso no conectamos el relevador a ningún dispositivo, pero si así que quiere puede ir conectado a un ventilador (opcional).

# Material requerido

-	1 modulo ESP32 de 30 pines
-	1 protoboard
-	1 Sensor DHT11 o DHT22
-	Módulo de 1 Relevador 10 A 120 VCA / 5 VCD con led indicador de funcionamiento (rojo verde)
-	2 resistencia de 220 ohms
-	Cables jumper macho-hembra o macho-macho 
-	1 cable usb a mini usb para conectar el ESP32 a la computadora.

# Software requerido

- IDE de Arduino 1.8.19 https://www.arduino.cc/en/software 
- Gestor de tarjetas para ESP32 (preferencias >> gestor de URLs adicionales >> https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)
- Drivers para comunicación serial entre la computadora y el ESP32 (Revisar la documentación https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html, https://esp32.com/viewtopic.php?t=5329) 
- Instalar la biblioteca DHT sensor library usando el gestor de librerías de arduino
- Código para la programación del ESP32 con el algoritmo de control     [Código  de control ](https://github.com/raymundosoto/Sistema-de-control-de-temperatura-y-humedad-usando-el-sensor-DHT-11-indicadores-led-y-un-relevador/blob/main/Codigo_ESP32_Relay_DHT11_leds/Codigo_ESP32_Relay_DHT11_leds.ino)

# Desarrollo.
Realizar las siguientes actividades:

1.	Armar el siguiente circuito con el material enlistado
  
![Esquema_conexión_ESP_leds_relay](https://user-images.githubusercontent.com/72757419/226203462-9982a4d3-95fa-4b5c-84de-d348e5e37758.png)

Figura 2. Diagrama del circuito

2.	Las resistencias de 220 irán conectadas entre los pines D12 (led verde) y D14 (led rojo) del ESP32; (PRECAUCIÓN, realizar las conexiones sin energizar el circuito). En el diagrama se usa el sensor DHT12, pero se puede usar el DHT11, sólo asegúrate de elegir el sensor adecuado en el código de arduino.
3.	Conectar el cable USB a la computadora y al ESP32
4.	Abrir el IDE de Arduino
5.	Seleccionar la placa DOIT ESP32 DEVKIT V1 en el IDE de Arduino
6.	Revisar que existe comunicación serial entre Arduino y el ESP32 abriendo el monitor serial y oprimiendo el botón EN del ESP32, se verá la información relacionada con las características del controlador.
7.	Cargar el programa para el control de temperatura y humedad usando el botón cargar del IDE de Arduino (en algunas ocasiones es necesario cargar el programa antes de realizar las conexiones, esto se realizará si después de haber configurado correctamente todo el IDE de arduino no detecta la placa).
8.	El programa utilizado usara una velocidad serial de 9600 baudios, elegir está velocidad para visualizar las mediciones de temperatura y humedad
9.	Para lograr que el sensor de temperatura y humedad mida cambios en los valores de temperatura y humedad acerque un encendedor sin tocar el sensor
Comentarios sobre el código de arduino 
•	El código se encuentra en el material semanal de la materia 
•	En la línea #define DHTTYPE DHT11 indicar si el sensor es el DHT11 o DHT22
•	Modificar en la línea el valor del ciclo if el valor de t donde se desee que los leds indicadores se enciendan, cuando el valor este por encima de este umbral se encenderá el relay y el led rojo, cuando este por debajo se encenderá el led rojo.
```
   if (t <= 28) {
       digitalWrite(pin_led_v, HIGH);
       digitalWrite(pin_led_r, LOW);
       digitalWrite(pin_relay, LOW);
     } else {
       digitalWrite(pin_led_r, HIGH);
       digitalWrite(pin_led_v, LOW);
       digitalWrite(pin_relay, HIGH);
     }
```

# Resultados

[En esta sección deberán colocar imágenes que permitan visualizar el armado del circuito, funcionamiento del circuito, programación del ESP32 y capturas de pantalla mostrando las mediciones del sensor en el monitor serial de Arduino, explicar cada una de las imágenes]

# Cuestionario

Realizar este cuestionario con ayuda de la bibliografía
1.	¿Qué es un diagrama de bloques y cuál es su importancia en ingeniería?
2.	¿Qué es la función de transferencia de un diagrama de bloques?
3.	¿Cuál sería la función de transferencia para el circuito de control de la práctica?
4.	¿Qué aplicaciones le ves al uso de estos circuitos de control en la ingeniería que estudias?
5.	Explica qué tipos de señales y sistemas tenemos en este circuito de control, explica a profundidad 
6.	De acuerdo a los bloques mostrado en la figura 1, indica que elemento del circuito realiza la función indicada en cada bloque (Set point o referencia, regulador, actuador, salidas o variables a controlar, sensor, acción de control y perturbaciones).

# Conclusiones

[ESTE SECCIÓN DEBERÁ SER EDITADA CON INFORMACIÓN QUE EL ALUMNO CREA CONVENIENTE SIGUIENDO LA GUÍA DE ELABORACIÓN DE CONCLUSIONES, TRATE DE PLASMAR TODAS LAS OBSERVACIONES Y CONOCIMIENTOS QUE OBTENGA, RECUERDA QUE LAS CONCLUSIONES DEBEN SER ACORDES A LOS OBJETIVOS] 

# Código fuente
[INSERTA TODO EL CODIGO SIN ERRORES Y DEBIDAMENTE COMENTADO]

# Bibliografía
[COLOCAR LAS REFERENCIAS BIBLIOGRÁFICAS EN FORMATO APA]
