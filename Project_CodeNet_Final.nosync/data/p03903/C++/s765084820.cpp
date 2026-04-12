#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 4e5 + 10;

int n, m, from[MAXN], to[MAXN], w[MAXN], sec[MAXN], q;
int par[MAXN], ss[4010][4010];
ll sm;
vector<pair<int, int>>	adj[MAXN];
bool vis[4010];

bool cmp(int u, int v){return w[u] < w[v];}

int getPar(int v){return par[v]==v?v:par[v]=getPar(par[v]);}

void dfs(int v, int p, int z = -1){
	ss[p][v] = z;
	vis[v] = 1;
	for (auto e:adj[v])
		if (!vis[e.F])
			dfs(e.F, p, max(z, e.S));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> from[i] >> to[i] >> w[i], from[i]--, to[i]--;
	iota(sec, sec + m, 0);
	sort(sec, sec + m, cmp);
	iota(par, par + n, 0);
	for (int i = 0; i < m; i++){
		int e = sec[i];
		int u = from[e], v = to[e];
		int pu = getPar(u), pv = getPar(v);
		if (pu == pv)	continue;
		adj[u].push_back({v, w[e]});
		adj[v].push_back({u, w[e]});
		par[pu] = pv;
		sm += w[e];
	}
	for (int i = 0; i < n; i++){
		memset(vis, 0, sizeof(vis));
		dfs(i, i);
	}
	cin >> q;
	while (q--){
		int u, v;	cin >> u >> v, u--, v--;
		printf("%lld\n", sm - ss[u][v]);
	}
	return 0;
}
