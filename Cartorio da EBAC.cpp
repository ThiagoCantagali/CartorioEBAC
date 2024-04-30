#include <stdio.h> //Biblioteca de comunicacao com o usuario
#include <stdlib.h> //Biblioteca de alocacao de espa�a
#include <locale.h> //Biblioteca de alocacao de texto por regiao 
#include <string.h> //Biblioteca responsavel por cuidar das string 

int registro ()
{
	setlocale(LC_ALL, "Portuguese"); // Defini��o da linguagem
	
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

	FILE *file; //criar o arquivo
	file = fopen(arquivo,"w");//criar o arquivo
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // atualizar o arquivo
	fprintf(file,",");// colocar a vrgula
	fclose(file);
	
	printf("Digite o nome cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose (file);
	
	file = fopen(arquivo,"a"); // atualizar o arquivo
	fprintf(file,",");// colocar a vrgula
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a"); // atualizar o arquivo
	fprintf(file,",");// colocar a vrgula
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");
	
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); // Defini��o da linguagem
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf(" \n N�o foi possivel abrir o arquivo! \n\n ");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar ()
{
	setlocale(LC_ALL, "Portuguese"); // Defini��o da linguagem
		
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	if(file == NULL)
	{
		printf("O usu�rio deletado! \n");
		system("pause");

	}
	
	
}


int main ()
	{
	int opcao=0; // definindo a vari�vel
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Defini��o da linguagem
	
		printf("### \t Cart�rio da EBAC \t ### \n\n "); // inicio do menu
		printf("Escolha a op��o desejada \n\n ");
		printf("\t1 - Registra nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n\n");
		printf("Op��o desejada:"); // final do menu
	
		scanf("%d", &opcao);
	
		system("cls");
		
		
		switch(opcao) // inicio da selecao
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
			printf("Essa op��o n�o est� disponivel \n"); 
			system("pause");
			break;// final da selecao 
			
		}

		
	}
}
	
