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

  randomSeed(analogRead(0));

  // initialize digital pin LED_BUILTIN as an output.
  for (int i = 0; i < 7; i++)
    pinMode(oogLedPins[i], OUTPUT);

  pinMode(btnPin, INPUT);
  pinMode(pwrPin, OUTPUT);

  digitalWrite(pwrPin, HIGH);

  Serial.begin(115200);
}

void tekenDobbelsteen(int waarde) {
  for (int i = 0; i < 7; i++)
    digitalWrite(oogLedPins[i], dobbelsteenOpmaak[waarde][i]);
}

bool btnPressed = false;
bool rolDeDobbelsteen = false;

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(btnPin) == HIGH) {
    btnPressed = true;
  }
  else
  {
    if (btnPressed)
    {
      rolDeDobbelsteen = true;
      btnPressed = false;
    }
  }

  if (rolDeDobbelsteen)
  {
    rolDeDobbelsteen = false;

    Serial.println("rol");
    int waarde;
    
    for(int i=1;i<20;i++)
    {
      waarde = random(1, 7);
      tekenDobbelsteen(waarde);
      delay(100);
    }
  }
}
