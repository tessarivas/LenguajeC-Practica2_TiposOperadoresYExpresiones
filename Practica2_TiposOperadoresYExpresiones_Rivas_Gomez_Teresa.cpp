#include <stdio.h>
#include <string.h>

#define MAX_INVENTARIO 100

struct Producto {
    char codigo[20];
    char nombre[50];
    int cantidad;
    double precio;
};

// Prototipos de funciones
int mostrarMenu();
void gestionarInventario(struct Producto inventario[], int *cantidadProductos);
void entrada(struct Producto inventario[], int *cantidadProductos);
void salida(struct Producto inventario[], int *cantidadProductos);
void mostrarInventario(struct Producto inventario[], int cantidadProductos);
void programa2();
void programa3();

int main() {
    int opcion;
    struct Producto inventario[MAX_INVENTARIO]; // Declarar el inventario aquí
    int cantidadProductos = 0; // Inicializar la cantidad de productos en 0

    do {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                gestionarInventario(inventario, &cantidadProductos); // Pasar el inventario y la cantidad de productos
                break;
            case 2:
                programa2();
                break;
            case 3:
                programa3();
                break;
            case 0:
                printf("Saliendo del programa. Gracias por usar el sistema.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opción valida.\n");
        }
    } while (opcion != 0);

    return 0;
}

int mostrarMenu() {
    int opcion;

    printf("MENU\n");
    printf("1. Gestionar Inventario\n");
    printf("2. Programa 2\n");
    printf("3. Programa 3\n");
    printf("0. Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void gestionarInventario(struct Producto inventario[], int *cantidadProductos) {
    int op;
    printf("\nMENU\n");
    printf("1-Agregar elementos \n");
    printf("2-Retirar elementos \n");
    printf("3-Mostrar inventario \n");
    printf("4-Salir \n");
    printf("SELECCIONA UNA OPCION NUMERICA \n");
    scanf("%d", &op); // seleccion de opcion del usuario
    switch (op)
    {
    case 1:
        entrada(inventario, cantidadProductos); // funcion ingresar donde se le agregan datos al inventario 
        break;
    case 2:
        salida(inventario, cantidadProductos); // funcion eliminar del inventario
        break;
    case 3:
        mostrarInventario(inventario, *cantidadProductos); // funcion mostrar el inventario 
        break;
    case 4:
        printf("Gracias!, nos vemos pronto! \n");  // mensaje en caso de que el usuario desee salir del menú de inventario 
        break;
    default:
        printf("OPCION INCORRECTA, INTENTALO DE NUEVO! \n");  // mensaje en caso de que el usuario ingrese una opción incorrecta
        break;
    }
    printf("\n");
}

void entrada(struct Producto inventario[], int *cantidadProductos) {
    if (*cantidadProductos < MAX_INVENTARIO) {
        printf("Ingrese el codigo del producto: ");
        scanf("%s", inventario[*cantidadProductos].codigo);
        printf("Ingrese el nombre del producto: ");
        scanf(" %[^\n]", inventario[*cantidadProductos].nombre);
        printf("Ingrese la cantidad: ");
        scanf("%d", &inventario[*cantidadProductos].cantidad);
        printf("Ingrese el precio: ");
        scanf("%lf", &inventario[*cantidadProductos].precio);
        (*cantidadProductos)++;
        printf("Producto agregado al inventario.\n");
    } else {
        printf("El inventario está lleno. No se pueden agregar más productos.\n");
    }
}

void salida(struct Producto inventario[], int *cantidadProductos) {
    if (*cantidadProductos > 0) {
        char codigo[20];
        printf("Ingrese el codigo del producto que desea retirar: ");
        scanf("%s", codigo);

        int encontrado = 0;

        for (int i = 0; i < *cantidadProductos; i++) {
            if (strcmp(inventario[i].codigo, codigo) == 0) {
                printf("Retirando producto: %s\n", inventario[i].nombre);
                // Implementa aquí la lógica para retirar el producto
                // Puedes decrementar la cantidad o eliminarlo del inventario
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("El producto no se encuentra en el inventario.\n");
        }
    } else {
        printf("El inventario esta vacio. No se pueden retirar productos.\n");
    }
}

void mostrarInventario(struct Producto inventario[], int cantidadProductos) {
    if (cantidadProductos > 0) {
        printf("Inventario:\n");
        printf("%-10s%-30s%-10s%-10s\n", "Codigo", "Nombre", "Cantidad", "Precio");
        for (int i = 0; i < cantidadProductos; i++) {
            printf("%-10s%-30s%-10d%-10.2lf\n", inventario[i].codigo, inventario[i].nombre,
                   inventario[i].cantidad, inventario[i].precio);
        }
    } else {
        printf("El inventario esta vacio.\n");
    }
}

void programa2() {
    printf("Funcion del Programa 2\n");
    int numero_decimal;

    printf("Ingresa un numero decimal: \n");
    scanf("%d", &numero_decimal);

    if (numero_decimal < 0){
        printf("Ingrese un valor valido.\n");
    }

    int numero_bits=0;
    int temp = numero_decimal;

    while (temp > 0){
        temp/=2;
        numero_bits++;
    }

    int bits[numero_bits];
    int indice = 0;

    while (numero_decimal > 0) {
        bits[indice] = numero_decimal % 2;
        numero_decimal /= 2;
        indice++;
    }

    printf("Numero en bits: \n");

    for(int i = indice - 1; i >= 0; i--){
        printf("%d", bits[i]);
    }
    printf("\n");

    int bits_encendidos = -1;

    printf("Los bits encendidos estan en la posición: \n");

    for (int i = 0; i < indice; i++){
        if (bits[i] == 1){
            bits_encendidos = i;
            printf("%d ", bits_encendidos + 1);
        }
    }

    if (bits_encendidos == -1){
        printf("No se encontro ningun bit encendido.\n");
    }
}

void programa3() {
    printf("Funcion del Programa 3\n");
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
}
