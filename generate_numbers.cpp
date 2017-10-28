#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void generate_sequence(float *s, int n){
	int i ;
    srand( (unsigned)time(NULL) );
	for(i=0; i<n;i++){
		
		s[i] = 1.0*((float)(rand())/RAND_MAX);
	}
}

/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(float *v, float *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] < c[ic]) v[z++] = c[iv++];
    else /* if (c[iv] > c[ic]) */ v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}


/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(float *v, float *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}




void mergesort(float *v, float n) {
  float *c =(float*) malloc(n * sizeof(float));
  sort(v, c, 0, n - 1);
  free(c);
}

long count_distincts(float *s, int n){
	int i;
	long count = n ;
	mergesort(s, n);
	for(i=0; i<n;i++){
		if(s[i]==s[i+1])
			count--;		
    } 
    return count;
	
}

int main(void){
	
	float sequence[1000000] ;
	int i;
	generate_sequence(sequence, 1000000);
		for(i=0; i<1000000; i++){	
		 printf(" %f ", sequence[i]);
	}
	
	long count = count_distincts(sequence, 1000000);
	printf("%d", count);
	
	
}
