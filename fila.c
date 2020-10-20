#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void limparTela() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void adicionar(fila *filaAdicionar) {
    limparTela();
    printf("Adicionar tarefa:");
    printf("\nDescreva a sua tarefa [1000 caract. máx.]: ");
    if (filaAdicionar->inicializada == '\0') {
        nodo *nodoFila = &filaAdicionar->primeiro;
        while (nodoFila->ultimo != '\0') {
            nodoFila = nodoFila->posterior;
        }
        nodoFila->posterior = malloc(sizeof(nodo));
        fgets(nodoFila->posterior->tarefa, 1001, stdin);
        nodoFila->posterior->ultimo = '\0';
        nodoFila->ultimo = 'N';
    } else {
        fgets(filaAdicionar->primeiro.tarefa, 1001, stdin);
        filaAdicionar->primeiro.ultimo = '\0';
        filaAdicionar->inicializada = '\0';
    }
    limparTela();
    printf("Tarefa adicionada com sucesso!\n\n");
}

void remover(fila *filaRemover) {
    limparTela();
    if(filaRemover->inicializada == '\0') {
        if (filaRemover->primeiro.ultimo == '\0') {
            filaRemover->inicializada = 'N';
        } else {
            nodo *remover = filaRemover->primeiro.posterior;
            filaRemover->primeiro = *filaRemover->primeiro.posterior;
            free(remover);
        }
        printf("Tarefa removida com sucesso!\n\n");
    } else {
        printf("Sem tarefas para remover!\n\n");
    }
}

void listar(fila *filaListar) {
    limparTela();
    if(filaListar->inicializada == '\0') {
        nodo *nodoFila = &filaListar->primeiro;
        printf("Tarefa 1:\n");
        printf("%s", nodoFila->tarefa);
        int i = 2;
        while (nodoFila->ultimo != '\0') {
            nodoFila = nodoFila->posterior;
            printf("Tarefa %d:\n", i);
            printf("%s", nodoFila->tarefa);
            i++;
        }
        printf("\n");
    } else {
        printf("Sem tarefas para listar!\n\n");
    }
}
