#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaÃ§o em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // bilioteca responsável por cuidar das strings

int registro()
{
    char arquivo[40]; // Criando uma variável que tem espaço para armazenar até 40 caracteres (No caso 39 pois no final teria o \O que seria o encerramento)
    char cpf[40];     // 40 caracteres seria letras. Cada letra contaria como 1 caractere. Mais que 40 letras poderia causar bugs ao sistema, fazendo com que 
    char nome[40];    // caracteres substituam outras partes da memoria de outros locais indevidos
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); // o "%s" está recebendo texto (strings) e guardando na variável cpf com o "&"

    strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings

    FILE *file; // Cria o arquivo. "FILE" uma função propria do *C* 
    file = fopen(arquivo, "w"); // Cria no modo de escrita "w" há outros modos também. 'fopen" abre o arquivo.
    fprintf(file, "CPF: ");
    fprintf(file, cpf); // Salvando o valor da variavel no arquivo // voce pode digitar instantanemente pela função
    fclose(file); // Fecha o arquivo 

    file = fopen(arquivo, "a"); // Se colocar pra abrir o arquivo com "a" ele irá atualizar oque tem dentro
    fprintf(file, ","); // Colocando uma virgula para separar
    fprintf(file, " Nome: ");
    fclose(file); //Fechando o arquivo
    
    printf("Digite o nome a ser cadastrado: "); 
    scanf("%s", nome); // Lê uma string e amazena na varievael nome

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);


    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fprintf(file, " Sobrenome: ");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fprintf(file, " Cargo: ");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s" , cpf); // O "%s" Está recebendo uma string

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Não foi possivel localizar o arquivo\n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int deletar()
{
    char cpf[40];
    printf("Digite o CPF que deseja deletar: ");
    scanf("%s", cpf); // Só lembrando que o scanf(%s) scanf irá armazenar na variável cpf um numero em string "%s"
    remove(cpf); // E logo depois sera deletado aqui.

    FILE *file;
    file = fopen(cpf, "r");
    if(file == NULL)
    {
        printf("Arquivo não se encontra no sistema.\n\n");
        system("pause");
    }
 
}

int main()
{
    int opcao=0;
    int laco=0;
    for( laco = 1; laco = 1;)
    {
        system("cls"); // Utilizado para limpar o sistema

        setlocale(LC_ALL, "Portuguese_Brazil"); // colocalando a localização em pt br

        printf("### Cadastro de Usuários ###\n\n");  
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opções: ");
        
        scanf("%d", &opcao); // o "%d" estão recebendo como entrada um numero inteiro decimal e armazenando na variavel opcao com o operador &

        system("cls");

        switch(opcao) // uma alternatica para IF, para tomar o rumo do programa com base na escolha do usuário
        {
            case 1:
            registro();
            break;

            case 2: 
            consulta();
            break;

            case 3:
            deletar();
            break;

            default:
            printf("Essa opção não está disponivel!\n");
            system("pause");
            break;
        }
    }    
}
