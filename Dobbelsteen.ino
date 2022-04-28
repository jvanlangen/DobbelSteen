// Jeroen van Langen.


/* Pin led layout
   12       6
    |       |
   11 - 9 - 7
    |       |
   10       8

   indexen in de array

    4       0
    |       |
    5 - 3 - 1
    |       |
    6       2

*/
const uint8_t oogLedPins[ 7 ] = { 6, 7, 8, 9, 12, 11, 10 };

const uint8_t btnPin = 5;
const uint8_t pwrPin = 13;

const uint8_t dobbelsteenOpmaak[ 7 ][ 7 ] = {
  { LOW, LOW, LOW, LOW, LOW, LOW, LOW }, // 0
  { LOW, LOW, LOW, HIGH, LOW, LOW, LOW }, // 1
  {HIGH, LOW, LOW, LOW, LOW, LOW, HIGH }, // 2
  { LOW, LOW, HIGH, HIGH, HIGH, LOW, LOW }, // 3
  {HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH }, // 4
  {HIGH, LOW, HIGH, HIGH, HIGH, LOW, HIGH }, // 5
  {HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH } // 6
};


// the setup function runs once when you press reset or power the board
void setup() {

  // zorgen dat random ook echt een random waarde geeft
  randomSeed(analogRead(0));

  // alle digital pin LED_BUILTIN as an output.
  for (int i = 0; i < 7; i++)
    pinMode(oogLedPins[i], OUTPUT);

  // button pin als input initializeren
  pinMode(btnPin, INPUT);
  // pwr pin voor de button
  pinMode(pwrPin, OUTPUT);

  // (+5v) hoog zetten, zodat we de button kunnen checken
  digitalWrite(pwrPin, HIGH);

  // serial monitor checken
  Serial.begin(115200);
}

// de functie die de dobbelsteen leds aanstuurt
void tekenDobbelsteen(int waarde) {
  // met een for-loop checken welke leds aan en uit moeten staan
  for (int i = 0; i < 7; i++)
    digitalWrite(oogLedPins[i], dobbelsteenOpmaak[waarde][i]);
}

// the loop function runs over and over again forever
void loop() {

  // kijken of de button ingedrukt wordt
  if (digitalRead(btnPin) == HIGH) {

    Serial.println("rol");
    // doe 20 keer random en zet de leds aan
    for (int i = 1; i < 20; i++)
    {
      // een random waarde tussen 1 t/m 6
      int waarde = random(1, 7);
      // zet leds aan/uit
      tekenDobbelsteen(waarde);
      // wacht 100 ms.
      delay(100);
    }
  }
}
