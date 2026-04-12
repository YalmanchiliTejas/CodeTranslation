#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

ll n, m;
vector<bool> seen;

void dfs(const Graph &G, ll v, ll &count)
{
	bool is_end = true;
	for (int i = 0; i < n; ++i)
	{
		if (i == v) continue;
		if (!seen[i])
			is_end = false;
	}
	if (is_end)
	{
		++count;
		return;
	}

	seen[v] = true;
	for (auto nv : G[v])
	{
		if (seen[nv]) continue;
		dfs(G, nv, count);
	}
	seen[v] = false;
}


int main(int argc, char **argv)
{
	cin >> n >> m;
	Graph G(m+1);

	for (int i = 1; i < m+1; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}

	seen.assign(m, false);
	ll count{0};
	dfs(G, 0, count);
	std::cout << count << std::endl;
}
