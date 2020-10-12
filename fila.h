typedef struct nodo nodo;

struct nodo {
    char tarefa[1024];
    nodo *posterior;
    char ultimo;
};

typedef struct fila {
    nodo primeiro;
    char inicializada;
} fila;

void limparTela();

void adicionar(fila *filaAdicionar);

void remover(fila *filaRemover);

void listar(fila *filaListar);
