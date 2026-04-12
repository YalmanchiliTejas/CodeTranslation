#include<stdio.h>
#include<cmath>
#include<algorithm>
int main(void)
{
	int N, S[110], A = 1, k = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &S[i]);
	}
	for (int i = 0; i < N - 1; i++)
	{
		if (i == 0)
		{
			k = S[0];
		}
		if (k <= S[i + 1])
		{
			k = S[i + 1];
			A++;
		}
	}

	printf("%d", A);
	return 0;
}