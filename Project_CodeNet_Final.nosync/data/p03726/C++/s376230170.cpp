#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

const int N = 100 * 1000 + 20;
int n;
vector<int> adj[N];
bool ans;

bool dfs(int v, int par = -1) {
       	int cnt = 0;
	for (auto u: adj[v])
		if (u ^ par)
			cnt += dfs(u, v);
	if (cnt >= 2) {
		ans = true;
		return false;
	}
	return 1 - cnt;
}	

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
	       	int v, u;
		cin >> v >> u;
		adj[--v].push_back(--u);
		adj[u].push_back(v);;
	}
	ans |= dfs(0);
	return cout << (ans? "First": "Second") << endl, 0;
}	
