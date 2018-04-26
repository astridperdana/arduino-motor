#include <NewPing.h>

// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#define TRIGGER_PIN_1  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_1     3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN_2  6  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_2     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.


void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

int ultrablue(int a, int b, int c){
  NewPing sonar(a, b, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping ");
  Serial.print(c);
  Serial.print(" :");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}



void loop() {
  ultrablue(TRIGGER_PIN_1, ECHO_PIN_1, 1);
  delay(50);
  ultrablue(TRIGGER_PIN_2, ECHO_PIN_2, 2);
}
