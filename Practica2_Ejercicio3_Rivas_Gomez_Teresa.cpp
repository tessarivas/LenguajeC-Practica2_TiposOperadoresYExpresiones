#include <stdio.h>
#include <string.h>

#define TAMANO_MAX_INVENTARIO 100
//Estructura de cada articulo
struct ArticuloInventario {
    char codigo[20];
    char nombre[50];
    int cantidad;
    double precio;
};
//Estructuras ArticuloInventario y un puntero a un entero count que representa 
//la cantidad actual de elementos en el inventario.
void entrada(struct ArticuloInventario Inventario[], int *count) {
	//verifica si la cantidad actual de elementos en el inventario 
	//es menor que el tamaño maximo permitido
    if (*count < TAMANO_MAX_INVENTARIO) {
        printf("\nIngrese el codigo del producto: ");
        scanf("%s", Inventario[*count].codigo);
        printf("Ingrese el nombre del producto: ");
        scanf(" %[^\n]", Inventario[*count].nombre);
        printf("Ingrese la cantidad: ");
        scanf("%d", &Inventario[*count].cantidad);
        printf("Ingrese el precio: ");
        scanf("%lf", &Inventario[*count].precio);
        (*count)++; //Se incrementa el valor de count en 1 para reflejar la adicion 
		//del nuevo articulo al inventario, y se muestra un mensaje de confirmacion.
        printf("Producto agregado al inventario.\n");
    } else {
        printf("El inventario esta lleno. No se pueden agregar mas productos.\n");
    }
}

void salida(struct ArticuloInventario Inventario[], int *count) {
	//Verifica si la cantidad actual de elementos en el inventario es mayor que cero
    if (*count > 0) {
        char CodigoProducto[20];
        printf("\nIngrese el codigo del producto que desea retirar: ");
        scanf("%s", CodigoProducto);

        int found = 0; //Variable found inicializada en 0 para rastrear si se encuentra el artículo que se desea retirar
        for (int i = 0; i < *count; i++) {
        	//Se compara el codigo del articulo en la posicion actual del inventario 
			//con el codigo ingresado por el usuario:
            if (strcmp(Inventario[i].codigo, CodigoProducto) == 0) {
                // Retirar el producto
                for (int j = i; j < *count - 1; j++) {
                    strcpy(Inventario[j].codigo, Inventario[j + 1].codigo);
                    strcpy(Inventario[j].nombre, Inventario[j + 1].nombre);
                    Inventario[j].cantidad = Inventario[j + 1].cantidad;
                    Inventario[j].precio = Inventario[j + 1].precio;
                    //para llenar el espacio del articulo retirado
                }
                (*count)--; //decrementa la cantidad actual de elementos en el inventario en 1
                found = 1; //indicar que se encontro y retiro el articulo
                printf("Producto retirado del inventario.\n");
                break;
            }
        }
		//significa que no se encontro el producto
        if (!found) {
            printf("El producto no se encuentra en el inventario.\n");
        }
    } else {
        printf("El inventario esta vacio. No se pueden retirar productos.\n");
    }
}

void inventario(struct ArticuloInventario Inventario[], int count) {
    printf("\nInventario:\n"); //Muestra encabezados de columna para el inventario
    printf("%-10s%-30s%-10s%-10s\n", "Codigo", "Nombre", "Cantidad", "Precio");
    //Recorre todos los elementos en el inventario
	for (int i = 0; i < count; i++) {
        printf("%-10s%-30s%-10d%-10.2lf\n", Inventario[i].codigo, Inventario[i].nombre, Inventario[i].cantidad, Inventario[i].precio);
    }
}

int main() {
    struct ArticuloInventario Inventario[TAMANO_MAX_INVENTARIO];
    int Articulo = 0;
    int eleccion;

    printf("Sistema de Inventario\n");
	//Menu del programa
    while (1) {
        printf("\n M E N U: \n");
        printf("1. Entrada de producto\n");
        printf("2. Salida de producto\n");
        printf("3. Mostrar inventario\n");
        printf("4. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &eleccion);
	//Casos a elegir dependiendo de la seleccion
        switch (eleccion) {
            case 1:
                entrada(Inventario, &Articulo);
                break;
            case 2:
                salida(Inventario, &Articulo);
                break;
            case 3:
                inventario(Inventario, Articulo);
                break;
            case 4:
                printf("Saliendo del programa. Gracias por usar el sistema de inventario.\n");
                return 0;
            default:
                printf("Opcion no valida. Por favor, seleccione una opciOn valida.\n");
        }
    }

    return 0;
}