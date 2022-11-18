//Aurelio Adair Fernández Santiago

#include <stdio.h>
#include <stdlib.h>

int A[9];

void pantalla(int *A, int n){
	for(int i = 0; i < n-1; i++)
		printf("%d, ", A[i]);
	printf("%d", A[n-1]);
	printf("\n");
}

void leer_archivo(){
	FILE* archivo;
	char c, texto[20];
	int j=0, i=0;

	archivo = fopen("datos.txt","rt");
	do{
		c = fgetc(archivo);
		if (c == ',') {
			A[j] = atoi(texto);
			j++;
			for (int z = 0; z<i; z++)
				texto[z]=0;
			i=0;
			continue;
		}
		texto[i] = c;
		i++;
	}while(c!= EOF);
}

void examen(int *A, int n){
    for(int i=0; i < n; i++){
        int min = i;

        for(int j=i+1; j<n; j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        if(min != i){
            int key = A[min];
            A[min] = A[i];
            A[i] = key;
        }
    }
}

int main(){
    int n = 9;
    leer_archivo();
    printf("Input: ");
    pantalla(A, n);
    examen(A, n);
    printf("Output: ");
    pantalla(A, n);
    printf("\n");
}