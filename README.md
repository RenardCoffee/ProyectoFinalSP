# ProyectoFinalSP(Abrepuertas automático con Arduino).

Debe haber visto abridores automáticos de puertas en centros comerciales y otros edificios comerciales. Abren la puerta cuando alguien se acerca a la entrada y la cierran después de algún tiempo. Hay varias tecnologías disponibles para hacer este tipo de sistemas como sensores PIR, sensores de radar, sensores láser, sensores infrarrojos, etc. En este proyecto basado en Arduino, hemos tratado de replicar el mismo sistema utilizando un sensor PIR.

Utiliza un sensor de detección de movimiento (sensor PIR) para abrir o cerrar la puerta que detecta la energía infrarroja omitida del cuerpo humano. Cuando alguien se acerca a la puerta, la energía infrarroja detectada por el sensor cambia y activa el sensor para abrir la puerta cada vez que alguien se acerca a la puerta. La señal se envía además a Arduino Uno que controla la puerta.

## Componentes del circuito:
* Arduino UNO
* 16x2 LCD
* Sensor PIR 
* Cables
* Bread board
* 1 k resistor
* Power supply
* Motor dc
  
## Sensor PIR.

El sensor PIR detecta cualquier cambio en el calor, y cada vez que detecta cualquier cambio, su PIN de salida se vuelve ALTO. También se conocen como sensores de movimiento piroeléctricos o IR.

Aquí debemos tener en cuenta que cada objeto emite una cierta cantidad de infrarrojos cuando se calienta. El ser humano también emite infrarrojos debido al calor corporal. Los sensores PIR pueden detectar una pequeña cantidad de variación en el infrarrojo. Cada vez que un objeto pasa a través del rango del sensor, produce infrarrojos debido a la fricción entre el aire y el objeto, y queda atrapado por PIR.

El componente principal del sensor PIR es el sensor piroeléctrico que se muestra en la figura (cristal rectangular detrás de la tapa de plástico). Junto con BISS0001 ("Micro Power PIR Motion Detector IC"), algunas resistencias, condensadores y otros componentes utilizados para construir el sensor PIR. BISS0001 IC toma la entrada del sensor y realiza el procesamiento para hacer que el pin de salida sea ALTO o BAJO en consecuencia.

![Sensor PIR](/Imagenes/proximity_pirsensor.jpg)

Los PIR están hechos básicamente de un sensor piroeléctrico (que puede ver a continuación como la lata redonda de metal con un cristal rectangular en el centro), que puede detectar niveles de radiación infrarroja. Todo emite algo de radiación de bajo nivel, y cuanto más caliente es algo, más radiación se emite. El sensor en un detector de movimiento está dividido en dos mitades. La razón de esto es que estamos buscando detectar movimiento (cambio), no niveles promedio de IR. Las dos mitades están conectadas para que se cancelen entre sí. Si una mitad ve más o menos radiación IR que la otra, la salida oscilará alto o bajo.

![Sensor PIR](/Imagenes/proximity_pirlens.jpg)

El sensor piroeléctrico se divide en dos mitades, cuando no hay movimiento, ambas mitades permanecen en el mismo estado, lo que significa que ambos detectan el mismo nivel de infrarrojos. Tan pronto como alguien ingresa en la primera mitad, el nivel infrarrojo de una mitad se vuelve mayor que el otro, y esto hace que los PIR reaccionen y hace que el pin de salida sea alto.

El sensor piroeléctrico está cubierto por una tapa de plástico, que tiene una gran variedad de lentes Fresnel en su interior. Estas lentes están curvadas de tal manera que el sensor puede cubrir un amplio rango.

## Diagrama de circuito y explicación.

![CircuitoFinal](/Imagenes/circuito.png)

## Prueba del Circuito.

![PruebaFinal](/Imagenes/pruebaCircuito.gif)

### Explicación de programación.
El concepto utilizado aquí para programar es muy simple. En el programa solo hemos usado entrada digital salida.

DigitalRead se utiliza para leer la salida del sensor PIR.
```javascript
void loop() 
{
  if(digitalRead(PIR_sensor))
  {
    lcd.setCursor(0,0);
    lcd.print("Movement Detected");
    lcd.setCursor(0, 1);
    lcd.print("    Gate Opened    ");
    digitalWrite(m11, HIGH);         // La puerta se abre
    digitalWrite(m12, LOW);
    delay(1000);
     ...
)
```
Después de eso, si el sensor PIR detecta algún movimiento, el programa envía un comando para abrir la puerta, detener la puerta, cerrar la puerta y detener la puerta.

```javascript
void loop() 
{
  if(digitalRead(PIR_sensor))
  {
    lcd.setCursor(0,0);
    lcd.print("Movement Detected");
    lcd.setCursor(0, 1);
    lcd.print("    Gate Opened    ");
    digitalWrite(m11, HIGH);         // La puerta se abre
    digitalWrite(m12, LOW);
    delay(1000);
    digitalWrite(m11, LOW);          // La puerta se detetiene por un rato 
    digitalWrite(m12, LOW);
    delay(1000);
    lcd.clear();
    lcd.print("   Gate Closed    ");
    digitalWrite(m11, LOW);           // La pueta se va cerrando
    digitalWrite(m12, HIGH);
    delay(1000);
    digitalWrite(m11, LOW);            // LA puerta se encunetra cerrada
    digitalWrite(m12, LOW);
    delay(1000);
  }
```
Vea a continuación el código completo para el abridor automático de puertas basado en Arduino.

## Codigo.

```javascript
#include <LiquidCrystal.h>
/*
  The circuit:
 * LCD RS pin to digital pin 13
 * LCD Enable pin to digital pin 12
 * LCD D4 pin to digital pin 11
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 9
 * LCD D7 pin to digital pin 8
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define PIR_sensor 14
#define m11 0
#define m12 1

void setup() 
{
  lcd.begin(16, 2);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(PIR_sensor, INPUT);
  lcd.print("    Automatic    ");
  lcd.setCursor(0,1); 
  lcd.print("   Door Opener   ");
  delay(3000);
  lcd.clear();
  delay(2000);
}

void loop() 
{
  if(digitalRead(PIR_sensor))
  {
    lcd.setCursor(0,0);
    lcd.print("Movement Detected");
    lcd.setCursor(0, 1);
    lcd.print("    Gate Opened    ");
    digitalWrite(m11, HIGH);         // La puerta se abre
    digitalWrite(m12, LOW);
    delay(1000);
    digitalWrite(m11, LOW);          // La puerta se detetiene por un rato 
    digitalWrite(m12, LOW);
    delay(1000);
    lcd.clear();
    lcd.print("   Gate Closed    ");
    digitalWrite(m11, LOW);           // La pueta se va cerrando
    digitalWrite(m12, HIGH);
    delay(1000);
    digitalWrite(m11, LOW);            // LA puerta se encunetra cerrada
    digitalWrite(m12, LOW);
    delay(1000);
  }
  
  else 
  {
    lcd.setCursor(0,0);
    lcd.print("   No Movement   ");
    lcd.setCursor(0,1);
    lcd.print("   Gate Closed   ");
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
  }
}
```
GitPage: https://sheeenpai.github.io/ProyectoFinalSP/
