#include<bits/stdc++.h>

using namespace std;

#define N 105

int n, m, d[N][N], f[N][N];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &d[i][j]);
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
			for(int x = 1; x <= n; x++)
				for(int y = 1; y <= m; y++)
					f[i][j] = max(f[i][j], d[x][y] - i * x - j * y);
	for(int x = 1; x <= n; x++)
		for(int y = 1; y <= m; y++)
		{
			int res = INT_MAX;
			for(int i = 0; i <= 100; i++)
				for(int j = 0; j <= 100; j++)
					res = min(res, f[i][j] + i * x + y * j);
			// cout << x << ' ' << y << ' ' << res << endl;
			if(d[x][y] != res) 
			{
				printf("Impossible\n");
				return 0;
			}
		}
	printf("Possible\n");
	printf("202 %d\n", 101 * 101 + 200);
	for(int i = 1; i <= 100; i++) printf("%d %d X\n", i, i + 1);
	for(int i = 102; i < 202; i++) printf("%d %d Y\n", i, i + 1);
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
			printf("%d %d %d\n", i + 1, 202 - j, f[i][j]);
	printf("1 202\n");
	return 0;
}