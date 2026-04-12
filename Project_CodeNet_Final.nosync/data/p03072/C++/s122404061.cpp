#include<stdio.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	int H[100];

	for (int i = 0; i < N; i++)
		scanf("%d", &H[i]);
	int count = 1;
	int Max = H[0];
	for (int i = 0; i < N-1; i++) {
		
		if (Max - H[i + 1] <= 0) {
			count++;
			Max = H[i + 1];

		}
			
	}

	printf("%d", count);

	return 0;



}