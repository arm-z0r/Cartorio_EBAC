#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidas das strings

int registro() //Fun��o respons�vel pelo cadastro no sistema
{
	//cria��o de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de cariaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usus�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //copia os valores das strings
	
	FILE *file; //cria o arquvio
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\nNOME: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);  //le o dado inserido pelo usuario e adciona ao arquivo existente
	
	file = fopen(arquivo,"a"); //adiciona informa��es ao arquivo aberto
	fprintf(file,nome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //le o dado inserido pelo usuario e adciona ao arquivo existente
	
	file = fopen(arquivo,"a"); //adiciona informa��es ao arquivo aberto
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCARGO:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); //le o dado inserido pelo usuario e adciona ao arquivo existente
	
	file =fopen(arquivo, "a"); //adiciona informa��es ao arquivo aberto
	fprintf(file,cargo);
	fprintf(file,"\n");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//cria��o de variaveis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de cariaveis/string
	
	printf("Digite o CPF a ser consultado: ");//coletando informa��o do usus�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	printf("\nEssas s�o as informa��es do usu�rio:\n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");

}

int deletar()
{
		//cria��o de variaveis/string
		char cpf[40];
		//final da cria��o de cariaveis/string
		
		printf ("Digite o CPF do usu�rio a ser deletado: ");//coletando informa��o do usus�rio
		scanf("%s", cpf); //%s refere-se a string
		
		remove(cpf); //fun��o para deletar o arquivo do sistema
		
		FILE *file;
		file = fopen(cpf, "r");
		fclose(file);
				
		if (file== NULL) //condicional caso o arquivo n�o exista no sistema
		{
			printf("Usu�rio n�o se encontra no sistema!.\n");
			system ("pause");
		}

}

int main()
{
	int opcao=0; //Defini��o de vari�veis
	int laco=1;
	
	for (laco=1;laco =1;)
	{
		
		system("cls");	
		
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
		printf("###Cart�rio da EBAC ###\n\n"); //in�cio do menu
    	printf("Escolha a op��o desejada no menu: \n\n");
    	printf("\t1 - Registrar os nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: "); //fim do menu
    
    	scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
    	system("cls"); //responsavel por limpar a tela
    
    	switch(opcao) //in�cio da sele��o
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
			
			case 4:
			printf("Obrigado por usar o sistema.\n");
			return 0;
			break;
				
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
						
		} //fim da sele��o
    
	}
}
