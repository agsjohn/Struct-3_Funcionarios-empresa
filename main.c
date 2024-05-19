#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int codigo;
  char nome[50];
  char endereco[50];
  int cpf;
  char data[15];
  int salario[12];
  int salario_total;
} modelo;

main(){
  modelo *funcionarios ,*aux1;
  int novotamanho, tamanho, escolha, x, cont, cont2, remover, aux, cod, comp, y;
  system("clear");
  printf("Digite o número iniciais de automóveis: ");
  scanf("%i", &tamanho);
  getchar();
  funcionarios = malloc(tamanho*sizeof(modelo));
  for(x = 0; x < tamanho; x++){
    printf("\nDigite o código funcionário: ");
    scanf("%i", &funcionarios[x].codigo);
    getchar();
    printf("Digite o nome do funcionário: ");
    gets(funcionarios[x].nome);
    printf("Digite o endereço do funcionário: ");
    gets(funcionarios[x].endereco);
    printf("Digite o CPF do funcionário: ");
    scanf("%i", &funcionarios[x].cpf);
    getchar();
    printf("Digite a data de nascimento: ");
    gets(funcionarios[x].data);
    funcionarios[x].salario_total = 0;
  }
  system("clear");
  do{
    printf("Escolha uma das opções\n[0] - Registrar funcionário\n[1] - Remover funcionário\n[2] - Mostrar funcionarios\n[3] - Buscar funcionário específico\n[4] - Alterar dados\n[5] - Sair do programa\n");
    scanf("%i", &escolha);
    getchar();
    switch(escolha){
      case 0:{
        novotamanho = tamanho + 1;
        funcionarios = realloc(funcionarios, novotamanho*sizeof(modelo));
        system("clear");
        printf("Digite o código funcionário: ");
        scanf("%i", &funcionarios[x].codigo);
        getchar();
        printf("Digite o nome do funcionário: ");
        gets(funcionarios[tamanho].nome);
        printf("Digite o endereço do funcionário: ");
        gets(funcionarios[tamanho].endereco);
        printf("Digite o CPF do funcionário: ");
        scanf("%i", &funcionarios[x].cpf);
        getchar();
        printf("Digite a data de nascimento: ");
        gets(funcionarios[tamanho].data);
        funcionarios[tamanho].salario_total = 0;
        tamanho = novotamanho;
        printf("\n");
      } //adicionar
      break;
      case 1:{ 
        cont = 0;
        printf("\nDigite a posição absoluta do funcionário que deseja deletar: ");
        scanf("%i", &remover);
        getchar();
        if(remover >= tamanho){
          printf("Posição inválida");
          getchar();
          system("clear");
        } else{
          novotamanho = tamanho - 1;
          aux1 = malloc(novotamanho*sizeof(modelo));
          for(x = 0; x < tamanho; x++){
            if(remover != x){
              aux1[cont].codigo = funcionarios[x].codigo;
              strcpy(aux1[cont].nome, funcionarios[x].nome);
              strcpy(aux1[cont].endereco, funcionarios[x].endereco);
              aux1[cont].cpf = funcionarios[x].cpf;
              strcpy(aux1[cont].data, funcionarios[x].data);
              for(y = 0; y < 12; y++){
                aux1[cont].salario[y] = funcionarios[x].salario[y];
              }
              aux1[cont].salario_total = funcionarios[x].salario_total;
              cont++;
            }
          }
          free(funcionarios);
          funcionarios = aux1;
          tamanho--;
          system("clear");
        }
      } //remover
      break;
      case 2:{
        system("clear");
        printf("//--Funcionários--// \n");
        for(x = 0; x < tamanho; x++){
          comp = strcmp(funcionarios[x].data, "");
          if(comp != 0){
            printf("Funcionário nº %i\n", x + 1);
            printf("Código: %i\nNome: %s\nEndereço: %s\nCPF: %i\nData de nascimento: %s\n", funcionarios[x].codigo, funcionarios[x].nome, funcionarios[x].endereco, funcionarios[x].cpf, funcionarios[x].data);
            printf("--------\n");
          }
        }
        printf("\n");
      } //mostrar
      break;
      case 3:{
        cont = 0;
        printf("\nDigite o código do funcionário: ");
        scanf("%i", &cod);
        getchar();
        for(x = 0; x < tamanho; x++){
          if(funcionarios[x].codigo == cod){
            cont++;
          }
        }
        if(cont > 0){
          printf("Deseja adicionar o salário do funcionário ou apenas visualizar seus dados?\n[0] - adicionar salário\n[1] - visualizar dados\n");
          scanf("%i", &escolha);
          getchar();
          if(escolha == 0){
            for(x = 0; x < tamanho; x++){
              if(funcionarios[x].codigo == cod){
                aux = x;
                x = tamanho;
              }
            }
            printf("\nFuncionário nº %i\n", x + 1);
            printf("Nome: %s\nEndereço: %s\nCPF: %i\nData de nascimento: %s\n", funcionarios[aux].nome, funcionarios[aux].endereco, funcionarios[aux].cpf, funcionarios[aux].data);
            funcionarios[aux].salario_total = 0;
            for(y = 0; y < 12; y++){
              printf("Digite o salário do funcionário no %iº mês: ", y + 1);
              scanf("%i", &funcionarios[aux].salario[y]);
              getchar();
              funcionarios[aux].salario_total = funcionarios[aux].salario_total + funcionarios[aux].salario[y];
            }
            cont2++;
            printf("\n");
            printf("Adicionado com sucesso");
            getchar();
            system("clear");
          } else {
            cont2 = 0;
            for(x = 0; x < tamanho; x++){
              if(funcionarios[x].codigo == cod){
                cont2++;
                if(funcionarios[x].salario_total == 0){
                  printf("\n\nFuncionário nº %i\n", x + 1);
                  printf("Código: %i\nNome: %s\nEndereço: %s\nCPF: %i\nData de nascimento: %s\n\n", funcionarios[x].codigo, funcionarios[x].nome, funcionarios[x].endereco, funcionarios[x].cpf, funcionarios[x].data);
                } else {
                  printf("\n\nFuncionário nº %i\n", x + 1);
                  printf("Código: %i\nNome: %s\nEndereço: %s\nCPF: %i\nData de nascimento: %s\n", funcionarios[x].codigo, funcionarios[x].nome, funcionarios[x].endereco, funcionarios[x].cpf, funcionarios[x].data);
                  for(y = 0; y < 12; y++){
                    printf("Salário mês %i: %i\n", y + 1, funcionarios[x].salario[y]);
                  }
                  printf("Salário total: %i\n\n", funcionarios[x].salario_total);
                }
              }
            }
          }
        } else {
          printf("Codigo inválido");
          getchar();
          system("clear");
        }
      } //procurar
      break;
      case 4:{
        printf("\nDigite a posição absoluta do funcionário que deseja alterar uma informação: ");
        scanf("%i", &remover);
        getchar();
        if(remover >= tamanho){
          printf("\nPosição inválida");
          getchar();
        } else{
          printf("\nEscolha que informação deseja alterar: \n[0] - Codigo\n[1] - Nome\n[2] - Endereco\n[3] - Cpf\n[4] - Data\n[5] - Salario\n");
          scanf("%i", &x);
          getchar();
          printf("\n");
          switch(x){
            case 0:{
              printf("Codigo atual: %i\nNovo codigo: ", funcionarios[remover].codigo);
              scanf("%i", &funcionarios[remover].codigo);
              getchar();
              printf("\nAtualizado com sucesso");
              getchar();
            }
            break;
            case 1:{
              printf("Nome atual: %s\nNovo nome: ", funcionarios[remover].nome);
              gets(funcionarios[remover].nome);
              printf("\nAtualizado com sucesso");
              getchar();
            }
            break;
            case 2:{
              printf("Endereco atual: %s\nNovo endereco: ", funcionarios[remover].endereco);
              gets(funcionarios[remover].endereco);
              printf("\nAtualizado com sucesso");
              getchar();
            }
            break;
            case 3:{
              printf("Cpf atual: %i\nNovo cpf: ", funcionarios[remover].cpf);
              scanf("%d", &funcionarios[remover].cpf);
              getchar();
              printf("\nAtualizado com sucesso");
              getchar();
            }
            break;
            case 4:{
              printf("Data atual: %s\nNova data: ", funcionarios[remover].data);
              gets(funcionarios[remover].data);
              printf("\nAtualizado com sucesso");
              getchar();
            }
            break;
            case 5:{
              funcionarios[remover].salario_total = 0;
              for(y = 0; y < 12; y++){
                printf("Salario atual mes %i: %i\nNovo salario: ", y + 1, funcionarios[remover].salario[y]);
                scanf("%i", &funcionarios[remover].salario[y]);
                getchar();
                funcionarios[remover].salario_total = funcionarios[remover].salario_total + funcionarios[remover].salario[y];
              }
              printf("\nAtualizado com sucesso");
              getchar();
            }
            break;
          }
        }
        system("clear");
      } //alterar
      break;
      case 5:
        printf("\nFinalizando programa\n");
        getchar();
      break;
      default:
        printf("\nEscolha inválida\n\n");
    }
  }while(escolha != 5);
}