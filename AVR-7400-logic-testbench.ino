/* digital logic test program
 *  Erik  Olsen 11-01-24
 *  
 *  Note that this program is only portable to Arduinos that use the ATMEGA 328
 */

void setup() {
  // Enable serial port at 9600 baud
  Serial.begin(9600);

  // Wait for serial port to be freed by bootloader
  while(!Serial){
    ;
  }

  // Note, only the first 5 pins of each array are actually connected to anything, and we're only gonna look at the first four
  
  //Set all pins on port b (9-13) to outputs
  DDRB = 0b11111111;

  //Set all pins on port c (a0-a5) to inputs
  DDRC = 0b00000000;

  //Enable pullup resistors on pins on port c (a0-a5)
  //Note, this makes the default state of the pins on port c high, unless grounded,
  //I'm not sure how to get around this unless I explicitly add external pulldown resistors.
  PORTC = 0b11111111;
  
  //Wait until we are ready to run the code by sending the character s for start
  while(Serial.read() != 's'){
  ;
  }
}

void loop() {

  // Some formatting
  Serial.println("Input | Output");

  //If we send s for start
  if(Serial.read() == 's'){
    //Loop from 0 to 15
    for(uint8_t i = 0; i < 16; i++){
      
      //Increment port b
      PORTB = i;

      //Convert everything into binary strings, concatonate them, and print them over the serial port
      //Note that PINC is the bit array for the states of port c
      Serial.println(String(i, BIN) + " | " + String(PINC, BIN));

      //Wait a little bit 
      delay(500);
    }
  }
}
