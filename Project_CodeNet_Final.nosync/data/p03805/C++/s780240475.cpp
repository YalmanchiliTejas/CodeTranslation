#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define endl '\n'
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int n, m;
vector<int>adj[10];
vector<bool>vis(10, false);
int ans;
bool checker() {
	for (int i = 0; i < n; i++) {
		if (!vis[i])return false;
	}
	return true;
}
void dfs(int node) {
	vis[node] = true;
	if (checker())ans++;
	for (auto k : adj[node]) {
		if (!vis[k]) {
			dfs(k);
		}
	}
	vis[node] = false;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0);
	cout << ans << endl;
}