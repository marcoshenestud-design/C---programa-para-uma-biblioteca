#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constante para definir o tamanho máximo do acervo, isso que garante que o vetor nunca ultrapasse 20 livros.
#define TAMANHO_ACERVO 20

// Definição da estrutura Livro
struct Livro {
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

// Assinaturas das funções - modularização

// cadastrarLivros: Adiciona novos livros ao vetor 'acervo'
void cadastrarLivros(struct Livro acervo[], int *quantidade);

// imprimirLivros: Lista todos os livros cadastrados
void imprimirLivros(struct Livro acervo[], int quantidade);

// pesquisarLivro: Busca um livro por critério (título, autor, etc.)
void pesquisarLivro(struct Livro acervo[], int quantidade);

// ordenarLivros: Ordena os livros (ex: por título em ordem alfabética)
void ordenarLivros(struct Livro acervo[], int quantidade);


// Cada função = módulo independente com responsabilidade única.


int main() {
    // Declaração do acervo de livros
    struct Livro acervo[TAMANHO_ACERVO];
    int quantidadeLivros = 0; // Contador de livros cadastrados
    int opcao = 0;
    
    printf("=== SISTEMA DE GERENCIAMENTO DE LIVROS ===\n");
    printf("Biblioteca Municipal Rute&Raquel - Acervo Maximo: %d livros\n\n", TAMANHO_ACERVO);
    
    // Laço principal do programa
    do {
        exibirMenu();
        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao);
        limparBuffer(); // Limpa o buffer do teclado
        
        switch(opcao) {
            case 1:
                cadastrarLivros(acervo, &quantidadeLivros);
                break;
            case 2:
                imprimirLivros(acervo, quantidadeLivros);
                break;
            case 3:
                pesquisarLivro(acervo, quantidadeLivros);
                break;
            case 4:
                ordenarLivros(acervo, quantidadeLivros);
                break;
            case 5:
                printf("\nSaindo do sistema...\n");
                printf("Obrigado por usar nosso sistema de gerenciamento!\n");
                break;
            default:
                printf("\nOpcao invalida! Por favor, escolha uma opcao de 1 a 5.\n");
        }
        
        if (opcao != 5) {
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
        }
        
    } while(opcao != 5);
    
    return 0;
}

// Função para exibir o menu principal
void exibirMenu() {
    printf("\n=========== MENU PRINCIPAL ===========\n");
    printf("1 - Cadastrar livros\n");
    printf("2 - Imprimir todos os livros\n");
    printf("3 - Pesquisar livro por codigo\n");
    printf("4 - Ordenar livros por ano de publicacao\n");
    printf("5 - Sair do programa\n");
    printf("======================================\n");
}

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar livros no acervo
void cadastrarLivros(struct Livro acervo[], int *quantidade) {
    int numLivros;
    
    printf("\n=== CADASTRO DE LIVROS ===\n");
    printf("Livros cadastrados atualmente: %d/%d\n", *quantidade, TAMANHO_ACERVO);
    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &numLivros);
    limparBuffer();
    
    // Verifica se há espaço suficiente no acervo
    if (*quantidade + numLivros > TAMANHO_ACERVO) {
        printf("Erro: Nao ha espaco para cadastrar %d livros.\n", numLivros);
        printf("Espaco disponivel: %d livros.\n", TAMANHO_ACERVO - *quantidade);
        return;
    }
    
    // Cadastra cada livro
    for (int i = 0; i < numLivros; i++) {
        printf("\n--- Livro %d/%d ---\n", i + 1, numLivros);
        
        // Gera um código automático sequencial
        acervo[*quantidade].codigo = *quantidade + 1;
        printf("Codigo gerado automaticamente: %d\n", acervo[*quantidade].codigo);
        
        // Entrada do título
        printf("Titulo: ");
        fgets(acervo[*quantidade].titulo, 50, stdin);
        acervo[*quantidade].titulo[strcspn(acervo[*quantidade].titulo, "\n")] = '\0'; // Remove o \n
        
        // Entrada do autor
        printf("Autor: ");
        fgets(acervo[*quantidade].autor, 30, stdin);
        acervo[*quantidade].autor[strcspn(acervo[*quantidade].autor, "\n")] = '\0';
        
        // Entrada da área
        printf("Area (ex: Literatura, Ciencia, Historia): ");
        fgets(acervo[*quantidade].area, 30, stdin);
        acervo[*quantidade].area[strcspn(acervo[*quantidade].area, "\n")] = '\0';
        
        // Entrada do ano
        printf("Ano de publicacao: ");
        scanf("%d", &acervo[*quantidade].ano);
        limparBuffer();
        
        // Entrada da editora
        printf("Editora: ");
        fgets(acervo[*quantidade].editora, 30, stdin);
        acervo[*quantidade].editora[strcspn(acervo[*quantidade].editora, "\n")] = '\0';
        
        (*quantidade)++; // Incrementa o contador de livros
    }
    
    printf("\nCadastro concluido! %d livro(s) foram adicionados ao acervo.\n", numLivros);
}

