#include<bits/stdc++.h>
using namespace std;
int a, b, d[12][12], f[107][107];
int read()
{
	int num = 0;
	char c = getchar();
	while (c<'0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int main()
{
	a = read();
	b = read();
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			d[i][j] = read();
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			for (int k = 1; k <= a; k++)
				for (int l = 1; l <= b; l++)
					f[i][j] = max(f[i][j], d[k][l] - i * k - j * l);
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
		{
			int mn = 1e9;
			for (int p = 0; p <= 100; p++)
				for (int q = 0; q <= 100; q++)
					mn = min(mn, f[p][q] + p * i + q * j);
			if (mn != d[i][j])
			{
				printf("Impossible\n");
				return 0;
			}
		}
	printf("Possible\n");
	printf("202 10401\n");
	for (int i = 1; i <= 100; i++)
		printf("%d %d X\n", i, i + 1);
	for (int i = 102; i < 202; i++)
		printf("%d %d Y\n", i, i + 1);
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			printf("%d %d %d\n", i + 1, 202 - j, f[i][j]);
	printf("1 202\n");
	return 0;
}