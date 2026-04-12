#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

const long long MAXN = 1e5 + 21, inf = 1e18 + 21, LG = 21;

bool vis[MAXN];
int n;
int par[MAXN], h[MAXN], ind[MAXN];
vector<int> adj[MAXN];

bool cmp(int i, int j) {
    return h[i] < h[j];
}

void dfs(int root, int pr = 0) {
    h[root] = h[pr] + 1;
    par[root] = pr;
    for (auto y: adj[root])
	if (y ^ pr)
	    dfs(y, root);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    if (n % 2)
	return cout << "First" << '\n', 0;

    for (int i = 1; i < n; i++) {
	int v, u;
	cin >> u >> v;
	adj[u].pb(v);
	adj[v].pb(u);
	ind[i] = i;
    }

    ind[n] = n;

    dfs(1);

    sort(ind + 1 , ind + n + 1, cmp);

    for (int i = n; i; i--) {
	int v = ind[i];
	if (vis[v])
	    continue;
	if (par[v] == 0)
	    return cout << "First" << '\n', 0;
	if (vis[par[v]])
	    return cout << "First" << '\n', 0;
	else {
	    vis[v] = true;
	    vis[par[v]] = true;
	}
    }

    cout << "Second" << '\n';
    return 0;
}

