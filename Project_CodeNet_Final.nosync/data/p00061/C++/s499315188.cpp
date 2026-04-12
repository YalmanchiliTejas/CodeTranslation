#include <stdio.h>

int main(void)
{
	int num[128];
	int rank[128];
	int i, j;
	int t;
	int n;
	
	for (i = 0; i < 128; i++){
		rank[i] = 0;
	}
	i = 0;
	while (scanf("%d,%d", &n, &rank[i]), n != 0 || rank[i] != 0){
		num[n] = rank[i];
		for (j = i; j > 0; j--){
			if (rank[j] > rank[j - 1]){
				t = rank[j - 1];
				rank[j - 1] = rank[j];
				rank[j] = t;
			}
			if (rank[j] == rank[j - 1]){
				rank[j] = 0;
			}
		}
		i++;
	}
	n = i;
	for (i = 0; i < n - 1; i++){
		for (j = n - 1; j >= 1 + i; j--){
			if (rank[j] > rank[j - 1]){
				t = rank[j - 1];
				rank[j - 1] = rank[j];
				rank[j] = t;
			}
		}
	}
	while (scanf("%d", &n) != EOF){
		for (i = 0; i < 108; i++){
			if (num[n] == rank[i]){
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	return (0);
}