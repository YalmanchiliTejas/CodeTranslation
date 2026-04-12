#include<stdio.h>
int main(void)
{
	int s[100][100];
	int sum[100];
	int change;
	int n=1;
	int i, t,j;
	j = 0;
	while (n)
	{
		sum[j] = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &s[j][i]);
		}
		for (i = 0; i < n; i++)
		{
			for (t = i; t < n; t++)
			{
				if (s[j][i] < s[j][t])
				{
					change = s[j][i];
					s[j][i] = s[j][t];
					s[j][t]=change;
				}
			}
		}
		for (i = 1; i < n - 1; i++)
		{
			sum[j] += s[j][i];
		}
		sum[j] = sum[j] / (n - 2);
		j++;
	}
	for (i = 0; i < j-1; i++)
	{
		printf("%d\n", sum[i]);
	}
	return 0;
}
