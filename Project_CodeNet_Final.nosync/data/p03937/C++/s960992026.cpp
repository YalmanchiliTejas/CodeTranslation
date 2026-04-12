#include <bits/stdc++.h>
using namespace std;
int A[10][10], Vis[10][10];
int N, M, fl;
inline int safe_getchar()
{
	char ch = getchar();
	while (ch != '#' && ch != '.') ch = getchar();
	return ch == '#';
}
inline void dfs(int x, int y)
{
	if (Vis[x][y]) return ;
	Vis[x][y] = 1;
	if (x == N && y == M) { fl = 1;Vis[x][y] = 2; return ;}
	int sum = 0;
	if (A[x + 1][y]) dfs(x + 1, y), ++sum;
	if (A[x][y + 1]) dfs(x, y + 1), ++sum;
	if (fl) Vis[x][y] = 2;
	if (sum == 2)
	{
		puts("Impossible");
		exit(0);
	}
}
int main()
{
#ifdef hk_cnyali
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			A[i][j] = safe_getchar();
	dfs(1, 1);
	if (!fl)
	{
		puts("Impossible");
		return 0;
	}
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (Vis[i][j] != 2 && A[i][j])
			{
				puts("Impossible");
				return 0;
			}
	puts("Possible");
	return 0;
}