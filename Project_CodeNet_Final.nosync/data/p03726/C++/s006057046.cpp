//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()
#define pb push_back

#define error(x) cout << #x << " = " << x << endl

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 1e5 + 20;
int n, sz[N];
vector <int> g[N];

void dfs (int v, int par = -1)
{
	sz[v] = 1;

	int cnt = 0;

	for (int u : g[v])
	{
		if (u == par) continue;

		dfs(u, v);

		cnt += (sz[u] & 1);

		sz[v] += sz[u];
	}

	if (cnt >= 2)
	{
		cout << "First\n";
		exit(0);
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0, u, v; i < n - 1; i++)
	{
		cin >> u >> v;
		u--, v--;

		g[u].pb(v);
		g[v].pb(u);
	}

	if (n & 1) return cout << "First\n", 0;

	dfs(0);

	cout << "Second\n";
}
