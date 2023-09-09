// 1. Crear un programa que permita a los usuarios ingresar un número entero, especificar
// el número de bits que se deben considerar y luego analizar el número en términos de
// bits encendidos, posiciones y representación binaria.

#include <stdio.h>

int main ()
{
    int numero_decimal;

    printf("Ingresa un numero decimal: \n");
    scanf("%d", &numero_decimal);

    if (numero_decimal < 0){
        return 1;
    }

    int numero_bits=0;
    int temp = numero_decimal;

    while (temp > 0){
        temp/=2;
        numero_bits++;
    }

    int bits[numero_bits];
    int indice;

    while (numero_decimal > 0) {
        bits[indice] = numero_decimal %2;
        numero_decimal /=2;
        indice++;
    }

    printf("Numero en bits: \n");

    for(int i=indice-1; i>=0; i--){
        printf("%d", bits[i]);
    }
    printf("\n");

    int bits_encendidos = -1;

    printf("Los bits encendidos estan en la posicion: \n");

    for (int i=0; i<indice; i++){
        if (bits[i]==1){
            bits_encendidos=i;
            printf("%d", bits_encendidos+1);
        }
    }

    if (bits_encendidos == -1){
        printf("No se encontro ningun bit encendido.");
    }

    return 0;
}