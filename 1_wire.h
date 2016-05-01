

#ifndef _1_WIRE_H_
#define _1_WIRE_H_
//Incluye la librería del pic para asignar el pin al bus
//en este caso es el PIC24FJ64GA002 perompuede ser utilizado
//en otros PICs
#include <p24FJ64GA002.h>
#ifndef FCY
#define FCY 4000000UL
    #warning no se ha definido la frecuencia del oscilador
#endif
#include <libpic30.h>

//define los comandos ROM
#define SEARCH_ROM 0xF0
#define READ_ROM 0x33
#define MATCH_ROM 0x55
#define SKIP_ROM 0xCC
#define ALARM_SEARCH 0xEC

//define los comandos del sensor DS18B20

#define CONVERT_T 0x44
#define WRITE_SCRATCHPAD 0x4E
#define READ_SCRATCHPAD 0xBE
#define COPY_SCRATCHPAD 0x48
#define RECALL_E 0xB8
#define READ_POWER 0xB4


//define las asignaciones de pines
#define _1W_TRIS TRISBbits.TRISB15
#define _1W_PIN  PORTBbits.RB15
#define _1W_LAT  LATBbits.LATB15


unsigned char  leer_bit_1w();
void escribe_1_1w();
void escribe_0_1w();
unsigned char reset_1w();
void escribe_byte_1w(unsigned char);
void leer_n_bytes_1w(unsigned char, unsigned char*);

#endif

