#include <stdio.h>

int main(void)
{
	int N, T, E, x;
	int i, j;
	
	scanf("%d %d %d", &N, &T, &E);
	for (i = 0; i < N; i++){
		scanf("%d", &x);
		for (j = T - E; j <= T + E; j++){
			if (j % x == 0){
				printf("%d\n", i + 1);
				
				return (0);
			}
		}
	}
	printf("-1\n");
	
	return (0);
}