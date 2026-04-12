#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > G;

int dfs(int, int *, int, int);

int main()
{
	int N, M;
	cin >> N >> M;

	G.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;

		G[x].push_back(y);
		G[y].push_back(x);
	}

	int vis[N + 1];
	memset(vis, 0, sizeof(vis));

	cout << dfs(1, vis, 1, N) << endl;

	return (0-0);
}

int dfs(int node, int * vis, int depth, int N)
{
	if (depth == N)
		return 1;

	vis[node] = 1;

	int ans = 0;

	for (int i = 0; i < G[node].size(); i++) {
		int adj = G[node][i];

		if (not vis[adj]) {
			ans += dfs(adj, vis, depth + 1, N);
		}
	}

	vis[node] = 0;

	return ans;
}