#include <algorithm>
#include <cstdio>
int mn[305][305], dis[305][305]; 
int main()
{
	int a, b; 
	scanf("%d%d", &a, &b); 
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			scanf("%d", dis[i] + j); 
			for (int x = 0; x <= 100; x++)
			{
				for (int y = 0; y <= 100; y++)
					mn[x][y] = std::max(mn[x][y], dis[i][j] - i * x - j * y); 
			}
		}
	}
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			bool f = false; 
			for (int x = 0; x <= 100; x++)
			{
				for (int y = 0; y <= 100; y++)
					f |= mn[x][y] + i * x + j * y == dis[i][j]; 
			}
			if (!f)
			{
				puts("Impossible"); 
				return 0; 
			}
		}
	}
	puts("Possible"); 
	printf("%d %d\n", 202, 101 * 101 + 100 * 2);
	for (int i = 1; i <= 100; i++)
		printf("%d %d X\n", i, i + 1);
	for (int i = 1; i <= 100; i++)
		printf("%d %d Y\n", i + 101, i + 102);
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
			printf("%d %d %d\n", i + 1, 202 - j, mn[i][j]);
	}
	puts("1 202"); 
	return 0;
}
