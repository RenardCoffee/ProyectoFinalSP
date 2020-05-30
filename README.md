# ProyectoFinalSP(Abrepuertas automático con Arduino)

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
  
## Sensor PIR

El sensor PIR detecta cualquier cambio en el calor, y cada vez que detecta cualquier cambio, su PIN de salida se vuelve ALTO. También se conocen como sensores de movimiento piroeléctricos o IR.

Aquí debemos tener en cuenta que cada objeto emite una cierta cantidad de infrarrojos cuando se calienta. El ser humano también emite infrarrojos debido al calor corporal. Los sensores PIR pueden detectar una pequeña cantidad de variación en el infrarrojo. Cada vez que un objeto pasa a través del rango del sensor, produce infrarrojos debido a la fricción entre el aire y el objeto, y queda atrapado por PIR.

El componente principal del sensor PIR es el sensor piroeléctrico que se muestra en la figura (cristal rectangular detrás de la tapa de plástico). Junto con BISS0001 ("Micro Power PIR Motion Detector IC"), algunas resistencias, condensadores y otros componentes utilizados para construir el sensor PIR. BISS0001 IC toma la entrada del sensor y realiza el procesamiento para hacer que el pin de salida sea ALTO o BAJO en consecuencia.

