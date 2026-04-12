#include <algorithm>
#include <cstdio>
int mx[305][305], dis[305][305]; 
int main()
{
	// freopen("ARC089-E.in", "r", stdin); 
	int a, b, n = 300; 
	scanf("%d%d", &a, &b); 
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
			scanf("%d", dis[i] + j); 
	}
	for (int x = 0; x <= 100; x++)
	{
		for (int y = 0; y <= 100; y++)
		{
			for (int i = 1; i <= a; i++)
			{
				for (int j = 1; j <= b; j++)
					mx[x][y] = std::max(mx[x][y], dis[i][j] - (i * x + j * y)); 
			}
		}
	}
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			bool f = false; 
			for (int x = 0; x <= 100 && !f; x++)
			{
				for (int y = 0; y <= 100 && !f; y++)
					f |= mx[x][y] + i * x + j * y == dis[i][j]; 
			}
			if (!f)
			{
				puts("Impossible"); 
				return 0; 
			}
		}
	}
	puts("Possible");
	// return 0; 
	printf("%d %d\n", n, 101 * 101 + 100 * 2);
	for (int i = 1; i <= 100; i++)
		printf("%d %d X\n", i, i + 1);
	for (int i = 1; i <= 100; i++)
		printf("%d %d Y\n", n - i, n - i + 1);
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
			printf("%d %d %d\n", i + 1, n - j, mx[i][j]);
	}
	printf("%d %d\n", 1, n);
	return 0; 
}
