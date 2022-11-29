#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define x 100 //Constante
void menu();                      //funcao que chama o menu principal
void sair();                      //funcao para saida do programa
void controleVenda();             //funcao do menu de vendas
void controleProduto();           //menu do control de produtos
void menu2();                     //Funcao do menu de entrada
void sobre();                     //funcao de apresentae-ao dos academicos
void controlePessoa();            //Menu controle de pessoas
void bemvindo();                   //funcao de abertura do programa
void loginsenha();                 //funcao de login e senha
int ProdutoExiste(int cod);       //Fun�ao verifica se o produto esta no banco de dados
int PessoaExiste(int cod);        //Fun�ao verifica se o funcionario esta no banco de dados
int compare (const void * a, const void * b);
//definindo estruturas para armazenamento de pessoas, produtos, e registro de vendas
typedef struct pessoas{
    int codigo;
    char nome[20],sobrenome[20];
    float salario;
};
typedef struct produtos{
    int codigo,quantidade;
    float pcompra,pvenda;
    char descricao[200],tamanho[3];
};
typedef struct vendas{
    int lista;
    double total;
};
     struct pessoas pes[x];
     struct produtos pro[x];
     int QtdProdCad = 2;
     int quantidade=x,qnt=0,cod=0,codProduto=0,codCliente=0,codPessoa=0;
     float valor,total=0,saldo=0;
//BLOCO PRINCIPAL, entrada das pessoas e produtos padroes
int main(){
    setlocale(LC_ALL, "Portuguese");
//funcionarios padrao
    pes[0].codigo=15;
    strcpy (pes[0].nome,"Vinicius");
    strcpy (pes[0].sobrenome,"Silva");
    pes[0].salario=800;
    pes[1].codigo=20;
    strcpy (pes[1].nome,"Luiz");
    strcpy (pes[1].sobrenome,"santos");
    pes[1].salario=900;
    pes[2].codigo=10;
    strcpy (pes[2].nome,"Julia");
    strcpy (pes[2].sobrenome,"Oliveira");
    pes[2].salario=600;
    pes[3].codigo=5;
    strcpy (pes[3].nome,"Michael");
    strcpy (pes[3].sobrenome,"Pereira");
    pes[3].salario=700;
//camiseta padrao
    pro[97].codigo=15;
    strcpy (pro[97].descricao,"camiseta");
    pro[97].quantidade=20;
    pro[97].pvenda=1;
    pro[97].pcompra=0.5;
    strcpy (pro[97].tamanho,"p");
    pro[98].codigo=10;
    strcpy (pro[98].descricao,"camiseta");
    pro[98].quantidade=30;
    pro[98].pvenda=2;
    pro[98].pcompra=0.9;
    strcpy (pro[98].tamanho,"M");
    pro[99].codigo=20;
    strcpy (pro[99].descricao,"camiseta");
    pro[99].quantidade=50;
    pro[99].pvenda=3;
    pro[99].pcompra=1;
    strcpy (pro[99].tamanho,"g");
    system("color 1F");
    bemvindo();
}
//funcao do entrada do menu principal
void menu(){
     int op;
     system("cls");
     printf("\n Menu Principal:");
     printf("\n 1 - Gerenciamento de Vendas");
     printf("\n 2 - Gerenciamento de Funcionarios");
     printf("\n 3 - Gerenciamento de Produtos");
     printf("\n 4 - Voltar\n\n ");
     scanf("%d",&op);
     switch(op){
         case 1: {                                        //opcao 1 controle de vendas
            system("cls");
            controleVenda();
            getch();
            menu();
        break;
         }
         case 2: {                                        //opcao 2 controle de pessoas
            controlePessoa();
            getch();
            menu();
        break;
         }
         case 3: {                                        //opcao 3 controle de pessoa
            controleProduto();
            getch();
            menu();
        break;
          }
         case 4: {                                      //opcao 4, voltar para o menu de entrada
            menu2();
            getch();
            menu();
        break;
            }
            default: {                                     //caso o usuario digite uma opcao nao valida  retonar ao menu, e avisa o usuario
               printf("Opcao Invalida");
               getch();
               menu();
}}}
//funcao do controle de vendas
void controleVenda(){
     system("cls");
     int op,quant;
     char cond;
    printf("\n Controle de venda: ");
    printf("\n 1 - Cadastrar nova venda");
    printf("\n 2 - Saldo do dia");
    printf("\n 3 - Voltar\n\n ");
    scanf("%d",&op);
     switch(op){
         case 1: {                                         //funcao para efetuar venda,  faz os caucolos e mais informa�oes para ajudar o usuario
              int i=0;
              do{
                system("cls");
                printf("Informe o codigo do produto: ");
                scanf("%d",&cod);
                 if (ProdutoExiste(cod) != 1){ //verifica se o produto esta cadastrado
                     printf("Produto inexistente !");
                     getch();
                     controleVenda();
            }else{
               printf("\n Produto: %s\n\n Valor Unitario %.2f\n\n Quantidade em estoque %d\n\n ",pro[codProduto].descricao,pro[codProduto].pvenda,pro[codProduto].quantidade);
               printf("Informe a quantidade de %s a ser vendido: ",pro[codProduto].descricao);
               scanf("%d",&quant);
            if(quant<pro[codProduto].quantidade){
                valor=quant*pro[codProduto].pvenda;
                total=total+valor;
                saldo=saldo+total;
                pro[cod].quantidade=pro[codProduto].quantidade-quant;
            }else{
                printf("Quantidade insuficiente em estoque ");
                getch();
                controleVenda();
}}
                printf("\n Total:%.2f\n ",total);
                printf("\n Finalizar a venda(s/n)?:  ");
                scanf("%s",&cond);
}
            while(cond!='s');
                printf("\n Total a pagar: R$%.2f",total);
                total=0;
                getch();
                controleVenda();
            break;
}
            case 2:{                                                                        //opcao 2, imprime o saldo do dia
                 printf("\n Total de vendas : R$%.2f",saldo);
                 getch();
                 controleVenda();
                 break;
}
            case 3:{                                                                        //opcao 3, volta para o menu
                 menu();
                 break;
}
            default: {                                                                      // informa o cliente quando ele digita um valor que nao coresponde ao menu
                printf("Opcao Invalida");
                getch();
                controleVenda();
}}}
 //funcao de saida do programa
