#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int dividir(int dividendo, int divisor) {
    // Manejo de casos especiales para evitar desbordamiento
    if (dividendo == INT_MIN && divisor == -1) {
        return INT_MAX; // Evita overflow
    }
    if (dividendo == INT_MIN && divisor == 1) {
        return INT_MIN;
    }

    // Determinar el signo del resultado
    int signo = ((dividendo < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convertir ambos números a valores positivos
    long long absDividendo = (dividendo < 0) ? -(long long)dividendo : dividendo;
    long long absDivisor = (divisor < 0) ? -(long long)divisor : divisor;
    
    int cociente = 0;

    // Resta sucesiva usando desplazamiento de bits
    while (absDividendo >= absDivisor) {
        long long temp = absDivisor, multiplo = 1;
        while (absDividendo >= (temp << 1)) {
            temp <<= 1;
            multiplo <<= 1;
        }
        absDividendo -= temp;
        cociente += multiplo;
    }

    return signo * cociente;
}

int main() {
    int dividendo, divisor;
    
    // Solicitar entrada al usuario
    printf("Ingrese el dividendo: ");
    scanf("%d", &dividendo);
    
    do {
        printf("Ingrese el divisor (no puede ser 0): ");
        scanf("%d", &divisor);
    } while (divisor == 0); // Evita que el usuario ingrese 0 como divisor

    // Llamar a la función y mostrar el resultado
    int resultado = dividir(dividendo, divisor);
    printf("Resultado de la división: %d\n", resultado);

    return 0;
}
