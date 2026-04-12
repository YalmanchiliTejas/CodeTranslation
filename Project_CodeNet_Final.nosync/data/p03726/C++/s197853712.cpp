#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int infint = 1e9;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 7;
int n, dp1[MAXN], dp2[MAXN];
vector<int> G[MAXN];
void dfs(int v, int p)
{
	int sm = 0;
	for (auto u : G[v])
		if(u != p)
		{
			dfs(u, v);
			dp2[v] += max(dp1[u], dp2[u]);
			sm += max(dp1[u], dp2[u]);
		}
	int mx = 0;
	for (auto u : G[v])
		if(u != p)
			mx = max(mx, 1 + dp2[u] + sm - max(dp1[u], dp2[u]));
	dp1[v] = mx;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, -1);
	int match = max(dp1[1], dp2[1]);
	if(match == n / 2 && n % 2 == 0)
		return cout << "Second", 0;
	cout << "First";
}