#include <util/delay.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#define tst_bit(Y, bit_x) (Y&(1<<bit_x))

#define DISPLAY PORTB
#define BOTAO PH5

const unsigned char Tabela[] PROGMEM = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0E};

int main(void){
  unsigned char valor = 0;
  DDRH = 0b11011111;
  PORTH = 0b00100001;
  DDRB = 0xFF;
  PORTB = 0xFF;

  while(1){
    if(!tst_bit(PINH, BOTAO)){
      if(valor == 0x0F){ valor = 0; }
      else{ valor++; }

      DISPLAY = pgm_read_byte(&Tabela[valor]);
      _delay_ms(200);
    }
  }
}