#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro () //Função responsável por cadastrar os usuários no sistema
{
   //início da criação de variáveis/strings
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //final da criação de variáveis/strings

   printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
   scanf("%s", cpf); //%s refere-se a string

   strcpy(arquivo, cpf); //Responsável por copiar os valores das string

   FILE *file; //Cria o arquivo
   file = fopen(arquivo, "w"); //Cria o arquivo e o w significa escrever
   fprintf(file, "\nCPF: ");
   fprintf(file,cpf); //Salvo o valor da variável
   fclose(file); //Fecha o arquivo

   file = fopen(arquivo, "a"); //Atualizar informação
   fprintf(file, "\nNOME: ");
   fclose(file);

   printf("Digite o nome a ser cadastrado: ");
   scanf("%s",nome);

   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);

   file = fopen(arquivo, "a"); //Atualizar informação
   fprintf(file, "\nSOBRENOME: ");
   fclose(file);

   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);

   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);

   file = fopen(arquivo, "a"); //Atualizar informação
   fprintf(file, "\nCARGO: ");
   fclose(file);

   printf("Digite o cargo a ser cadastrado: ");
   scanf("%s",cargo);

   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);

   system("read"); //pausa para o usuário ler a tela


}

int consulta ()
{
   setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

   char cpf[40];
   char conteudo[200];
   char *token; 

   printf("Digite o CPF a ser consultado: ");
   scanf("%s",cpf);

   FILE *file;
   file = fopen(cpf,"r");

   if(file == NULL)
   {
      printf("Não localizado! \n"); 
   }

   printf("Essas são as informações do usuário: \n");

   while(fgets(conteudo, 200, file) != NULL)
   {   
      printf("%s", conteudo);
      printf("\n");
   }

   system("read");
   fclose(file);

}


int deletar ()
{
   char cpf[40];
   
   printf("Digite o CPF do usuário a ser deletado: ");
   scanf("%s",cpf);

   FILE *file;
   file = fopen(cpf, "r");

   if(file == NULL)
   {
      printf("O CPF do usuário não se encontra no sistema. \n");
      system("read");
      fclose(file);
   }
   else 
   {
      fclose(file);
      remove(cpf);
      printf("Usuário deletado com sucesso. \n");
      system("read");
   }

}

int main ()
{
    int opcao=0; //definindo as variáveis
    int laco=1;
    char senhadigitada[]="a";
    int comparacao;

    printf("### Cartório da EBAC ###\n\n");
    printf("Login de administrador.\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);  

    comparacao = strcmp(senhadigitada, "broccoli");  
    if(comparacao == 0)
    {

      system ("clear");
      for (laco=1;laco=1;)
      { 

       system("clear");
 
       setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

       printf("### Cartório da EBAC ###\n\n"); //início do menu
       printf("Escolha a opção desejada do menu:\n\n");
       printf("\t1 - Registrar nomes\n");
       printf("\t2 - Consultar nomes\n");
       printf("\t3 - Deletar nomes\n"); 
       printf("\t4 - Sair do sistema\n\n");
       printf("Opção:"); //fim do menu

       scanf("%d", &opcao); //armazenando a escolha do usuário

       system("clear"); //responsável por limpar a tela

       switch(opcao) //inicio da seleção do menu
       {
          case 1:
          registro(); //chamada de funções
          break;

          case 2:
          consulta();
          break;

          case 3:
          deletar();
          break;

          case 4:
          printf("Obrigado por utilizar o sistema!\n");
          return 0;
          break;

          default:
          printf("Opção indisponível!\n");
          system("read");
          break;
       } //fim da seleção do menu

      }   
    }

else
   printf("Senha incorreta!"); 

}