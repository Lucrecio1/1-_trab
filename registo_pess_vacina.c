#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 5
int qtd_reg;

//estrutura usada para armazenar a data de nascimento
typedef struct data{
    int dia,mes,ano;
}DATA;

typedef struct comorb{
    char  comorbil[100];   
} COMORB;
//estrutura de dados individual
typedef struct Dados_Individual{
    int    cod_reg;
    char nome_cmp[100];
    char  Doc_Ind[100];
    char  Num_Di[100];
    char  e_mail[100];
    char  Genero;
    DATA dat_nasc; 
    int Num_TL;
    COMORB comorb[max];
    char  nacional[100];
    char  prov_res[100];
    char  muni_res[100];
}DADOS;
//estrutura utilizada para preencher o Registo Individual
typedef struct DADOS_ID{
	char Nome_cp[100];
	char DOC_IND[100];
	char NUM_DI[100];
	int  COD_RI;
}DADOS_IDT;

//Função para criação de Interface (Design)
void Interface(){
    for (int i = 0; i < 44; i++)
    {
        printf("-");
    }
}
void pausar_ex(){
    printf("\n\nclique em qualquer tecla para continuar\n");
           system("pause");
           system("cls");
}
void comorblidades(DADOS p[],int resp,int qtds_doe, int indice){
    printf("\ntem alguma doenca");
           printf("\n1- Sim");
           printf("\n0- Nao\n");
           scanf("%d", &resp);

           switch (resp)
           {
           case 1:
               printf("tens quantas doencas");
               scanf("%d", &qtds_doe);
                if (qtds_doe>0 && qtds_doe<=3)
                {
                    for (int i = 1; i <= qtds_doe; i++)
                    {
                        printf("\ndigite a doenca numero %d",i);
                        scanf("\n%[^\n]s", &p[indice].comorb[i].comorbil);
                        //fgets(p[indice].comorb[i].comorbil, 100, stdin);
                    }
                }
               break;
           case 0:
               break;
           default:
               break;
           }
}
//  função que permite efetuar o registo individual.
void CAD_VACINA(DADOS pessoa[],int ver_resp,int qtds_d){
  
   printf("pretendes efetuar quantos registos: ");
   scanf("%d", &qtd_reg);
   
   system("cls");
   printf("\n\t REGISTO DE VACINA\n");
    Interface();
    for (int i = 1; i <= qtd_reg; i++)
    {
            printf("\nDigite o Nome:");
           fflush(stdin);
           fgets(pessoa[i].nome_cmp, 100, stdin);
          
                      
     
          printf("Digite o Documento Individual:");
           fflush(stdin);
           fgets(pessoa[i].Doc_Ind, 100, stdin);

          printf("Digite o Numero do ocumento Individual:");
           fflush(stdin);
           fgets(pessoa[i].Num_Di, 100, stdin);  
          
           printf("Digite o E_mail:");
           fflush(stdin);
           fgets(pessoa[i].e_mail, 30, stdin);
           
      
           printf("Telefone: ");   
		    scanf("%d",&pessoa[i].Num_TL); 
		
		   printf("Digite a data de nascimento\n");
           printf("Dia: ");
            scanf("%d",&pessoa[i].dat_nasc.dia);
           printf("mes: ");
            scanf("%d",&pessoa[i].dat_nasc.mes);
           printf("ano: ");
            scanf("%d",&pessoa[i].dat_nasc.ano);
        
           printf("Digite a Nacionalidade:");
            fflush(stdin);
            fgets(pessoa[i].nacional, 30, stdin);

           printf("Digite Provincia:");
            fflush(stdin);
            fgets(pessoa[i].prov_res, 30, stdin);
        
           printf("Digite a Municipio:");
            fflush(stdin);
            fgets(pessoa[i].muni_res, 30, stdin); 
		   
		   
          pessoa[i].cod_reg=rand()%100;
    }       
}
/* está função tem a finalidade de pegar os valores que estão dentro da estrutura Dados_individual, atraves dos ponteiros
que posteriormente seram utilizados para preencher o registo individual, esta funcionando 
corretamente. usando STRCPY. Essa função copia um valor para uma variável de cadeia de caracteres.
*/
void preencher_RI(DADOS pessoa[], DADOS_IDT luc[],int qtd_reg){
    for(int i=1;i<=qtd_reg;i++){
        strcpy(luc[i].Nome_cp,pessoa[i].nome_cmp);
        luc[i].COD_RI=pessoa[i].cod_reg;
       // strcpy(luc[i].DOC_IND,pessoa[i].Doc_Ind);
       // strcpy(luc[i].NUM_DI,pessoa[i].Num_Di);
    }
}
// esta função serve para mostrar os valor contidos dentro de cada campo da estrutura Dados_Individual 
void Mostrar_RI(DADOS_IDT pessoa[]){
	
    char inf[40]=" registos individuais a serem mostrados";
    
    printf("\n %d %s\n",qtd_reg,strupr(inf));
    Interface();
    for (int i = 1; i <= qtd_reg; i++)
    {	 
    	 printf("\nNOME: %s",strupr(pessoa[i].Nome_cp));  
         printf("Codigo de registo: %d\n", pessoa[i].COD_RI);
         //printf("Documento de I: %s\n", strupr(pessoa[i].DOC_IND));  
         //printf("Numero do Di: %s\n", pessoa[i].NUM_DI); 	
         Interface();
    }pausar_ex();	
}
// Menu de opções
void Menu_principal(){
	printf("\n\t  ESCOLHA A OPCAO\n");
	Interface();	
	printf("\n1- Efetuar registo\n");
	printf("2- Opcoes Mostrar RI\n");
    printf("0- Sair\n");
}
void sms_erro(){
        char nao_exist[35]="os dados selecionado nao existe ";
        printf("\n %s", strupr(nao_exist));
        printf("\nOU A OPCAO ESCOLHIDA E INVALIDA\n\n");
        Interface();
        pausar_ex();
}

