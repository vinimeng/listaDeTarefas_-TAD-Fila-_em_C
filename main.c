#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "fila.h"

void textoInicio() {
    printf("Programa para lista de tarefas by Vinícius Meng\n");
    printf("Escolha uma opção:\n");
    printf("1 - Adicionar tarefa\n");
    printf("2 - Remover tarefa\n");
    printf("3 - Listar tarefas\n");
    printf("4 - Encerrar programa\n");
    printf("Escolha: ");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    fila fl;
    int escolha = 0;
    char tmp;
    while (escolha != 4) {
        textoInicio();
        scanf("%d%c", &escolha, &tmp);
        switch (escolha) {
            case 1:
                adicionar(&fl);
                break;
            case 2:
                remover(&fl);
                break;
            case 3:
                listar(&fl);
                break;
            case 4:
                break;
            default:
                limparTela();
                printf("Opção inválida!\n\n");
        }
    }
    return 0;
}