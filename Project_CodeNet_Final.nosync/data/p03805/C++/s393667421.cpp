#include <bits/stdc++.h>
using namespace std;

#define ll long long;
int main() {
	int n,m, cnt = 0;
	cin >> n >> m;
	vector< vector< bool > > adj(n, vector< bool > (n, 0));
	vector< int > pp(n);
	for (int i=0; i<n; i++)	pp[i] = i;
	for (int i=0; i<m; i++) {
		int u,v;
		cin >> u >> v;
		--u,--v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	do {
		if (pp[0] != 0) continue;
		int i;
		for (i=0; i+1<n; i++) if (adj[pp[i]][pp[i+1]] == 0) break;
		if (i == n-1) cnt++;
	}
	while (next_permutation(pp.begin(),pp.end()));
	cout << cnt << '\n';
	return 0;
}
