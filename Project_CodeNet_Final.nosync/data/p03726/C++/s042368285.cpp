#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100000;

int n;
vector<int> adj[MaxN + 1];

int f[MaxN + 1][2];

void dfs(int u, int fa)
{
	f[u][0] = 0;
	f[u][1] = 1;

	for (int v : adj[u])
		if (v != fa)
		{
			dfs(v, u);
			f[u][0] += f[v][1];
			f[u][1] += min(f[v][0], f[v][1]);
		}
}

int main()
{
	while (cin >> n)
	{
		for (int u = 1; u <= n; ++u)
			adj[u].clear();
		for (int i = 1; i < n; ++i)
		{
			int u = getint(), v = getint();
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(1, 0);

		int n_matches = min(f[1][0], f[1][1]);
		if (n_matches * 2 == n)
			puts("Second");
		else
			puts("First");
	}

	return 0;
}