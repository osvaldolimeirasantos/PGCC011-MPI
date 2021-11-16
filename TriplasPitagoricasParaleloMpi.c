#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define quantidade 4000

int main (int argc, char *argv[]) {

    //variaveis para a contagem das triplas e uso do MPI
    int a, b, c, i, j, k, y, f,size, rank, work;
    int contador = 0;
    int total = 0;
    int tripla = 0;

    //como o vetor precisa de um tamanho setado, alocamos a quantidade*25
    int vet[quantidade*25][3];

    //instancia para a criação do arquivo .txt
    FILE * fPtr;
    fPtr = fopen("triplaParalelo.txt", "w");

    


    //Inicialização do MPI
    MPI_Status st;
	MPI_Init(&argc, &argv);						// inicializado MPI
	MPI_Comm_size(MPI_COMM_WORLD, &size);		// quero saber em aplica��o so processos que mandei
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);		// quero saber quantos processos o usuario disparou

    /*Verifico se o processo é o mestre ou trabalhador, como o rank = 0 o processo é o mestre */
    if(rank == 0) {  

          /* caso a criação do arquivo não tenha sido bem sucedida. */
    if(fPtr == NULL)
    {
        printf("Não foi possível criar o arquivo.\n");
        exit(EXIT_FAILURE);
    } else {
        //criamos o cabeçalho do arquivo que vai receber as triplas
        fprintf(fPtr,"\n  ✩｡:*•.─────  ❁  Triplas Pitagóricas ❁  ─────.•*:｡✩  \n \n");

		for (work = 1; work < size; work++) {

            /*O mestre recebe as triplas encontradas pelos trabalhadores e faz a soma total*/
			MPI_Recv(vet, quantidade*25, MPI_INT, work, 1, MPI_COMM_WORLD, &st);
            MPI_Recv(&tripla, 1, MPI_INT, work, 1, MPI_COMM_WORLD, &st);
			fflush(stdout);

            /*verificamos se o trabalhador retornou com alguma tripla,
            caso tenha retornado, adicionamos as triplas ao arquivo criado e somamos
            o numero de triplas ao total*/
            if (tripla>0){
                for (f = 0;f <tripla; f++) {
                //adicionamos as triplas que foram encontradas no arquivo
                fprintf(fPtr,"(a = %d, b= %d, c=%d) \n",vet[f][0],vet[f][1],vet[f][2]);
                }   

                total+=tripla;
            }
		}

        //adicionamos o valor total no rodapé do arquivo
        fprintf(fPtr,"\n Total de triplas: %d",total);

        //finalizamos o arquivo
        fclose(fPtr);
    }

	} else 	{ 
        /* Aqui diz respeito aos trabalhadores, no primeiro FOR é feito o calculo para a distribuição da carga,
        y inicia com o valor do processo e vai incrementando de acordo com o tamanho total de processos (-1)
        que é o mestre, desta forma, se o trabalhador tiver valor 1 e tamanho total de processos 5 ele vai ser 
        incrementado de 4 em 4 até atingir o valor máximo estipulado para encontrar as triplas*/
	 for (y = rank; y <= quantidade; y=y+(size-1)){
        /*A combinação para encontrar as triplas*/
         for (i = y; i <= y; i++){
            for (j = i; j < quantidade; j++){
                for (k = j; k <= quantidade; k++){
                    a = i * i;
                    b = j * j;
                    c = k * k;
                    
                    /* Verificando se os valores encontrados formam uma tripla*/
                    if (a + b == c){
                            //alocamos as triplas em um vetor
                            vet[tripla][0] = i;
                            vet[tripla][1] = j;
                            vet[tripla][2] = k;

                        //contabilizamos cada tripla
                        tripla++;
                    }
                }
            }
        }
	 }
       
         
        /*Se o trabalhador encontrar uma tripla, ela é contabilizada e ao final do for é enviada
        para o mestre*/

        //enviamos o vetor com as triplas
		MPI_Send(vet,quantidade*25, MPI_INT, 0, 1, MPI_COMM_WORLD);

        //enviamos também a quantidade de triplas que cada trabalhador encontrou
        MPI_Send(&tripla,1, MPI_INT, 0, 1, MPI_COMM_WORLD);
		fflush(stdout);
	}
	
	// final do MPI 
	MPI_Finalize();	
	return 0;
}
