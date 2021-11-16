#include <stdio.h>
#include <stdlib.h>

#define quantidade 4000 

void tripla_pitagorica_c()
{
    int a, b, c, i, j, k;
    int contador = 0;

    FILE * fPtr;
    fPtr = fopen("tripla.txt", "w");

    /* caso a criação do arquivo não tenha sido bem sucedida. */
    if(fPtr == NULL)
    {
        printf("Não foi possível criar o arquivo.\n");
        exit(EXIT_FAILURE);
    } else {

        fprintf(fPtr,"\n  ✩｡:*•.─────  ❁  Triplas Pitagóricas ❁  ─────.•*:｡✩  \n \n");

        for (i = 1; i < quantidade - 1; i++){
            for (j = i; j < quantidade; j++){
                for (k = j; k <= quantidade; k++){
                    a = i * i;
                    b = j * j;
                    c = k * k;
                    if (a + b == c){
                        fprintf(fPtr,"(a = %d, b= %d, c=%d) \n",i,j,k);
                        contador++;
                    }
                }
            }
        }
    }
    
    fprintf(fPtr,"\n Total de triplas: %d",contador);
    fclose(fPtr);
    
}
 
// Driver Code
int main()
{
    tripla_pitagorica_c();
}