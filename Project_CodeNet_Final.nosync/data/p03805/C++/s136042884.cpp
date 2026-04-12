#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;
ll ans = 0;
vector<vector<bool>> v;

void dfs(ll now, set<ll> visited) {
	if (visited.find(now) != visited.end())return;
	visited.insert(now);
	if (visited.size() == n) {
		++ans;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (v[now][i])dfs(i, visited);
	}
}

int main() {
	cin >> n >> m;
	vector<bool> tmp(n, false);
	v.resize(n, tmp);
	for (ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		--a; --b;
		v[a][b] = true;
		v[b][a] = true;
	}
	dfs(0, {});
	cout << ans << endl;
}