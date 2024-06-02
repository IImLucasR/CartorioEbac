#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espaço em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // bilioteca respons�vel por cuidar das strings

int registro()
{
    char arquivo[40]; // Criando uma vari�vel que tem espa�o para armazenar at� 40 caracteres (No caso 39 pois no final teria o \O que seria o encerramento)
    char cpf[40];     // 40 caracteres seria letras. Cada letra contaria como 1 caractere. Mais que 40 letras poderia causar bugs ao sistema, fazendo com que 
    char nome[40];    // caracteres substituam outras partes da memoria de outros locais indevidos
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); // o "%s" est� recebendo texto (strings) e guardando na vari�vel cpf com o "&"

    strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings

    FILE *file; // Cria o arquivo. "FILE" uma fun��o propria do *C* 
    file = fopen(arquivo, "w"); // Cria no modo de escrita "w" h� outros modos tamb�m. 'fopen" abre o arquivo.
    fprintf(file, "CPF: ");
    fprintf(file, cpf); // Salvando o valor da variavel no arquivo // voce pode digitar instantanemente pela fun��o
    fclose(file); // Fecha o arquivo 

    file = fopen(arquivo, "a"); // Se colocar pra abrir o arquivo com "a" ele ir� atualizar oque tem dentro
    fprintf(file, ","); // Colocando uma virgula para separar
    fprintf(file, " Nome: ");
    fclose(file); //Fechando o arquivo
    
    printf("Digite o nome a ser cadastrado: "); 
    scanf("%s", nome); // L� uma string e amazena na varievael nome

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
    scanf("%s" , cpf); // O "%s" Est� recebendo uma string

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("N�o foi possivel localizar o arquivo\n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas s�o as informa��es do usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int deletar()
{
    char cpf[40];
    printf("Digite o CPF que deseja deletar: ");
    scanf("%s", cpf); // S� lembrando que o scanf(%s) scanf ir� armazenar na vari�vel cpf um numero em string "%s"
    remove(cpf); // E logo depois sera deletado aqui.

    FILE *file;
    file = fopen(cpf, "r");
    if(file == NULL)
    {
        printf("Arquivo n�o se encontra no sistema.\n\n");
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

        setlocale(LC_ALL, "Portuguese_Brazil"); // colocalando a localiza��o em pt br

        printf("### Cadastro de Usu�rios ###\n\n");  
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Op��es: ");
        
        scanf("%d", &opcao); // o "%d" est�o recebendo como entrada um numero inteiro decimal e armazenando na variavel opcao com o operador &

        system("cls");

        switch(opcao) // uma alternatica para IF, para tomar o rumo do programa com base na escolha do usu�rio
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
            printf("Essa op��o n�o est� disponivel!\n");
            system("pause");
            break;
        }
    }    
}
