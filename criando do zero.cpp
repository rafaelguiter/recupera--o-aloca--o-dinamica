#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct cadastro cadastro;
struct cadastro{

    int id;
    char nome[100];
    char email[100];
    char sexo [5];
    char endereco[300];
    double altura;
    int vacina;
    struct cadastro *proximo;

}*pessoas;

cadastro *inicializar(){
    return NULL;
}

void limparbuffer(void){
  char c;
  while ((c= getchar())  != '\n' && c != EOF);
  
}



cadastro *inserir(cadastro *pessoas){

    void limparbuffer(void);

    cadastro *novo = (cadastro*) malloc(sizeof(pessoas));

    int i=0,parar, verificaremail; 
	int quantidade;



            printf("Digite o seu nome completo: \n");
        fgets(novo->nome, sizeof(novo->nome), stdin);
        printf("\n");


        printf("Por favor digite o seu email, siga o exemplo (exemplo@exemplo.com ou (.br)): \n ");
        fgets(novo->email, sizeof(novo->email), stdin);
        setbuf(stdin, NULL);
        printf("\n");

		if ((strstr(novo->email, "@") != NULL) || (strstr(novo->email, ".com")!= NULL) && (strstr(novo->email, ".br")!= NULL)){

			verificaremail=1;

		}else{

			while ((strstr(novo->email, "@") == NULL) || (strstr(novo->email, ".com")== NULL) && (strstr(novo->email, ".br")== NULL)){
				
				printf("Verifique o Email digitado, pois pode estar faltando alguns dos dados citados acima, ou um '@' ou um '.com' ou um '.br' \n");
				fgets(novo->email, sizeof(novo->email), stdin);
				setbuf(stdin, NULL);	
				printf("\n");

			}

		}

        printf("Nos informe o seu sexo (M) para masculino, (F) para feminino e (I) para indefinido: \n");
		fgets(novo->sexo, sizeof(novo->sexo), stdin);
		setbuf(stdin, NULL);
		printf("\n");

			while ((strstr(novo->sexo, "m")== NULL) && (strstr(novo->sexo, "f") == NULL) && (strstr(novo->sexo, "i") == NULL) ) {

				printf("Digito invalido, por favor responda com (m), (f) ou (i):\n");
				fgets(novo->sexo, sizeof(novo->sexo), stdin);
				setbuf(stdin, NULL);
				printf("\n");

			}


		printf("Nos informe sua altura: \n");
		scanf("%lf",&novo->altura, stdin);
		limparbuffer();
		printf("\n");               

		printf("Nos informe o seu endereco: \n");
		fgets(novo->endereco, sizeof(novo->endereco), stdin);
		setbuf(stdin, NULL);
		printf("\n");

        printf("Voce foi vaciando digite (1) SIM  e (2) NAO: \n");
		scanf("%d", &novo->vacina);
		setbuf(stdin, NULL);
		printf("\n");

        while(novo->vacina !=1 && novo->vacina!=2){

			printf("Digitos invalidos, verifique a opcao desejada.\nVoce ja foi vacinado digite (1) SIM  e (2) NAO: \n");
			scanf("%d", &novo->vacina);
			setbuf(stdin, NULL);
			printf("\n");
		}

        novo->proximo=pessoas;
	    return novo;


}

