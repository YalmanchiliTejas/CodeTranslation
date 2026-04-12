#include<stdio.h>
int main(void)
{
	int N,K;
	char S[10],a;
	scanf("%d", &N);
	scanf("%s",S);
	scanf("%d", &K);
	for (int i = 0; i < N; i++) {
		if (S[i] == S[K-1])
			printf("%c", S[i]);
		else
			printf("*");
	}
	
	return 0;
}