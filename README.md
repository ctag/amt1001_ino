# amt1001_ino

AMT1001 sensor library for arduino sketches

## Hardware

Yellow Wire -> Humidity

White Wire -> Temperature

The temperature wire should be situated in a voltage divider before it reaches the analog input pin. Use a 10K resistor to ground.

## Code

<pre>
// Get Temperature
uint16_t step = analogRead(tempPin);
uint16_t temperature = amt1001_gettemperature(step);
Serial.println(temperature);

// Get Humidity
uint16_t step = analogRead(humPin);
double volt = (double)step * (5.0 / 1023.0);
uint16_t humidity = amt1001_gethumidity(volt);
Serial.println(humidity);
</pre>

## References

[Original library](http://davidegironi.blogspot.com/2013/07/amt1001-humidity-and-temperature-sensor.html#.VXOzO5Tve00)


