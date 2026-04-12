#include <stdio.h>

int N,M; char S[10][10];
long long D[10][10];

int main()
{
	scanf ("%d %d",&N,&M);
	for (int i=0;i<N;i++) scanf ("%s",S[i]);

	D[0][0] = 1;
	int c = 0;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++) if (S[i][j] == '#'){
			if (i) D[i][j] += D[i-1][j];
			if (j) D[i][j] += D[i][j-1];
			c++;
		}
	}

	if (c != N + M - 1){
		puts("Impossible");
		return 0;
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			if ((S[i][j] == '#') ^ (D[i][j] == 1)){
				puts("Impossible");
				return 0;
			}
		}
	}

	puts("Possible");
	return 0;
}