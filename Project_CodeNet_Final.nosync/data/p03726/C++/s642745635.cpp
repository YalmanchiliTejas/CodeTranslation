#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define ld long double

using namespace std;	

const int N = 1e5 + 101;

int n, matching, dead[N];
vector <int> g[N];

void dfs(int v, int p) {
	for (auto u : g[v])
		if (u != p)
			dfs(u, v);
	if (p != 0 && !dead[p] && !dead[v]) {
		matching += 2;
		dead[p] = 1;
		dead[v] = 1;
	}
}

int main() {
	scanf ("%d", &n);
	rep(i, 2, n) {
		int u, v;
		scanf ("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	printf (matching == n ? "Second\n" : "First\n");
	
	return 0;
}
