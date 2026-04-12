#include <stdio.h>

int main(void)
{
	int n;
	int i, j, k, l;
	int sq[24][24];
	
	while (scanf("%d", &n), n != 0){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				sq[i][j] = 0;
			}
		}
		i = n / 2 + 1;
		j = n / 2;
		for (k = 1; k < n * n; k++){
			sq[i][j] = k;
			if (i + 1 >= n){
				i = 0;
			}
			else {
				i++;
			}
			if (j + 1 >= n){
				j = 0;
			}
			else {
				j++;
			}
			
			while (sq[i][j] > 0){
				if (j - 1 < 0){
					j = n - 1;
				}
				else {
						j--;
				}
				if (i + 1 >= n){
					i = 0;
				}
				else {
						i++;
				}
			}
		}
		sq[i][j] = k;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				printf("%4d", sq[i][j]);
			}
			printf("\n");
		}
	}
	
	return (0);
}