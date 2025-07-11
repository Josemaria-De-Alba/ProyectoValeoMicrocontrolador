/*
 * ExPuertos.c
 *
 * Created: 29/05/2025 01:32:26 p. m.
 * Author: L00638437
 */



#include <mega328p.h>
#include <delay.h>
#include <stdio.h>

#define STCLK_595 PORTB.2
#define SHCLK_595 PORTB.0
#define DATA_595 PORTB.1

/*
void Escribe595 (unsigned char dato)
{
    unsigned char i;
    for (i=0;i<8;i++)
    {
        if ((dato&0x80)==0)
          DATA_595=0;
        else
          DATA_595=1;  
        SHCLK_595=1;   //Captura bit el 595
        SHCLK_595=0;     
        dato=dato<<1;  
    }     
    STCLK_595=1;      //Storage Clock
    STCLK_595=0;
}
*/

int s; //Sensor Number
//int T1, T2, T3;
//char sep1,sep2,sep3; //separacion
char estado;


void main(void)
{
    // USART initialization
    // Communication Parameters: 8 Data, 1 Stop, No Parity
    // USART Receiver: On
    // USART Transmitter: On
    // USART Mode: Asynchronous
    // USART Baud Rate: 9600 (Double Speed Mode)
    UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (1<<U2X0) | (0<<MPCM0);
    UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
    UCSR0C=(0<<UMSEL01) | (0<<UMSEL00) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
    UBRR0H=0x00;
    UBRR0L=0x0C;
    
    
    DDRB=0xFF;
    DDRC=0xFF;
    DDRD=0xFC;
    printf("Terminal Conected\r");
    

    while (1){  
       /*            
       Escribe595(k);
       k++;
       delay_ms(500);
       */
       if((UCSR0A&0x80) != 0){
            scanf("%i%c",&s,&estado);
                //Sensor 1
                if(s == 1){
                    if ((estado == 'V') || (estado == 'v')){
                        PORTD.2 = 0;
                        PORTD.3 = 0;
                        PORTD.4 = 0;   
                        printf("Sensor 1 en +12 volts\n\r");  
                    }
                    else if ((estado == 'G') || (estado == 'g')){
                        PORTD.2 = 0;
                        PORTD.3 = 1;
                        PORTD.4 = 0;
                        printf("Sensor 1 en Gnd\n\r");
                    }
                    else if ((estado == 'S') || (estado == 's')){
                        PORTD.2 = 1;
                        PORTD.3 = 0;
                        PORTD.4 = 0;
                        printf("Sensor 1 en Sensor\n\r");
                    } 
                    else if ((estado == 'C') || (estado == 'c')){
                        PORTD.2 = 1;
                        PORTD.3 = 1;
                        PORTD.4 = 1;
                        printf("Sensor 1 en Circuito Abierto\n\r");
                    }
                    else{
                        printf("Letra invalida para comando\r");
                    }
                }
                
                //Sensor 2
                else if(s == 2){
                    if ((estado == 'V') || (estado == 'v')){
                        PORTD.5 = 0;
                        PORTD.6 = 0;
                        PORTD.7 = 0;   
                        printf("Sensor 2 en +12 volts\n\r");  
                    }
                    else if ((estado == 'G') || (estado == 'g')){
                        PORTD.5 = 0;
                        PORTD.6 = 1;
                        PORTD.7 = 0;
                        printf("Sensor 2 en Gnd\n\r");
                    }
                    else if ((estado == 'S') || (estado == 's')){
                        PORTD.5 = 1;
                        PORTD.6 = 0;
                        PORTD.7 = 0;
                        printf("Sensor 2 en Sensor\n\r");
                    } 
                    else if ((estado == 'C') || (estado == 'c')){
                        PORTD.5 = 1;
                        PORTD.6 = 1;
                        PORTD.7 = 1;
                        printf("Sensor 2 en Circuito Abierto\n\r");
                    }
                    else{
                        printf("Letra invalida para comando\r");
                    }
                }
                
                //Sensor 3
                else if(s == 3){
                    if ((estado == 'V') || (estado == 'v')){
                        PORTC.5 = 0;
                        PORTC.4 = 0;
                        PORTC.3 = 0;   
                        printf("Sensor 3 en +12 volts\n\r");  
                    }
                    else if ((estado == 'G') || (estado == 'g')){
                        PORTC.5 = 0;
                        PORTC.4 = 1;
                        PORTC.3 = 0;
                        printf("Sensor 3 en Gnd\n\r");
                    }
                    else if ((estado == 'S') || (estado == 's')){
                        PORTC.5 = 1;
                        PORTC.4 = 0;
                        PORTC.3 = 0;
                        printf("Sensor 3 en Sensor\n\r");
                    } 
                    else if ((estado == 'C') || (estado == 'c')){
                        PORTC.5 = 1;
                        PORTC.4 = 1;
                        PORTC.3 = 1;
                        printf("Sensor 3 en Circuito Abierto\n\r");
                    }
                    else{
                        printf("Letra invalida para comando\r");
                    }
                }
                
                //Sensor 4
                else if(s == 4){
                    if ((estado == 'V') || (estado == 'v')){
                        PORTC.2 = 0;
                        PORTC.1 = 0;
                        PORTC.0 = 0;   
                        printf("Sensor 4 en +12 volts\n\r");  
                    }
                    else if ((estado == 'G') || (estado == 'g')){
                        PORTC.2 = 0;
                        PORTC.1 = 1;
                        PORTC.0 = 0;
                        printf("Sensor 4 en Gnd\n\r");
                    }
                    else if ((estado == 'S') || (estado == 's')){
                        PORTC.2 = 1;
                        PORTC.1 = 0;
                        PORTC.0 = 0;
                        printf("Sensor 4 en Sensor\n\r");
                    } 
                    else if ((estado == 'C') || (estado == 'c')){
                        PORTC.2 = 1;
                        PORTC.1 = 1;
                        PORTC.0 = 1;
                        printf("Sensor 4 en Circuito Abierto\n\r");
                    }
                    else{
                        printf("Letra invalida para comando\r");
                    }
                }
                
                else{
                    printf("Sensor o comando invalido\r");
                }                  
    
       }
    }
}