cadastro *editar(cadastro *pessoas){

		void limparbuffer(void);

        cadastro *auxiliar;

	    int i, n_encontrado, nome_ou_email, editar, escolha_editar, continuar, v_e_encontrado, visualizar;
	    char encontrar_nome[100], encontrar_email[100];


while (nome_ou_email!=1 && nome_ou_email!=2 ){

	printf("Voce quer fazer a pesquisa pelo nome ou pelo o e-mail ? (1)NOME / (2)E-MAIL: \n\n");
	scanf("%d",&nome_ou_email);
	limparbuffer();

}	


if (nome_ou_email==1){
 
    printf("Digite o nome desejado:\n\n");
fgets(encontrar_nome,sizeof(encontrar_nome), stdin);
fflush(stdin);


}else{

    printf("Digite o E-MAIL desejado:\n\n");
fgets(encontrar_email,sizeof(encontrar_email), stdin);
fflush(stdin);

}

for (auxiliar=pessoas; auxiliar!=NULL;  auxiliar=auxiliar->proximo){

    if ((strcmp(auxiliar->nome, encontrar_nome)==0) || (strcmp(auxiliar->email, encontrar_email)==0)){



        printf("-----------------------   Cadastro Encontrado: ------------------------------\n\n");
            printf("ID: %d\n\n", auxiliar->id);
            printf("Nome: %s\n\n", auxiliar->nome);
            printf("Email: %s\n\n", auxiliar->email);
            printf("Sexo: %s\n\n", auxiliar->sexo);
            printf("Endereco: %s\n\n", auxiliar->endereco);
            printf("Altura: %.2f\n\n", auxiliar->altura);
            printf("Vacina: %d\n\n", auxiliar->vacina);

        
		v_e_encontrado = 1;

        break;

        

    }else{

        i++;

    }

}



if (v_e_encontrado!=1){

    printf("-------------------------------------------------------------------\n\n");

    printf("Cadastro nao encontrado\n\n");

    printf("-------------------------------------------------------------------\n\n");

}else{


	while (editar!=1 && editar!=2){

		printf("Deseja editar algum dos dados ? (1) SIM  / (2) NAO : \n\n");
			scanf("%d", &editar);
			fflush(stdin);

	}    


	if (editar==1){

		      do{  
			   
			        printf("------------------------     Digite o numero do campo que deseja alterar:     -------------------------------\n");
                    printf("1 - Nome\n");
                    printf("2 - Email\n");
                    printf("3 - Sexo\n");
                    printf("4 - Endereco\n");
                    printf("5 - Altura\n");
                    printf("6 - Vacina\n");
                    scanf("%d\n", &escolha_editar);
                    limparbuffer();
                
        
                    switch (escolha_editar) {

                        case 1:
                        printf("Digite o novo nome: \n");
                        fgets(auxiliar->nome, sizeof(auxiliar->nome), stdin);
                        limparbuffer();
                        break;

                        case 2:
                        printf("Digite o novo email:\n ");
                        fgets(auxiliar->email, sizeof(auxiliar->email), stdin);
                        limparbuffer();
                        break;

                        case 3: 
                        printf("Digite o novo sexo: \n ");
                        fgets(auxiliar->sexo, sizeof(auxiliar->sexo), stdin);
                        limparbuffer();
                        break;

                        case 4: 
                        printf("Digite o novo endereco: \n ");
                        fgets(auxiliar->endereco, sizeof(auxiliar->endereco), stdin);
                        limparbuffer();
                        break;

                        case 5:
                        printf("Digite a nova altura:\n ");
                        scanf("%lf", &auxiliar->altura);
                        limparbuffer();
                        break;

                        case 6:
                        printf(" A pessoa foi vacinada (1)SIM / (2)NAO: \n");
                        scanf("%d", &auxiliar->vacina);
                        limparbuffer();
                        break;

                        default:
                        printf("Numero digitado esta incorreto incorreto.\n\n");
						printf("Para editar o cadastro, selecione a opcao (DESEJA EDITAR OUTRO DADO DESTA PESSOA) digite (1).\n\n");
						printf("Leia as opcoes atentamente e selecione a opcao desejada.\n\n");
                        break;
                    
                    
                    }

			

							while (visualizar!=1 && visualizar!=2){

		                       printf("Deseja visualizar os dados do cadastro? (1)SIM / (2)NAO : \n");
                        		scanf("%d", &visualizar);
                        		limparbuffer();
		                    }

							if (visualizar==1){

								printf("-----------------------   Dados do paciente: ------------------------------\n\n");
            					printf("ID: %d\n\n", auxiliar->id);
            					printf("Nome: %s\n\n", auxiliar->nome);
            					printf("Email: %s\n\n", auxiliar->email);
           					 	printf("Sexo: %s\n\n", auxiliar->sexo);
            					printf("Endereco: %s\n\n", auxiliar->endereco);
            					printf("Altura: %.2f\n\n", auxiliar->altura);
            					printf("Vacina: %d\n\n", auxiliar->vacina);
							
								
							}else{
								printf("Certo - \n\n");
							}
							
                
               
  							while (continuar!=1 && continuar!=2){

		                       printf("Deseja editar outro dado desta pessoa? (1)SIM / (2)NAO : \n");
                        		scanf("%d", &continuar);
                        		limparbuffer();
		                    }
							
						
                    

            
                }while (continuar==1);


	}else{

		printf("------------------------  Aba de edicao de cadastro fechada   --------------------------\n\n");

	}



    
}



}

