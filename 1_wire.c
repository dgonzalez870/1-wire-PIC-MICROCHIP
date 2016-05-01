#include "1_wire.h"

/**
 * Lee 1 bit en el bus 1-wire
 * @return el valor del bit leido
 */
unsigned char leer_bit_1w()
{
    unsigned char dato;
    _1W_TRIS=0;
    _1W_LAT=0;
    __delay_us(6);
    _1W_LAT=1;
    _1W_TRIS=1;
    __delay_us(9);
    dato=_1W_PIN;
    __delay_us(55);
    return dato;
}

/**
 * Escribe un cero en la linea del bus
 */
void escribe_0_1w()
{
    _1W_TRIS=0; //configura el pin cono salida
    _1W_LAT=0;
    __delay_us(60);
    _1W_LAT=1;
    //_1W_TRIS=1; //libera la linea
    __delay_us(10);
}

/**
 * Escribe un 1 lógico en la linea del bus
 */
void escribe_1_1w()
{
    _1W_TRIS=0;
    _1W_LAT=0;
    __delay_us(6);
    _1W_LAT=1;
    //_1W_TRIS=1;
    __delay_us(64);
}

/**
 * Envía un pulso de inicio al bus y espera la respuesta de presencia por el esclavo
 * @return 0 si se confirma la presencia de un esclavo, 1 si no responde el esclavo
 */
unsigned char reset_1w()
{
    unsigned char presencia;
    _1W_TRIS=0;
    _1W_LAT=0;
    __delay_us(480);
    _1W_LAT=1;
    _1W_TRIS=1; //configura el pin como entrada y libera la línea del bus
    __delay_us(100);
    presencia=_1W_PIN;
    __delay_us(410);
    //_1W_TRIS=0; //configura el pin como salida
    return presencia;
}

/**
 * Escribe un byte en el bus
 * @param dato - el dato a ser enviado en el bus
 */
void escribe_byte_1w(unsigned char dato)
{
    unsigned char i=0;
    for(i=0;i<8;i++)
    {
        if(i>0)
            dato>>=1;
    if(dato & 1)
        escribe_1_1w();
    else
        escribe_0_1w();
    }
}
/**
 * Lee la cantidad de bytes indicadas en el bus
 * @param nBytes - número de bytes a ser leidos
 * @param destino - puntero a l dirección en la que se guardarán los datos
 */
void leer_n_bytes_1w(unsigned char nBytes, unsigned char* destino)
{
    unsigned char leido=0,i=0,j=0;

    for(i=0;i<nBytes;i++)
    {
        for(j=0;j<8;j++)
        {
            leido+=leer_bit_1w()<<j;
        }
        *destino=leido;
        destino++;
        leido=0;
    }
}