void mostrar_Ri_por_parte(DADOS_IDT pessoa[], int opcao,int qtd_reg){
	system("cls");
        char inf[35]="dados do registo individual numero";        
    Interface();
  for (int i = 1; i <= qtd_reg; i++)
  {
       if (opcao==i)
        {
           printf("\n %s  %d\n",strupr(inf),opcao);
           Interface();
    	   printf("\nNOME: %s",strupr(pessoa[i].Nome_cp));  
           printf("Codigo de registo: %d\n", pessoa[i].COD_RI);
         //printf("Documento de I: %s\n", strupr(pessoa[i].DOC_IND));  
         //printf("Numero do Di: %s\n", pessoa[i].NUM_DI); 	
           Interface();
           pausar_ex();
        }
        
  }    if((opcao>qtd_reg)){
           system("cls");
           sms_erro();         
        }
}
void op_mostrar( DADOS_IDT ver[], int op_most,int qtd_reg);

// função principa responsavel pela chamada das sub-rotinas
void main(){
    int opc,c,op_most,resp,qtds_doe;
    DADOS Cidadao[max];
    DADOS_IDT aux[max];
    
    srand(time(NULL));
    for(;;){
        system("cls");
       Menu_principal();
	    scanf("%d",&opc);
	
	switch(opc){
		case 1:
			system("cls");
            CAD_VACINA(Cidadao,resp,qtds_doe);
            preencher_RI(Cidadao,aux,qtd_reg);
            c=1;
        break;
        case 2:
        	if(c==1){
        		system("cls");
                op_mostrar(aux,op_most,qtd_reg);
			}
			else{
				system("cls");
				printf("\n\tPrimeiro escolha a opcao 1\n");
				Interface();
				printf("\n");
				_sleep(1000);
				system("cls");
			}
            break;
           case 0:
            system("cls");
        	exit(0);
           break;
           default:
           system("cls");
          printf("\nOpcao Invalida");
          _sleep(1000);
     	}    
    }
}	

void op_mostrar( DADOS_IDT ver[], int op_most, int qtd_reg){
  for(;;){
    printf("\n\t  ESCOLHA A OPCAO \n");
    Interface();
    for (int i = 1; i <= qtd_reg; i++)
    {
        printf("\n%d - para mostrar o registo %d", i,i);
        
    }printf("\n6 - ver todos os registos");
     printf("\n7 - Menu principal");
     printf("\n0 - Sair\n");
     scanf("%d", &op_most);
     
     switch(op_most){
         case 1:
             mostrar_Ri_por_parte(ver,op_most,qtd_reg); 
         break;
         case 2:
             mostrar_Ri_por_parte(ver,op_most,qtd_reg);
         break; 
         case 3:
              mostrar_Ri_por_parte(ver,op_most,qtd_reg);
         break;
         case 4:
               mostrar_Ri_por_parte(ver,op_most,qtd_reg);
         break;
         case 5:
               mostrar_Ri_por_parte(ver,op_most,qtd_reg);
         break;
         case 6:
                system("cls");
                Mostrar_RI(ver);
         break;
         case 7:
                system("cls");
                main();
         break;    
         case 0:
                exit(0);
         break;
         default:
         system("cls");
          sms_erro();
        }
    }
}