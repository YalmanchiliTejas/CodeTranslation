#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

int main() {
	int n, m;
	cin >> n >> m;
	
	vector< vector< int > > edge(n);
	for_(i,0,m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	vector< vector< int > > dp(1 << n, vector< int >(n, 0));
	dp[1][0] = 1;
	for_(S,1,(1<<n)) for_(v,0,n) {
		for (int u : edge[v]) {
			if (S >> u & 1) continue;
			dp[S | (1 << u)][u] += dp[S][v];
		}
	}	
	cout << accumulate(dp[(1 << n) - 1].begin(), dp[(1 << n) - 1].end(), int()) << endl;
}