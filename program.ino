#define MEMORY_PROGRAMMING_MODE A1
#define WRITE_TO_MEMORY A2
#define RESET_COMPUTER A3
#define MEMORY_ADDRESS_PIN_0 10
#define MEMORY_ADDRESS_PIN_1 11
#define MEMORY_ADDRESS_PIN_2 12
#define MEMORY_ADDRESS_PIN_3 13
#define MEMORY_PIN_0 2
#define MEMORY_PIN_1 3
#define MEMORY_PIN_2 4
#define MEMORY_PIN_3 5
#define MEMORY_PIN_4 6
#define MEMORY_PIN_5 7
#define MEMORY_PIN_6 8
#define MEMORY_PIN_7 9

const int MEMORY_ADDRESSES = 16;
const int MEMORY_ADDRESSES_PINS = 4;
const int MEMORY_PINS = 8;

/*
 * Fibonacci program.
 * 
 * References:
 *   - https://youtu.be/a73ZXDJtU48?t=263
 */
int FIBONACCI_PROGRAM[MEMORY_ADDRESSES][MEMORY_ADDRESSES_PINS + MEMORY_PINS] = {
  { 0, 0, 0, 0,    0, 1, 0, 1,    0, 0, 0, 1 },
  { 0, 0, 0, 1,    0, 1, 0, 0,    1, 1, 1, 0 },
  { 0, 0, 1, 0,    0, 1, 0, 1,    0, 0, 0, 0 },
  { 0, 0, 1, 1,    1, 1, 1, 0,    0, 0, 0, 0 },
  { 0, 1, 0, 0,    0, 0, 1, 0,    1, 1, 1, 0 },
  { 0, 1, 0, 1,    0, 1, 0, 0,    1, 1, 1, 1 },
  { 0, 1, 1, 0,    0, 0, 0, 1,    1, 1, 1, 0 },
  { 0, 1, 1, 1,    0, 1, 0, 0,    1, 1, 0, 1 },
  { 1, 0, 0, 0,    0, 0, 0, 1,    1, 1, 1, 1 },
  { 1, 0, 0, 1,    0, 1, 0, 0,    1, 1, 1, 0 },
  { 1, 0, 1, 0,    0, 0, 0, 1,    1, 1, 0, 1 },
  { 1, 0, 1, 1,    0, 1, 1, 1,    0, 0, 0, 0 },
  { 1, 1, 0, 0,    0, 1, 1, 0,    0, 0, 1, 1 },
  { 1, 1, 0, 1,    0, 0, 0, 0,    0, 0, 0, 0 },
  { 1, 1, 1, 0,    0, 0, 0, 0,    0, 0, 0, 0 },
  { 1, 1, 1, 1,    0, 0, 0, 0,    0, 0, 0, 0 },
};

/*
 * Write a program to the memory.
 */
void writeProgram(int program[MEMORY_ADDRESSES][MEMORY_ADDRESSES_PINS + MEMORY_PINS]) {
  for (int command = 0; command < MEMORY_ADDRESSES; command += 1) {
    digitalWrite(MEMORY_ADDRESS_PIN_3, program[command][0]);
    digitalWrite(MEMORY_ADDRESS_PIN_2, program[command][1]);
    digitalWrite(MEMORY_ADDRESS_PIN_1, program[command][2]);
    digitalWrite(MEMORY_ADDRESS_PIN_0, program[command][3]);

    digitalWrite(MEMORY_PIN_7, program[command][4]);
    digitalWrite(MEMORY_PIN_6, program[command][5]);
    digitalWrite(MEMORY_PIN_5, program[command][6]);
    digitalWrite(MEMORY_PIN_4, program[command][7]);
    digitalWrite(MEMORY_PIN_3, program[command][8]);
    digitalWrite(MEMORY_PIN_2, program[command][9]);
    digitalWrite(MEMORY_PIN_1, program[command][10]);
    digitalWrite(MEMORY_PIN_0, program[command][11]);

    digitalWrite(WRITE_TO_MEMORY, LOW);
    delayMicroseconds(1);
    digitalWrite(WRITE_TO_MEMORY, HIGH);
    delay(10);
  }
}


/*
 * Setup the Arduino program.
 * 
 * Both write to memory and memory programming mode pins need to write
 * low to SN74LS157N's first pin to select DIP switches what is neeeded 
 * for Arduino to put a program into the memory. When it's high, then
 * the computer is working in the run mode.
 * 
 * References:
 *   - https://youtu.be/KNve2LCcSRc?t=900
 */
void setup() {
  pinMode(MEMORY_PROGRAMMING_MODE, OUTPUT);
  pinMode(WRITE_TO_MEMORY, OUTPUT);
  pinMode(RESET_COMPUTER, OUTPUT);
  pinMode(MEMORY_PIN_0, OUTPUT);
  pinMode(MEMORY_PIN_1, OUTPUT);
  pinMode(MEMORY_PIN_2, OUTPUT);
  pinMode(MEMORY_PIN_3, OUTPUT);
  pinMode(MEMORY_PIN_4, OUTPUT);
  pinMode(MEMORY_PIN_5, OUTPUT);
  pinMode(MEMORY_PIN_6, OUTPUT);
  pinMode(MEMORY_PIN_7, OUTPUT);
  pinMode(MEMORY_ADDRESS_PIN_0, OUTPUT);
  pinMode(MEMORY_ADDRESS_PIN_1, OUTPUT);
  pinMode(MEMORY_ADDRESS_PIN_2, OUTPUT);
  pinMode(MEMORY_ADDRESS_PIN_3, OUTPUT);

  digitalWrite(WRITE_TO_MEMORY, HIGH);
  digitalWrite(MEMORY_PROGRAMMING_MODE, LOW);

  writeProgram(FIBONACCI_PROGRAM);
  
  digitalWrite(MEMORY_PROGRAMMING_MODE, HIGH);
  digitalWrite(RESET_COMPUTER, HIGH);
  digitalWrite(RESET_COMPUTER, LOW);
}

void loop() {}
