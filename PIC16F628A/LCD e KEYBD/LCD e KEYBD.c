//*****************************************************************************
// CCS C Compiler for PIC
//*****************************************************************************
#include <16F628A.h>
#use delay(internal=4000000)
//*****************************************************************************

#FUSES NOMCLR                  //Master Clear pin used for I/O
#FUSES NOBROWNOUT              //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
//*****************************************************************************
#define use_portb_kbd TRUE //Teclado definido para o port B
#include <KBD.C>
//*****************************************************************************
/*
#define LCD_DATA_PORT getenv("SFR:PORTB");
#define LCD_ENABLE_PIN  PIN_B0
#define LCD_RS_PIN      PIN_B1
#define LCD_RW_PIN      PIN_B2
#define LCD_DATA4       PIN_B4
#define LCD_DATA5       PIN_B5
#define LCD_DATA6       PIN_B6
#define LCD_DATA7       PIN_B7
#include <lcd.c>
*/
//*****************************************************************************
#define LCD_DATA_PORT getenv("SFR:PORTB")
#include "flex_lcd.c"
//*****************************************************************************
char tecla;
//*****************************************************************************

void main()
{
  kbd_init();
  lcd_init();
  lcd_putc("\fTeste de LCD\r\n");
    
  while(TRUE)
  {
     tecla=kbd_getc();
     delay_ms(1);
     if (tecla!=0){ //tecla diferente de zero, foi pressionada
        printf(lcd_putc, "%c", tecla);
        if (tecla == '*') lcd_putc("\fTeste de LCD\r\n"); // Limpar a tela e exibir novas teclas pressionadas   
        delay_ms(200);
     }
  }
}
//*****************************************************************************
