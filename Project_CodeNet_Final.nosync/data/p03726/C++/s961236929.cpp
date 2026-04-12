#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr, args)
const int maxn = 1e5 + 10;

int n;
vector <int> adj[maxn];

int dp[2][maxn];

void dfs (int v, int par)
{
	dp[0][v] = 1;

	int x = 0;
	bool y = false;

	for (int i = 0; i < adj[v].size(); ++i)
	{
		int u = adj[v][i];

		if (u == par)
			continue;

		dfs (u, v);

		if (!dp[1][u])
		{
			dp[0][v] = 0;
			
			if (!x)
				x = u;
			else
				y = true;
		}
	}

	if (y)
	{
		debug ("%d. %d %d\n", v, dp[0][v], dp[1][v]);
		return;
	}

	for (int i = 0; i < adj[v].size(); ++i)
	{
		int u = adj[v][i];

		if (u == par)
			continue;

		if (dp[0][u] && (!x || x == u))
			dp[1][v] = 1;
	}

	debug ("%d. %d %d\n", v, dp[0][v], dp[1][v]);
}

int main ()
{
	scanf ("%d", &n);

	for (int i = 1; i <= n - 1; ++i)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		adj[a].push_back (b);
		adj[b].push_back (a);
	}

	dfs (1, -1);

	debug ("%d %d\n", dp[0][1], dp[1][1]);

	if (dp[1][1])
		printf ("Second\n");
	else
		printf ("First\n");

	return 0;
}