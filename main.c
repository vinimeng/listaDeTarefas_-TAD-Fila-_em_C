#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

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
    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleCP(1252);
        SetConsoleOutputCP(1252);
    #endif
    fila fl;
    int escolha = 0;
    char tmp[3];
    while (escolha != 4) {
        textoInicio();
        fgets(tmp, 3, stdin);
        escolha = atoi(tmp);
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