void sair(){
   system("cls");
   printf("\n\n             Obrigado por utilizar nosso sistema \n\n");
   getch();
   exit (0);
}
//Menu de entrada
void menu2(){
     int op;
     system("cls");
     printf("\n Menu Principal:");
     printf("\n 1  -  Entrar");
     printf("\n 2  -  Sobre");
     printf("\n 3  -  Sair\n\n ");
     scanf("%d",&op);
switch(op){
    case 1: {
        menu();                          //opcao 1, abre o menu principal
        getch();
        menu2();
    break;}
    case 2: {                            //opcao 2, abre as informacoes sobre os academicos
        sobre();
        getch();
        menu2();
    break;}
    case 3: {                          //opcao de saida do programa
        sair();
        getch();
    break;}
    default: {                          //informa quando o usuario digita uma opcao invalida
        printf("Opcao Invalida");
        getch();
        menu2();
}}}
//funcao de apresentasao do progeto
void sobre(){
      system("cls");
        printf("\n Sobre o Programa:\n\n Desenvolvemos este software para  ajudar lojas e estabelecimentos \n a automatizarem seus processos de rotina, organizar e ter controle \n de seu estoque atrav�s de um sistema ..\n\n");
        printf("\n Desenvolvedores :\n\n Julia Caroline da Silva           RA: N9284B4\n\n Lucas Moreira da Silva            RA: G5052A8\n\n Luiz Henrique Matos Oliveira      RA: G4017C0\n\n Vinicius Santos da Silva          RA: N7950E0");
}
// funcao login e senha
void loginsenha(){
    char c;
    char login[15] = "lucas"; //Tem que ter mais espa�o que a string. Pelo menos 1 a mais que a palavra.
    char login1[15]; //Pode ser do mesmo tamanho que o login
    char senha[15] = "123";
    char senha1[15];
    int i = 0,verifica_senha= 0;
while(verifica_senha == 0){
    FILE *arq_login;
    arq_login =fopen("arquivo_login.txt","a+");
        if(arq_login == NULL){
            printf("erro na abertura do arquivo");
        }else{
            printf("                       LOGIN : ");
            scanf("%s",login1); //String se l� com %s
            fprintf(arq_login,"                       LOGIN : ");
            fprintf(arq_login,"%s",login1);
            printf("\n                       SENHA : ");
            fprintf(arq_login,"\n                       SENHA : ");
        while((c=getch())!=13){
            senha1[i]=c;
            i++;
            printf("*");
}
            senha1[i]='\0';
            i=0;
            fprintf(arq_login,"%s",senha1);
            fclose(arq_login);
            system("cls");
        if (strcmp(login, login1) == 0 && strcmp(senha,senha1)==0){ // comparando 2 strings. Se for igual a 0 � porque as duas s�o iguais.
            menu2();
	        verifica_senha =1;
	        }else {
                printf("\n\n                      SENHA INVALIDA TENTE NOVAMENTE!!!\n\n\n");
}}}}
//funcao de entrada do programa
void bemvindo(){
     system("cls");
     printf("\n\n\n");
     printf("                            BEM VINDO A TECCOUNTRY\n\n\n\n\n\n");
     loginsenha();
}
//funcao do menu de controle de pessoas
void controlePessoa(){
     int op;
     system("cls");
        printf("\n Controle de funcionarios:");
        printf("\n 1  -  Cadastro de funcionarios");
        printf("\n 2  -  Consulta de funcionarios");
        printf("\n 3  -  Alterar cadastro de funcionarios");
        printf("\n 4  -  Excluir cadastro de funcionarios");
        printf("\n 5  -  Voltar\n\n ");
        scanf("%d",&op);
        switch(op){
            case 1:{                              //opcao 1, para o usuario poder fazer cadastro de pessoas
            char cond;
            do{
                printf("\n Informe o codigo do funcionario ");
                scanf("%d",&cod);
            if (PessoaExiste(cod) == 1){ //verifica se o pessoa esta cadastrado
                printf(" Funcionario ja cadastrado !");
                getch();
                controlePessoa();
            }else{
                while(pes[codPessoa].codigo>0){
                        codPessoa=codPessoa+1;
}
                        pes[codPessoa].codigo=cod;
                        printf("\n Informe o nome :  ");
                        fflush(stdin);
                        gets(pes[codPessoa].nome);
                        printf("\n Informe o sobrenome : ");
                        fflush(stdin);
                        gets(pes[codPessoa].sobrenome);
                        printf("\n Informe o Salario : ");
                        scanf("%f",&pes[codPessoa].salario);
}
                        printf("\n Deseja cadastrar outro funcionario:(s/n) ");
                        scanf("%s",&cond);
}
                while(cond!='n');
                        controlePessoa();
                    break;
}
                    case 2:{                                 //menu de consulta de funcionarios
                        system("cls");
                        int opcao;
                            printf("\n  1 -  Consultar por codigo\n ");
                            printf(" 2 -  Exibir todos os funcionarios\n ");
                            printf(" 3 -  Ordenar por codigo\n ");
                            printf(" 4 -  voltar\n\n  ");
                            scanf("%d",&opcao);
                        switch (opcao){
                            case 1:{
                            int cod;
                                printf("\n Informe o codigo da pessoa :  ");
                                scanf("%d",&cod);
                            for(int i=0;i<x;i++){
                                if(pes[i].codigo==cod){
                                    printf("\n Codigo : %d\n Nome : %s\n ",pes[i].codigo, pes[i].nome);
                                    printf("Sobrenome : %s\n Salario : %.2f\n\n ", pes[i].sobrenome, pes[i].salario);
}}
                                    getch();
                                    controlePessoa();
                            break;
}
                            case 2:{         //exibe todos os funcionarios na ordem da posisao dele
                                system("cls");
                                    for(int i=0;i<x;i++){
                                        if(pes[i].codigo > 0){
                                            FILE *arq_funcionarios;
                                            arq_funcionarios =fopen("arquivo_funcionarios.txt","a+");
                                            if(arq_funcionarios == NULL){
                                                printf("erro na abertura do arquivo");
                                            }else{
                                                printf ("\n Codigo : %d\n Nome : %s\n ",pes[i].codigo, pes[i].nome);
                                                printf ("Sobrenome : %s\n Salario : %.2f\n\n ", pes[i].sobrenome, pes[i].salario);
                                                fprintf(arq_funcionarios,"\n Codigo : %d\n Nome : %s\n ",pes[i].codigo, pes[i].nome);
                                                fprintf (arq_funcionarios,"Sobrenome : %s\n Salario : %.2f\n\n ", pes[i].sobrenome, pes[i].salario);
                                            fclose(arq_funcionarios);
}}}}
                                            getch();
                                            controlePessoa();
                            break;
                            case 3:{                                       //opcao 3, imprime os funcionarios na ordem crecente do codigo
                                int i , j , valor,c,gap = 1;
                                char valor1[20],valor2[50];
                                float valor3;
                            do {
                                gap = 3*gap+1;
                            } while(gap < x);
                            do {
                                gap /= 3;
                                    for(i = gap; i < x; i++) {
                                    valor =pes[i].codigo;
                                    strcpy(valor1, pes[i].nome);
                                    strcpy(valor2, pes[i].sobrenome);
                                    valor3 =pes[i].salario;
                                    j = i - gap;
                            while (j >= 0 && valor < pes[j].codigo) {
                                    pes[j + gap].codigo = pes[j].codigo;
                                    strcpy(pes[j + gap].nome,pes[j].nome);
                                    strcpy(pes[j + gap].sobrenome,pes[j].sobrenome);
                                    pes[j + gap].salario = pes[j].salario;
                                    j -= gap;
}
                                    pes[j + gap].codigo = valor;
                                    strcpy(pes[j + gap].nome, valor1);
                                    strcpy(pes[j + gap].sobrenome, valor2);
                                    pes[j + gap].salario = valor3;
}
                                } while ( gap > 1);
                                    system ("cls");
                                    printf ("\n Codigo\t\tNome\t\tSobrenome\t\tSalario\n ");
                                    for (c=0;c<x;c++){
                                        if (pes[c].salario > 0)
                                            printf ("%d\t\t%s\t\t%s\t\tR$ - %.2f\n ", pes[c].codigo,pes[c].nome,pes[c].sobrenome,pes[c].salario);
}
                                            printf ("\n\n");
                                            getch();
                                            controlePessoa();
                                        break;
                                                }
                            case 4:{                                                                 //opcao 4, volta para o menu do controle de produtos
                                getch();
                                controlePessoa();
                            break;
}}}
                            case 3:{                                                                             //opcao 3, funcao para alterar os dados dos funcionarios
                            char cond;
                            do{
                                printf("\n\n  Informe o codigo do funcionario a ser alterado : ");
                                scanf("%d",&cod);
                            if (PessoaExiste(cod) != 1){
                                printf("Funcionario inexistente !\n");
                                getch();
                                controlePessoa();
}
                            else{
                                printf("Nome : %s\n ",pes[codPessoa].nome);
                                printf("Sobrenome : %s\n ",pes[codPessoa].sobrenome);
                                printf("Salario : %.2f\n ",pes[codPessoa].salario);
                                printf("\n Informe o novo codigo do funcionario : ");
                                scanf("%d",&pes[codPessoa].codigo);
                                printf("\n Informe o novo nome : ");
                                fflush(stdin);
                                gets(pes[codPessoa].nome);
                                printf("\n Informe o novo sobrenome : ");
                                fflush(stdin);
                                gets(pes[codPessoa].sobrenome);
                                printf("\n Informe o novo Salario : ");
                                scanf("%f",&pes[codPessoa].salario);
                                printf("\n Deseja alterar outro funcionario(s/n)?  ");
                                scanf("%s",&cond);
}}
                                while(cond!='n');
                                controlePessoa();
                            break;
}
                            case 4:{                                                                             //opcao 4, o usuario informa o codigo do funcionario, e confirma a exclusao do mesmo
                                char cond,resp;
                            do{
                                printf("\n Informe o codigo do funcionario a ser excluido : ");
                                scanf("%d",&cod);
                            if (PessoaExiste(cod) != 1){ //verifica se o pessoa esta cadastrado
                                printf(" Funcio inexistente !");
                                getch();
                                controlePessoa();
                            }else{
                                printf("\n Nome : %s\n ",pes[codPessoa].nome);
                                printf("Sobrenome : %s\n ",pes[codPessoa].sobrenome);
                                printf("Salario : %f\n ",pes[codPessoa].salario);
                                printf("\n Deseja realmente excluir este cadastro(s/n)\n ");
                                scanf("%s",&resp);
}
                            if(resp='s'){
                                pes[codPessoa].codigo=0;
                                strcpy (pes[codPessoa].nome,"");
                                strcpy (pes[codPessoa].sobrenome,"");
                                pes[codPessoa].salario=0;;
}
                                printf("\n Deseja excluir outro funcionario ? (s/n)\n ");
                                scanf("%s",&cond);
}
                            while(cond!='n');
                                controlePessoa();
                            break;
}
                            case 5: {                                                                                //opcao 5, volta para o menu principal
                                menu();
                            break;
}
                            default: {
                                printf(" Opcao Invalida");
                                getch();
                                controlePessoa();
}}}
//Controle de produto
void controleProduto(){
                     int op;
                     system("cls");
                     printf("\n Controle de produtos : ");
                     printf("\n 1 - Cadastro de produtos");
                     printf("\n 2 - Consulta de produto");
                     printf("\n 3 - Listar Produtos");
                     printf("\n 4 - Alterar cadastro de produto");
                     printf("\n 5 - Excluir cadastro de produto");
                     printf("\n 6 - Voltar\n\n ");
                     scanf("%d",&op);
                     switch(op){
                        case 1:{//Cadastro de produto
                            char cond;
                        do{
                            printf("\n Informe o codigo do produto : ");
                            scanf("%d",&cod);
                        if (ProdutoExiste(cod) == 1){ //verifica se o produto esta cadastrado
                            printf(" Produto ja castrado !");
                            getch();
                            controleProduto();
                       }else{
                            while(pro[codProduto].codigo>0){
                                codProduto=codProduto+1;
}
                                pro[codProduto].codigo=cod;
                                printf("\n Informe o nome do produto : ");
                                fflush(stdin);
                                gets(pro[codProduto].descricao);
                                printf("\n Informe a quantidade recebida : ");
                                scanf("%d",&pro[codProduto].quantidade);
                                printf("\n Informe o Valor de Compra : ");
                                scanf("%f",&pro[codProduto].pcompra);
                                printf("\n Informe o Valor de Venda : ");
                                scanf("%f",&pro[codProduto].pvenda);
                                printf("\n Informe o tamanho do produto : ");
                                fflush(stdin);
                                gets(pro[codProduto].tamanho);
}
                                printf("\n Deseja cadastrar outro produto:(s/n)? ");
                                scanf("%s",&cond);
}
                            while(cond!='n');
                                controleProduto();
                            break;
}
                        case 2:{//Consultar o cadastro de produto
                            system("cls");
                            int opcao;
                                printf(" 1 - Consultar por codigo\n ");;
                                printf("2 - Ordem de produtos\n ");
                                printf("3 - voltar\n\n ");
                                scanf("%d",&opcao);
                            switch (opcao){
                                case 1:{                //procura o codigo por codigo
                                    printf("\n Informe o codigo do produto : ");
                                    scanf("%d",&cod);
                            for(int i=0;i<x;i++){
                                if(pro[i].codigo==cod){
                                    printf ("\n Codigo: %d\n Nome: %s\n",pro[i].codigo, pro[i].descricao);
                                    printf (" Quantidade: %d\n Valor de compra: %.2f\n Valor de venda: %.2f\n tamanho: %s\n\n ", pro[i].quantidade, pro[i].pcompra, pro[i].pvenda,pro[cod].tamanho);
}}
                                    getch();
                                    controleProduto();
                                break;
                                case 2:{ //Metodo que ordena os produtos
                                    int i , j , valor,c;
                                    char valor1[20],valor4[50];
                                    float valor2,valor3;
                                    int gap = 1;
                                do {
                                    gap = 3*gap+1;
                                  } while(gap < x);
                                do {
                                    gap /= 3;
                                      for(i = gap; i < x; i++) {
                                        valor =pro[i].codigo;
                                        strcpy(valor1, pro[i].descricao);
                                        strcpy(valor4, pro[i].tamanho);
                                        valor2 =pro[i].pcompra;
                                        valor3 =pro[i].pvenda;
                                        j = i - gap;
                                     while (j >= 0 && valor < pro[j].codigo) {
                                        pro[j + gap].codigo = pro[j].codigo;
                                        strcpy(pro[j + gap].descricao,pro[j].descricao);
                                        strcpy(pro[j + gap].tamanho,pro[j].tamanho);
                                        pro[j + gap].pcompra = pro[j].pcompra;
                                        pro[j + gap].pvenda = pro[j].pvenda;
                                        j -= gap;
}
                                        pro[j + gap].codigo = valor;
                                        strcpy(pro[j + gap].descricao, valor1);
                                        strcpy(pro[j + gap].tamanho, valor4);
                                        pro[j + gap].pcompra = valor2;
                                        pro[j + gap].pvenda = valor3;
                                    }} while ( gap > 1);
                                        system ("cls");
                                        printf (" Codigo\t|Nome\t\t|Preco de compra\t|Preco de venda\t|Tamanho\n ");
                                    for (c=0;c<x;c++){
                                        if (pro[c].pcompra > 0)//Exibe os remedios ordenados somente os cadastrados
                                            printf ("%d\t|%s\t| R$ - %.2f\t\t| R$ - %.2f\t|%s\n ", pro[c].codigo,pro[c].descricao,pro[c].pcompra,pro[c].pvenda,pro[c].tamanho);
}
                                            printf ("\n\n\n");
                                            getch();
                                            controleProduto();
                                        break;
}
                                        case 3:{ //voltar
                                            getch();
                                            controleProduto();
                                        break;
}}}
                                case 3:{//Exibir todos os Produtos
                                     system("cls");
                                        for(int i=0;i<x;i++){
                                            if(pro[i].codigo>0){
                                                FILE *arq_produtos;
                                                arq_produtos =fopen("arquivo_produtos.txt","a+");
                                                    if(arq_produtos == NULL){
                                                        printf("erro na abertura do arquivo");
                                                    }else{
                                                        printf ("\n Codigo : %d\n Nome : %s\n",pro[i].codigo, pro[i].descricao);
                                                        printf (" Quantidade : %d\n Valor de compra : %.2f\n Valor de venda : %.2f\n Tamanho : %s\n\n ", pro[i].quantidade, pro[i].pcompra, pro[i].pvenda,pro[i].tamanho);
                                                        fprintf(arq_produtos,"\"\n Codigo : %d\n Nome : %s\n",pro[i].codigo, pro[i].descricao);
                                                        fprintf (arq_produtos,"Quantidade : %d\n Valor de compra : %.2f\n Valor de venda : %.2f\n Tamanho : %s\n\n ", pro[i].quantidade, pro[i].pcompra, pro[i].pvenda,pro[i].tamanho);
                                                        fclose(arq_produtos);
}}}};
                                            getch();
                                            controleProduto();
                                        break;
}
                                case 4:{//Altera um cadastro de produtos
                                     char cond;
                                     do{
                                        printf("\n Informe o codigo do produto a ser alterado :  ");
                                        scanf("%d",&cod);
                                    if (ProdutoExiste(cod) != 1){ //verifica se o codigo esta castrado
                                        printf("  Produto inexistente !");
                                        getch();
                                        controleProduto();}
                                  else{
                                        printf(" Nome : %s\n",pro[codProduto].descricao);
                                        printf(" Quantidade : %d\n",pro[codProduto].quantidade);
                                        printf(" Valor de Compra : %.2f\n",pro[codProduto].pcompra);
                                        printf(" Valor de Venda : %.2f\n",pro[codProduto].pvenda);
                                        printf(" tamanho : %s\n\n ",pro[codProduto].tamanho);
                                        printf("\n Informe o novo codigo do produto :  ");
                                        scanf("%d",&pro[codProduto].codigo);
                                        printf("\n Informe o novo nome do produto :  ");
                                        fflush(stdin);
                                        gets(pro[codProduto].descricao);
                                        printf("\n Informe o nova quantidade :  ");
                                        scanf("%d",&pro[codProduto].quantidade);
                                        printf("\n Informe o novo Valor de Compra :  ");
                                        scanf("%f",&pro[codProduto].pcompra);
                                        printf("\n Informe o novo Valor de Venda :  ");
                                        scanf("%f",&pro[codProduto].pvenda);
                                        printf("\n Informe o novo tamanho :  ");
                                        fflush(stdin);
                                        gets(pro[codProduto].tamanho);
}
                                        printf("\n Deseja alterar outro produto(s/n)?  ");
                                        scanf("%s",&cond);
}
                                     while(cond!='n');
                                        controleProduto();
                                     break;
}
                                case 5:{//Excuir o cadastro de produto
                                    char cond,resp;
                                    do{
                                        printf("\n\n  Informe o codigo do produto a ser excluido :  ");
                                        scanf("%d",&cod);
                                           if (ProdutoExiste(cod) != 1){ //verifica se o produto esta cadastrado
                                                printf(" Produto inexistente !");
                                                getch();
                                                controleProduto();
                                        }else{
                                           printf ("\n Codigo : %d\n Nome : %s\n ",pro[codProduto].codigo, pro[codProduto].descricao);
                                           printf (" Quantidade : %d\n Valor de compra : %.2f\n Valor de venda : %.2f\n Tamanho : %s\n\n ", pro[codProduto].quantidade, pro[codProduto].pcompra, pro[codProduto].pvenda,pro[codProduto].tamanho);
                                           printf("\n Deseja realmente excluir este produto(s/n) ?  ");
                                           scanf("%s",&resp);
}
                                           if(resp='s'){
                                           pro[codProduto].codigo=0;
                                           strcpy (pro[codProduto].descricao,"");
                                           pro[codProduto].quantidade=0;
                                           pro[codProduto].pvenda=0;
                                           pro[codProduto].pcompra=0;
                                           strcpy (pro[codProduto].tamanho,"");
}
                                           printf("\n Deseja excluir outro produto(s/n) ? ");
                                           scanf("%s",&cond);
}
                                        while(cond!='n');
                                            controleProduto();
                                        break;
}
                                case 6: { //Voltar
                                   menu();
                                   getch();
                                   controleProduto();
                                   break;
                                }
                                default: {
                                   printf(" Opcao Invalida ");
                                   getch();
                                   controleProduto();
 }}}
int ProdutoExiste(int cod){//Verifica se o produto esta cadastrado
 int i,Retorno = 0;
 for (i = 0; i < x; i++){
  if (pro[i].codigo == cod){
    codProduto=i;
    Retorno = 1;
}}
 return Retorno;
}
int PessoaExiste(int cod){ //verifica se o funcionario
 int i,Retorno = 0;
 for (i = 0; i < x; i++){
  if (pes[i].codigo == cod){
  codPessoa=i;
   Retorno = 1;
}}
 return Retorno;
}
