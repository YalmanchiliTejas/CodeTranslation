#include <bits/stdc++.h>

using namespace std;

typedef vector< vector<int> > Graph;

int n, m;
Graph g;

bool judge(vector<int>& route) {
	if (route[0] != 0) return false;
	for (int i = 1; i < n; i++) {
		if (find(g[route[i - 1]].begin(), g[route[i - 1]].end(), route[i]) != g[route[i - 1]].end()) continue;
		return false;
	}
	return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
 	vector<int> route(n);
	for (int i = 0; i < n; i++) route[i] = i;
	int ans = 0;
	do {
		ans += judge(route);
	} while (next_permutation(route.begin(), route.end()));
	cout << ans << endl;
	return 0;
}