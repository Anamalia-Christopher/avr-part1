#include <avr/io.h> /*for including the avr package. In C, we use #include to import a library into our program. We are using the avr library to use the features of the atmega32 microcontrolller*/

/*LINE 4,5,6 : for checking whether the frequency of the microcontrolller has been defined */
#ifndef F_CPU /*F_CPU is a constant that is defined in the avr/io.h library that refers to the frequency of the microcontrolller you're using. The frequency basically means the rate at which the microcontrolller is processing information*/
  #define F_CPU 1000000UL /*the frequency of the MCU that we are usings is 1Mhz*/
#endif


#include <util/delay.h> /*for including the delay packag. This package helps us to implement some delays into our program. Delays basically tell the program to pasue whatever its doing. Hence if the MCU is put on delay for some number od seconds, it is going to remain that way until the delay time passes where it would unpause */

/*in C, the structure for functions are
  return_type name_of_function(parameters)
  if one has no parameters, that part is left empty as indicated in the main functions

  In addition, apart from the main function which is required by almost every C file, all other functions that are going to be declared in the file should have prototypes. Example of function prototypes are shown in the lines below. Kindly take note of the syntax
 */
/*LINE 13,14,15: function prototypes */
int buttonState(uint8_t button); /*This is a function prototype for determining the state of the button. i.e whether the button is on or off*/
void highState(uint8_t button); /* this function prototype is for turning the LED on.*/
void lowState(uint8_t button); /*This is for turning the LED off*/

/*BITWISE OPERATIONS
Bitwise operations are operations that are carried out on a bit to give an output based on certain rules or  conventions.
Bitwise operators that are going to be used in this program are:
& = and (gives 1 if both conditions are 1 else gives a 0. For example, 1001 & 1100 = 1000)
~ = not (gives the negation of the current value. Changes 1 ->0 and 0->1. For example; ~1010 = 0101)
| = or (gives a 1 when either of them is 1. For example, 1001 | 1100 = 1101 )
<< = left shift (this is for shifting a bit to a particular location. For example 1<<3 shifts a bit 3 times forword[1000]. By virtue of the fact that atmega32 is 8 bits, anytime we do a left shift bitewise operation, it pads the values infront of it to result in an 8 bit result. For example, 1<<3 = 00001000)

*/
/*#define is used for defining certain constant variables that would later be substituted during compilation. It is good to use this for definig certain stuffs that would not change in the cource of programming*/
#define BUTTON_PIN 1<<3 // this is 4th pin.
#define LED_PIN 1<<5 // this is 5th pin.

/* there are different ports in the microcontrolller but this tutorial is using PORTD*/
/* the main function is the function that is called when the program is run*/
void main() {


  DDRD |=LED_PIN;/*for making pinmode an output for the specified pin on port D*/


  // DDRD &= ~BUTTON_PIN;  /*for making pinmode an input for the specified pin on port D. It was commented out because it is not necessary since by default, it is LOW*/


  for (;;) {/*Synonymous to a while loop*/
    /*in place of for(;;), while(1) could have being used. */
    if (buttonState(BUTTON_PIN)){ /*checks if the button has being pressed. True only if the button has been pressed*/
      highState(LED_PIN);/*turns on the LED*/
  }

    else{
      lowState(LED_PIN);/*turns off the LED */

    }
  }

}

/* this function is for checking the button state any button */
int buttonState(uint8_t button) {
  /*for reading the state of the buttton and returns 1 when pressed, else return 0 */
  /*PIND is a variable that contains the state of a pins belonging to the pin D. Likewise, PINC would also contain the state of pins belonging to pin C. We used PIND because we we are working with port D in this program*/
  if (~PIND & button)
  return 1;

  return 0;
}

void highState(uint8_t button) {
  /*turns on the LED*/
  PORTD|=LED_PIN;
  _delay_ms(20);
}

void lowState(uint8_t button) {
  /*turns off the LED*/
  PORTD &=~LED_PIN;
  _delay_ms(20);

}


/*
Set a bit

BYTE |= (1<<i);

Clear a bit

BYTE &= ~(1<<i);

Toogle a bit
24hthuthuat

BYTE ^= (1<<i);
*/