// Função para imprimir todos os livros do acervo
void imprimirLivros(struct Livro acervo[], int quantidade) {
    printf("\n=== TODOS OS LIVROS DO ACERVO ===\n");
    
    if (quantidade == 0) { //Se não tiver nenhum livro cadastrado
        printf("Nenhum livro cadastrado no acervo.\n");
        return;
    }
    
    printf("Total de livros cadastrados: %d\n\n", quantidade);
    
    // Percorre e imprime todos os livros cadastrados na bibliotecas
    for (int i = 0; i < quantidade; i++) {
        printf("--- Livro %d ---\n", i + 1);
        printf("Codigo: %d\n", acervo[i].codigo);
        printf("Titulo: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Area: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
        printf("\n");
    }
}

// Função para pesquisar um livro por código
void pesquisarLivro(struct Livro acervo[], int quantidade) {
    int codigoBusca;
    int encontrado = 0; // Flag para indicar se o livro foi encontrado
    
    printf("\n=== PESQUISAR LIVRO POR CODIGO ===\n");
    
    if (quantidade == 0) {
        printf("Nenhum livro cadastrado no acervo.\n");
        return;
    }
    
    printf("Digite o codigo do livro: ");
    scanf("%d", &codigoBusca);
    limparBuffer();
    
    // Percorre o acervo em busca do código
    for (int i = 0; i < quantidade; i++) {
        if (acervo[i].codigo == codigoBusca) {
            printf("\n=== LIVRO ENCONTRADO ===\n");
            printf("Codigo: %d\n", acervo[i].codigo);
            printf("Titulo: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Area: %s\n", acervo[i].area);
            printf("Ano: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
            encontrado = 1;
            break; // Sai do loop pois encontrou o livro
        }
    }
    
    if (!encontrado) {
        printf("\nLivro com codigo %d nao encontrado no acervo.\n", codigoBusca);
    }
}

// Função para ordenar os livros por ano de publicação usando Bubble Sort
void ordenarLivros(struct Livro acervo[], int quantidade) {
    printf("\n=== ORDENAR LIVROS POR ANO ===\n");
    
    if (quantidade == 0) {
        printf("Nenhum livro cadastrado no acervo.\n");
        return;
    }
    
    if (quantidade == 1) {
        printf("Apenas um livro cadastrado. Nao ha necessidade de ordenacao.\n");
        return;
    }
    
    struct Livro temp; // Variável temporária para troca
    int trocou; // Flag para verificar se houve troca
    
    // Implementação do algoritmo Bubble Sort
    for (int i = 0; i < quantidade - 1; i++) {
        trocou = 0;
        
        for (int j = 0; j < quantidade - i - 1; j++) {
            // Compara os anos dos livros adjacentes
            if (acervo[j].ano > acervo[j + 1].ano) {
                // Realiza a troca dos livros
                temp = acervo[j];
                acervo[j] = acervo[j + 1];
                acervo[j + 1] = temp;
                trocou = 1;
            }
        }
        
        // Se não houve trocas, o vetor já está ordenado
        if (!trocou) {
            break;
        }
    }
    
    printf("Livros ordenados por ano de publicacao com sucesso!\n");
    printf("Use a opcao 2 do menu para visualizar a nova ordem.\n");
}