void *listar(cadastro *pessoas){
        cadastro *mostrar;
        int i, pesquisa, visualizar, verificap=0;
        char encontrar[100];
        void limparbuffer(void);

    while (pesquisa!=1 && pesquisa!=2){
        printf("Para visualizar a lista de ( NOMES digite-(1) ) / ( EMAIL digite-(2) )\n ");
    scanf("%d", &pesquisa);
    }




    if (pesquisa==1){
    for(mostrar=pessoas;mostrar!=NULL;mostrar=mostrar->proximo){
            printf("Nome: %s\n",mostrar->nome);
            verificap=1;
        }
    }else{

        for(mostrar=pessoas;mostrar!=NULL;mostrar=mostrar->proximo){
            printf("Nome: %s\n",mostrar->email);
            verificap=1;
        }
    }

    pesquisa=0;

    if(verificap!=1){
        printf("Banco de dados vazio\n\n");
    }

    else{

    while (visualizar!=1 && visualizar!=2){
        printf("Deseja visualizar os dados completo de alguma dessas pessoas ? SIM - (1)  / NAO - (2)\n");
        scanf("%d",&visualizar);
        limparbuffer();
        printf("\n\n");
    }

    if(visualizar==1){

                printf("Digite o Nome ou E-MAIL que desejado:\n\n");
                fgets(encontrar,sizeof(encontrar), stdin);
                limparbuffer();
                printf("\n");

            for (mostrar=pessoas; mostrar!=NULL;  mostrar=mostrar->proximo){

                if ((strcmp(mostrar->nome, encontrar)==0) || (strcmp(mostrar->email, encontrar)==0)){



                    printf("-----------------------   Cadastro Encontrado: ------------------------------\n\n");
                        printf("ID: %d\n\n", mostrar->id);
                        printf("Nome: %s\n\n", mostrar->nome);
                        printf("Email: %s\n\n", mostrar->email);
                        printf("Sexo: %s\n\n", mostrar->sexo);
                        printf("Endereco: %s\n\n", mostrar->endereco);
                        printf("Altura: %.2f\n\n", mostrar->altura);
                        printf("Vacina: %d\n\n", mostrar->vacina);

            
                        visualizar=0;


                    break;

                    

                }else{

                    printf("A pessoa informada nao se encontra em nosso banco de dados\n\n\n");
                    printf("-----------------------------------------------------------------\n");
                    

                }
            }


    }else{
        printf("Tudo bem, aba de visualizacao fechada\n\n\n");
        printf("------------------------------------------------------------\n\n");
    }
}

}

int main (){

    pessoas = inicializar();
    void limparbuffer(void);
    void *listar(cadastro *pessoas);
    
    int menu, fecharprograma;

    printf("teste");


    do {



	printf("esolha qual opcao deseja: \n");
    printf("1 - Cadastrar: \n");
    printf("2 - Editar : \n");
	printf("3 - listar : \n");

	scanf("%i", &menu);
    limparbuffer();


	switch(menu){

		case 1 :

            printf("---------------------------    Cadastro       ------------------------------\n\n");

            int parar;
                    
            while (parar!=2){
                

                pessoas=inserir(pessoas);

                printf("Digite (1) REALIZAR UM NOVO CADASTRO / (2) VOLTAR : \n\n");
                scanf("%d", &parar);
                fflush(stdin);
                printf("\n");


                while(parar!=1 && parar!=2){

                    printf("Digitos invalidos, verifique a opcao desejada.\nDeseja realizar um novo cadastro digite (1) SIM  e (2) NAO: \n\n");
                    scanf("%d", &parar);
                    fflush(stdin);
                    printf("\n");
                }
                    
                if(parar==1){

                    printf("-----------------------------   Realizar novo cadastro --------------------------- \n\n");
                    
                }else{ 

                    printf("----------------------------- Aba de cadastro fechada ------------------------------\n\n");
                    
                }

            }

            break;
		
		case 2:

			printf("-------------------------      Editar     ------------------------------------\n\n");
			
            editar(pessoas);

			break;

        case 3:

            printf("-------------------------      Lista dos cadastrados  ------------------------------------\n\n");
            listar(pessoas);

        break;


		default:

			printf("opcao invalida\n\n");

		break;

	}

		printf("digite - (1) PARA FECHAR O PROGRAMA / (2) PARA VOLTAR AO MENU DE SELECOES: \n");
		scanf("%d", &fecharprograma);
		

		while (fecharprograma!=1 && fecharprograma!=2){

			printf("Dados digitados incorretamente. Digite (1) para sair do programa e (2) para realizar outra operação :\n ");
		scanf("%d",&fecharprograma);
		fflush(stdin);

		}
		

	
} while (fecharprograma!=1);




	return 0; 	

 		
}

