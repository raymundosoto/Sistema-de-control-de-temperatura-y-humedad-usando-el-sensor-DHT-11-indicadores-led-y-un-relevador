// Incluimos librería
#include <DHT.h>
 
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT22
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

int pin_led_r = 14;  // Pin del led rojo
int pin_led_v = 12;  // Pin del led verde
int pin_relay = 26; // pin del relay

 
void setup() {
  // Inicializamos comunicación serie
  Serial.begin(9600);
 
  // Comenzamos el sensor DHT
  dht.begin();

  pinMode(pin_led_r, OUTPUT); // Modo de inicio del led
  pinMode(pin_led_v, OUTPUT); // Modo de inicio del led
  pinMode(pin_relay, OUTPUT); // Modo de inicio del relay
}
 
void loop() {
    // Esperamos 5 segundos entre medidas
  delay(2000);
 
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahreheit
  float f = dht.readTemperature(true);
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
 
 
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\n");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C, ");
  Serial.print(f);
  Serial.print(" *F\n");
  

 if (t <= 28) {
   digitalWrite(pin_led_v, HIGH);
   digitalWrite(pin_led_r, LOW);
   digitalWrite(pin_relay, LOW);
 } else {
   digitalWrite(pin_led_r, HIGH);
   digitalWrite(pin_led_v, LOW);
   digitalWrite(pin_relay, HIGH);
 }
}
 
