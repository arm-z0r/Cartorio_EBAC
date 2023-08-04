#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidas das strings

int registro() //Função responsável pelo cadastro no sistema
{
	//criação de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de cariaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do ususário
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
	
	file = fopen(arquivo,"a"); //adiciona informações ao arquivo aberto
	fprintf(file,nome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //le o dado inserido pelo usuario e adciona ao arquivo existente
	
	file = fopen(arquivo,"a"); //adiciona informações ao arquivo aberto
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCARGO:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); //le o dado inserido pelo usuario e adciona ao arquivo existente
	
	file =fopen(arquivo, "a"); //adiciona informações ao arquivo aberto
	fprintf(file,cargo);
	fprintf(file,"\n");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//criação de variaveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de cariaveis/string
	
	printf("Digite o CPF a ser consultado: ");//coletando informação do ususário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	printf("\nEssas são as informações do usuário:\n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");

}

int deletar()
{
		//criação de variaveis/string
		char cpf[40];
		//final da criação de cariaveis/string
		
		printf ("Digite o CPF do usuário a ser deletado: ");//coletando informação do ususário
		scanf("%s", cpf); //%s refere-se a string
		
		remove(cpf); //função para deletar o arquivo do sistema
		
		FILE *file;
		file = fopen(cpf, "r");
		fclose(file);
				
		if (file== NULL) //condicional caso o arquivo não exista no sistema
		{
			printf("Usuário não se encontra no sistema!.\n");
			system ("pause");
		}

}

int main()
{
	int opcao=0; //Definição de variáveis
	int laco=1;
	
	for (laco=1;laco =1;)
	{
		
		system("cls");	
		
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
		printf("###Cartório da EBAC ###\n\n"); //início do menu
    	printf("Escolha a opção desejada no menu: \n\n");
    	printf("\t1 - Registrar os nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Opção: "); //fim do menu
    
    	scanf("%d", &opcao); //armazenando a escolha do usuário
    
    	system("cls"); //responsavel por limpar a tela
    
    	switch(opcao) //início da seleção
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
						
		} //fim da seleção
    
	}
}
