DESCRIÇÃO DA ATIVIDADE

Imagine que você foi contratado para desenvolver um sistema de gerenciamento de livros para uma pequena biblioteca. O sistema deve permitir que o bibliotecário cadastre, pesquise, ordene e gerencie o acervo de 20 livros. Esta tarefa exigirá a aplicação de diversos conceitos fundamentais da linguagem C.

Conceitos a serem aplicados:
Estruturas (Structs): Para armazenar os dados de cada livro (código, título, autor, área, ano e editora).
Constantes: Para definir o tamanho máximo do acervo de 20 livros.
Vetores: Para criar um acervo com capacidade para 20 livros, utilizando um vetor de structs.
Strings: Para manipular os campos de texto como título, autor, área e editora.
Funções: Para modularizar o código, separando a lógica de cada funcionalidade (cadastrar, imprimir, pesquisar, ordenar).
Estruturas de Repetição: Para percorrer o vetor de livros durante o cadastro, a impressão e a ordenação.
Estruturas Condicionais: Para criar um menu de opções e tomar decisões lógicas, como verificar se um livro foi encontrado na pesquisa.
Entrada e Saída de Dados: Para interagir com o usuário, recebendo dados do teclado e exibindo resultados na tela.
Funções Intrínsecas: Para operações de manipulação de strings (por exemplo, strcmp para comparar nomes) e outras utilidades.
Arquivos (Opcional - desafio extra): Para armazenar o acervo de forma persistente, lendo os dados de um arquivo ao iniciar o programa e salvando-os ao encerrar.

Dado o contexto, seguem as etapas que precisarão cumprir na atividade:

Etapa 1: Planejamento e Estrutura do Código - Antes de começar a codificar, planeje a estrutura do seu programa.

Defina a struct: Crie uma estrutura chamada Livro com os campos necessários:
int codigo;
char titulo[50];
char autor[30];
char area[30];
int ano;
char editora[30];

Declare as constantes e variáveis: Use #define para definir uma constante para o tamanho do acervo (TAMANHO_ACERVO 20). Na função main, declare um vetor dessa struct (struct Livro acervo[TAMANHO_ACERVO]) e outras variáveis auxiliares.

Desenhe o menu: Crie um menu principal para o usuário escolher entre as seguintes opções:
1 - Cadastrar livros
2 - Imprimir todos os livros
3 - Pesquisar livro por código
4 - Ordenar livros por ano de publicação
5 - Sair do programa

Esboce as funções: Crie as assinaturas das funções que você precisará. Por exemplo:
void cadastrarLivros(struct Livro acervo[], int tamanho);
void imprimirLivros(struct Livro acervo[], int tamanho);
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca);
void ordenarLivros(struct Livro acervo[], int tamanho);
 


Etapa 2: Implementação do Código - Agora, implemente cada funcionalidade em seu código.

Função main: use um laço de repetição (do-while ou while) e uma estrutura de seleção (switch-case ou if-else) para exibir o menu e chamar a função correspondente à opção do usuário.
Função cadastrarLivros: use um laço for para percorrer o vetor de structs. Dentro do laço, use printf e scanf para solicitar e ler os dados de cada livro. Lembre-se de usar fflush(stdin) após cada scanf para limpar o buffer do teclado.
Função imprimirLivros: percorra o vetor com um laço for e use printf para exibir os dados de cada livro.
Função pesquisarLivro: solicite ao usuário o código do livro a ser pesquisado. Percorra o vetor com um laço while. Se o código for encontrado, exiba as informações do livro. Se não, mostre uma mensagem de "não encontrado".
Função ordenarLivros: implemente o método de ordenação da bolha (BubbleSort) para ordenar os livros por ano de publicação, usando laços for aninhados e uma variável temporária para a troca.
Documente o código: Adicione comentários (// ou /* */) em todas as partes importantes: o que cada função faz, o que cada variável armazena e por que certas decisões de lógica foram tomadas
