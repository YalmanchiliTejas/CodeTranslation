//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

int n, par[MAXN], h[MAXN], a[MAXN];
vector<int> adj[MAXN];
bool mark[MAXN];

void dfs(int v = 1, int pr = 0) {
	par[v] = pr;
	h[v] = h[pr] + 1;
	for (auto i : adj[v])
		if (i != pr)
			dfs(i, v);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	dfs();
	iota(a + 1, a + n + 1, 1);
	sort(a + 1 ,a + n + 1, [](int i, int j) { return h[i] < h[j]; });
	for (int i = n; i; i--) {
		int v = a[i];
		if (mark[v])
			continue;
		if (!par[v])
			return cout << "First" << endl, 0;
		if (mark[par[v]])
			return cout << "First" << endl, 0;
		else
			mark[v] = mark[par[v]] = true;
	}
	cout << "Second" << endl;
	return 0;
}
