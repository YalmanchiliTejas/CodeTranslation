#include<stdio.h>

int main(void)
{
	int n;
	const int N = 15;
	while(scanf("%d", &n), n)
	{
		const int n2 = n*n;
		int a[N][N] = {0};
		int i = (n>>1)+1,
			j = n>>1;
		int d = 1;
		while(d <= n2)
		{
			if(!a[i][j])
			{
				a[i][j] = d;
				d++;
				i = (i+1)%n;
				j = (j+1)%n;
			}
			else
			{
				i = (i+1)%n;
				j = (j-1+n)%n;
			}
		}
		for(i = 0; i < n; ++i)
		{
			for(j = 0; j < n; ++j)
				printf("%4d", a[i][j]);
			putchar('\n');
		}
	}
	return 0;
}