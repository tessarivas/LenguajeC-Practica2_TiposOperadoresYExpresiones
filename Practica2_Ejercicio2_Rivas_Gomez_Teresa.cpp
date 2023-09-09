// 2. Crear un programa que tome una calificación numérica y la convierta en una
// calificación en letra utilizando operadores ternarios.

#include <stdio.h>

int main() {
    int cal;

    printf("Ingrese su calificacion: ");
    scanf("%d", &cal);

    if (cal >= 0 && cal <= 100) {
        const char* mensaje = (cal <= 59) ? "F" :
                              (cal <= 69) ? "D" :
                              (cal <= 79) ? "C" :
                              (cal <= 89) ? "B" :
                                            "A";
        printf("Tu calificacion es %s\n", mensaje);
    } else {
        printf("La calificacion debe estar en el rango de 0 a 100.\n");
    }

    return 0;
}
