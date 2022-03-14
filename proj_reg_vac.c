#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 5

typedef struct data{
    int dia,mes,ano;
}DATA;

typedef struct comorb{
    char  comorbil[100];   
} COMORB;

typedef struct Dados_Individual{
    int    cod_reg;
    char nome_cmp[100];
    char  Doc_Ind[40];
    char  Num_Di[15];
    char  e_mail[30];
    char  Genero;
    DATA dat_nasc; 
    int Num_TL;
    COMORB comorb[3];
    char  nacional[30];
    char  prov_res[30];
    char  muni_res[30];
}DADOS;

typedef struct DADOS_RI{
	char Nome_cp[100];
	char DOC_IND[40];
	char NUM_DI[15];
	int  COD_RI;
}DADOS_IDT;

void Interface(){
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
}
void pausar_ex(){
    printf("\n\nCLIQUE EM QUALQUER TECLA PARA CONTINUAR\n");
        system("pause");
        system("cls");
}
void inf_etapas(int etapa){
    system("cls");
    printf("\n\t\tREGISTO DE VACINA\n");
    Interface();
    printf("\nPREENCHE OS CAMPOS DA ETAPA %d DE 4\n", etapa);
    Interface();
    
}
void sms_1_analise(int etapa){
    printf("\nANALISANDO OS DADOS");
    printf("\nAGUARDE");
    for (int i = 0; i < 3; i++)
    {
        printf(".",i);
        _sleep(1000);
    }
}
void sms_2_sucesso(int etapa){
    system("cls");
    printf("\n\t\tREGISTO DE VACINA\n");
    Interface();
    printf("\nDADOS DA %d ETAPA SALVO COM SUCESSO",etapa);
    _sleep(2000);
    system("cls");
}
void sms_3_alert(){
        char nao_exist[35]="OS DADOS SELECIONADO NAO EXISTE ";
        printf("\n %s", strupr(nao_exist));
        printf("\nOU A OPCAO ESCOLHIDA E INVALIDA\n\n");
        Interface();
        pausar_ex();
}
void sms_4_erro(int num){
        char nao_exist[35]="deves digitar numeros de 1 a ";
        printf("\n%s %d", strupr(nao_exist),num);
        printf("\nDIGITE NOVAMENTE\n\n");
        Interface();
        pausar_ex();
}
void mod_1_reg(DADOS pessoa[],int i){
         inf_etapas(1);
        printf("\nDigite o Nome:");
           fflush(stdin);
           fgets(pessoa[i].nome_cmp, 100, stdin);
          
        printf("Digite o Documento Individual:");
           fflush(stdin);
           fgets(pessoa[i].Doc_Ind, 40, stdin);

        printf("Digite o Numero do documento Individual:");
           fflush(stdin);
           fgets(pessoa[i].Num_Di, 15, stdin);  
          
        printf("Digite o E_mail:");
           fflush(stdin);
           fgets(pessoa[i].e_mail, 30, stdin);

        pessoa[i].cod_reg=(rand()%100)*12;
         sms_2_sucesso(1);
}
void mod_2_reg(DADOS pessoa[],int i){
     inf_etapas(2);
       printf("\nDigite o numero de telefone: ");   
		scanf("%d",&pessoa[i].Num_TL); 
		
	    for (; ;){ 
            system("cls");
            inf_etapas(2);
             printf("\nDigite a data de nascimento\n");
                printf("Dia: ");
                  scanf("%d",&pessoa[i].dat_nasc.dia);
                printf("mes: ");
                  scanf("%d",&pessoa[i].dat_nasc.mes);
                printf("ano: ");
                  scanf("%d",&pessoa[i].dat_nasc.ano);
            sms_1_analise(2);
            
           if ((pessoa[i].dat_nasc.dia > 0 && pessoa[i].dat_nasc.dia <= 31) && 
		   (pessoa[i].dat_nasc.mes > 0 && pessoa[i].dat_nasc.mes <= 12) && 
		   ((pessoa[i].dat_nasc.ano>0) &&(2022-pessoa[i].dat_nasc.ano>=12) ))
            {
                 sms_2_sucesso(2);
                 break;
            }else{
                printf("\nData incerta, nao pode fazer o registo");
                _sleep(1500);
                system("cls");
                 Interface();
             }          
     }                         
}
void mod_3_reg(DADOS pessoa[],int i){
     inf_etapas(3);
        printf("\nDigite a Nacionalidade:");
            fflush(stdin);
            fgets(pessoa[i].nacional, 30, stdin);
  
        printf("Digite Provincia:");
            fflush(stdin);
            fgets(pessoa[i].prov_res, 30, stdin);
        
        printf("Digite a Municipio:");
            fflush(stdin);
            fgets(pessoa[i].muni_res, 30, stdin); 
           sms_2_sucesso(3);  
}
void mod_4_reg(DADOS p[],int resp,int qtds_doe, int indice){
     inf_etapas(4);
    printf("\nPOSSUI COMORBILIDADE?");
           printf("\n1- Sim");
           printf("\n0- Nao\n");
           scanf("%d", &resp);

           switch (resp)
           {
           case 1:
                for (;;)
                {
                    system("cls");
                    inf_etapas(4);
                   printf("\nDigite o Numero de comorbilidade: ");
                   scanf("%d", &qtds_doe);
                   sms_1_analise(4);
                   inf_etapas(4);
                  if (qtds_doe>0 && qtds_doe<=3)
                    {
                        for (int i = 1; i <= qtds_doe; i++)
                        {
                            printf("\nDigite a Comorbilidade numero %d: ",i);
                            scanf("\n%[^\n]s", &p[indice].comorb[i].comorbil);
                        }
                        sms_2_sucesso(4);
                        break;
                    }else{
                      sms_4_erro(3);
                    }  
                }
               break;
           case 0:strcpy(p[indice].comorb[1].comorbil,"sem comorbilidade");
               break;
           default:
               break;
           }
}
void CAD_VACINA(DADOS pessoa[],int ver_resp,int qtds_d,int i){
        mod_1_reg(pessoa,i);
        //mod_2_reg(pessoa,i);
        //mod_3_reg(pessoa,i);
       // mod_4_reg(pessoa,qtds_d,ver_resp,i); 
        
        printf("\n\t\tREGISTO DE VACINA\n");
        Interface();
        printf("\nREGISTO NUMERO %d FEITO COM SUCESSO", i);
        _sleep(1300);
}
void preencher_RI(DADOS pessoa[], DADOS_IDT luc[],int i){
        strcpy(luc[i].Nome_cp,pessoa[i].nome_cmp);
        luc[i].COD_RI=pessoa[i].cod_reg;
        strcpy(luc[i].DOC_IND,pessoa[i].Doc_Ind);
        strcpy(luc[i].NUM_DI,pessoa[i].Num_Di);
}
void Mostrar_RI(DADOS_IDT pessoa[],int qtd_reg){
	
    char inf[40]="registos individuais a serem mostrados";
    
    printf("\n %d %s\n",qtd_reg,strupr(inf));
    Interface();
    for (int i = 1; i <= qtd_reg; i++)
    {	 
    	 printf("\nNome: %s",strupr(pessoa[i].Nome_cp));  
         printf("Codigo de registo: %dLLDDB%d", pessoa[i].COD_RI, pessoa[i].COD_RI*11 );
         printf("\nDocumento de ID: %s", strupr(pessoa[i].DOC_IND));  
         printf("Numero do DI: %s\n", pessoa[i].NUM_DI); 	
    	  Interface();
    }pausar_ex();	
}
void Menu_principal(){
	printf("\n\t\tESCOLHA A OPCAO\n");
	Interface();	
	printf("\n1- Efetuar registo");
	printf("\n2- Opcoes Mostrar RI\n");
    printf("0- Sair\n");
}
void mostrar_Ri_por_parte(DADOS_IDT pessoa[], int opcao,int qtd_reg){
	system("cls");
        char inf[35]="dados do registo individual numero";        
    Interface();
  for (int i = 1; i <= qtd_reg; i++){
       if (opcao==i)
        {
           printf("\n %s  %d\n",strupr(inf),opcao);
           Interface();
    	   printf("\nNome: %s",strupr(pessoa[i].Nome_cp));  
           printf("Codigo de registo: %dLLDDB%d", pessoa[i].COD_RI,pessoa[i].COD_RI*11);
           printf("\nDocumento de I: %s", strupr(pessoa[i].DOC_IND));  
           printf("Numero do Di: %s\n", pessoa[i].NUM_DI); 	
           Interface();
           pausar_ex();
        }      
    }   
      if((opcao>qtd_reg)){
           system("cls");
           sms_3_alert();         
        }
}
void op_mostrar( DADOS_IDT ver[], int op_most,int qtd_reg);
void main(){
    int opc,c,op_most;
    int qtd_reg,resp,qtds_doe;
    DADOS Cidadao[max];
    DADOS_IDT aux[max];
    
    srand(time(NULL));
    for(;;){
        system("cls");
       Menu_principal();
	    scanf("%d",&opc);
	
	switch(opc){
		case 1:
         for (; ;){
            
            printf("VAI REALISAR QUANTOS REGISTOS: ");
            scanf("%d", &qtd_reg);
             if(qtd_reg>0 && qtd_reg<=5){
                 for (int i = 1; i <=qtd_reg; i++)
                 {
                     CAD_VACINA(Cidadao,resp,qtds_doe,i);
                     preencher_RI(Cidadao,aux,i);
                 }
                 c=1;
             break;
        }
        else{
            system("cls");
           sms_4_erro(5);
            }  
        }  
        break;
        case 2:
        	if(c==1){
        		system("cls");
                op_mostrar(aux,op_most,qtd_reg);
			}
			else{
				system("cls");
				printf("\n\tPRIMEIRO ESCOLHA A OPCAO 1\n");
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
          printf("\nOpcao INVALIDA");
          _sleep(1000);
     	}    
    }
}	
void op_mostrar( DADOS_IDT ver[], int op_most, int qtd_reg){
  for(;;){
    printf("\n\t\tESCOLHA A OPCAO \n");
    Interface();
    for (int i = 1; i <= qtd_reg; i++)
    {
        printf("\n%d - para mostrar o registo %d", i,i);
        
    }printf("\n6 - VER TODOS OS REGISTOS");
     printf("\n7 - MENU PRINCIPAL");
     printf("\n0 - SAIR\n");
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
                Mostrar_RI(ver,qtd_reg);
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
          sms_3_alert();
        }
    }
}