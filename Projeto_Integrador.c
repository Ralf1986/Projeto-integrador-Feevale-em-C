#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Evento {
    char data[12];
    char hora[9];
    int id;
    int evento_tipo;
    struct Evento *proximo;
};

typedef struct Evento Evento;

//====================================declarações das função=======================================//

void processarArquivo(FILE *arquivo, Evento **inicio_lista);
Evento *criarNodo(char *data, char *hora, int id, int evento_tipo);
Evento* inserir_inicio(Evento* inicio_lista);
Evento* inserir_fim(Evento* inicio_lista);
Evento* remover_evento(Evento* inicio_lista, int id);
void imprimir_lista(Evento *inicio_lista);
void liberarMemoria(Evento *inicio_lista);
void ler_evento(Evento *tmp);
Evento* criar_lista(void);

//===========================================Main==================================================//

int main() {
    
    Evento *inicio_lista = NULL;

    FILE *arquivo = fopen("syslog", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    processarArquivo(arquivo, &inicio_lista);
    fclose(arquivo);

    printf("\n|============Monitoramento das interfaces de rede============|\n");

    int escolha;
    do {
        printf("\nMenu de Opções:\n");
        printf("\n");
        printf("\t1- Adicionar um evento no inicio da estrutura\n");
        printf("\t2- Adicionar um evento no fim da estrutura\n");
        printf("\t3- Remover um evento da estrutura\n");
        printf("\t4- Listar todos os eventos da estrutura\n");
        printf("\t5- Liberar lista\n");
        printf("\t6- Sair\n");
        printf("\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                inicio_lista = inserir_inicio(inicio_lista);
                break;
            case 2:
                inicio_lista = inserir_fim(inicio_lista);
                break;

            case 3: {
                int id;
                printf("Digite o ID do evento a ser removido: ");
                scanf("%d", &id);
                inicio_lista = remover_evento(inicio_lista, id);
                break;
            }
            case 4:
                imprimir_lista(inicio_lista);
                break;
            case 5:
                liberarMemoria(inicio_lista);
                inicio_lista = criar_lista(); // Recriar a lista vazia
                printf("Lista liberada.\n");
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 6);


    return 0;
}

//==========================================Funções================================================//

//======================================Processar Arquivo==========================================//

void processarArquivo(FILE *arquivo, Evento **inicio_lista) {
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char mes[4], dia_str[3], hora[9];
        int dia, id;

        if (sscanf(linha, "%3s %2s %8s %*s NetworkManager[%d]: %*s %*s state is now %*s_%*s\n", mes, dia_str, hora, &id) == 4) {
            dia = atoi(dia_str);
            char data[12];
            sprintf(data, "%s %02d", mes, dia);

            int evento_tipo = -1;
            if (strstr(linha, "CONNECTED_LOCAL")) {
                evento_tipo = 1;
            } else if (strstr(linha, "DISCONNECTED")) {
                evento_tipo = 0;
            }

            if (evento_tipo != -1) {
                Evento *novoEvento = criarNodo(data, hora, id, evento_tipo);
                if (*inicio_lista == NULL) {
                    *inicio_lista = novoEvento;
                } else {
                    Evento *temp = *inicio_lista;
                    while (temp->proximo != NULL) {
                        temp = temp->proximo;
                    }
                    temp->proximo = novoEvento;
                }
            }
        }
    }
}

//=========================================Criar nodo==============================================//

Evento *criarNodo(char *data, char *hora, int id, int evento_tipo) {
    Evento *novoEvento = (Evento *)malloc(sizeof(Evento));
    if (novoEvento == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novoEvento->data, data);
    strcpy(novoEvento->hora, hora);
    novoEvento->id = id;
    novoEvento->evento_tipo = evento_tipo;
    novoEvento->proximo = NULL;
    return novoEvento;
}

//==================================adicionar um evento à estrutura================================//

Evento* inserir_inicio(Evento* inicio_lista) {
    Evento* novo = (Evento*)malloc(sizeof(Evento));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return inicio_lista;
    }
    ler_evento(novo);
    novo->proximo = inicio_lista;
    return novo;
}

//==============================adicionar um evento no fim da estrutura============================//

Evento* inserir_fim(Evento* inicio_lista) {
    Evento* novo = (Evento*)malloc(sizeof(Evento));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return inicio_lista;
    }
    ler_evento(novo);
    novo->proximo = NULL;                // Defina o próximo do novo evento como NULL.
 
    if (inicio_lista == NULL) {
                                         // Se a lista estiver vazia, o novo evento se torna o início da lista.
        return novo;
    } else {
        Evento* temp = inicio_lista;

                                 
        while (temp->proximo != NULL) {  // Percorra a lista até o último elemento.
            temp = temp->proximo;
        }

                                
        temp->proximo = novo;           // Defina o próximo do último elemento para o novo evento.
        return inicio_lista;
    }
}

//===================================remover um evento da estrutura================================//

Evento* remover_evento(Evento* inicio_lista, int id) {
    Evento* anterior = NULL;
    Evento* atual = inicio_lista;

    while (atual != NULL) {
        if (atual->id == id) {
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;
            } else {
                inicio_lista = atual->proximo;
            }
            free(atual);
            return inicio_lista;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Evento com ID %d não encontrado.\n", id);
    return inicio_lista;
}

//================================listar todos os eventos da estrutura==============================//

void imprimir_lista(Evento *inicio_lista) {
    if (inicio_lista == NULL) {
        printf("Lista vazia.\n");
    } else {
        Evento *tmp = inicio_lista;
        printf("Eventos:\n");
        while (tmp != NULL) {
            printf("Data: %s, Hora: %s, ID: %d, Tipo de evento: %s\n",
                   tmp->data, tmp->hora, tmp->id,
                   tmp->evento_tipo == 1 ? "Conexão" : "Desconexão");
            tmp = tmp->proximo;
        }
    }
}


//=========================================Liberar memoira==========================================//

void liberarMemoria(Evento *inicio_lista) {
    while (inicio_lista != NULL) {
        Evento *temp = inicio_lista;
        inicio_lista = inicio_lista->proximo;
        free(temp);
    }
}

//===========================================Ler eventos============================================//

void ler_evento(Evento *tmp){
    printf("\nFormato do evento: Data: Sep 17, Hora: 10:37:59, ID: 820, Tipo de evento: Conexão: \n");
    printf("\nData (MMM DD): ");
    scanf(" %[^\n]", tmp->data);
    getchar();

    printf("\nHora (HH:MM:SS): ");
    scanf(" %[^\n]", tmp->hora);
    getchar();

    printf("\nId: ");
    scanf("%d", &tmp->id);
    getchar();

    printf("\nTipo de evento (Conexão ou Desconexão, 1 ou 0): ");
    scanf("%d", &tmp->evento_tipo);   
}

//========================================criar lista vazia=========================================//

Evento* criar_lista(void) {
    return NULL;
}

//===============================================FIM================================================//