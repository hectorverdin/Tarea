
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Función que ejecutará el hilo secundario (imprime del 10,000 al 1)
void* tarea_hilo(void* arg) {
    for (int i = 10000; i >= 1; i--) {
        printf("[HILO] Numero: %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t hilo;

    // Crear el hilo secundario
    if (pthread_create(&hilo, NULL, tarea_hilo, NULL) != 0) {
        perror("Error al crear el hilo");
        return EXIT_FAILURE;
    }

    // Proceso / Hilo principal (imprime del 1 al 10,000)
    for (int i = 1; i <= 10000; i++) {
        printf("[PRINCIPAL] Numero: %d\n", i);
    }

    // Esperar a que el hilo secundario termine su ejecución
    pthread_join(hilo, NULL);

    return EXIT_SUCCESS;
}