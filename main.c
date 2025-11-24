#include <stdio.h>
#include "ventas.h"
 
int main(void) {
    float ventas[TAM_MAX];
    int n = 0;
    int opcion;
    int hayVentas = 0;
    int lectura;
 
    do {
        printf("\nBIENVENIDO AL EXAMEN DEL PROGRESO 2 || Calderon - Viteri\n");
        printf("1. Define el numero de dias (como maximo son %d)\n", TAM_MAX);
        printf("2. Ingresa las ventas\n");
        printf("3. Procesar los datos registrados (total, promedio, maximo)\n");
        printf("4. Muestra los resultados\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
 
        lectura = scanf("%d", &opcion);
        if (lectura != 1) {
            printf("Entrada invalida, solo se acpetan numeros\n");
            while (getchar() != '\n');
            continue;
        }
 
        switch (opcion) {
            case 1:
                do {
                    printf("Cuantos dias desea registrar (1-%d): ", TAM_MAX);
                    lectura = scanf("%d", &n);
                    if (lectura != 1) {
                        printf("Tu entrada es invalida, solo se acepetan numeros\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (n < 1 || n > TAM_MAX) {
                        printf("Tu entrada es invalida, solo se acepetan numeros\n");
                    }
                } while (lectura != 1 || n < 1 || n > TAM_MAX);
                hayVentas = 0;
                break;
 
            case 2:
                if (n <= 0) {
                    printf("Tu entrada es invalida, solo se acepetan numeros\n");
                } else {
                    leerVentas(ventas, n);
                    hayVentas = 1;
                }
                break;
 
            case 3:
                if (!hayVentas) {
                    printf("Primero tienes que ingresar las ventas\n");
                } else {
                    float total = calcularTotal(ventas, n);
                    float promedio = calcularPromedio(ventas, n);
                    float maxima = calcularMaxima(ventas, n);
                    printf("\nProcesamiento realizado con exito\n");
                    printf("Total de ventas: %.2f\n", total);
                    printf("Promedio de las ventas: %.2f\n", promedio);
                    printf("Venta maxima: %.2f\n", maxima);
                }
                break;
 
            case 4:
                if (!hayVentas) {
                    printf("Primero tienes que ingresar las ventas\n");
                } else {
                    float total = calcularTotal(ventas, n);
                    float promedio = calcularPromedio(ventas, n);
                    float maxima = calcularMaxima(ventas, n);
                    mostrarResultados(total, promedio, maxima);
                }
                break;
 
            case 0:
                printf("Cerrando el programa\n");
                break;
 
            default:
                printf("Entrada invalida, solo se acpetan numeros\n");
                break;
        }
 
    } while (opcion != 0);
 
    return 0;
}