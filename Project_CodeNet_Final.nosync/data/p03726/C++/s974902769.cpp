#include "bits/stdc++.h"
using namespace std;
int dp[2][100010];
vector <int> g[100010];
const int inf = 100000000;

int dfs(int x, int par) {
	dp[0][x] = dp[1][x] = 0;
	int mx = -inf;
	for(auto i : g[x]) {
		if(i == par) continue;
		dfs(i, x);
		dp[1][x] += dp[0][i];
		mx = max(mx, dp[1][i] - dp[0][i]);
	}
	dp[0][x] = max(dp[1][x], 1 + (dp[1][x] + mx)); 
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		g[p].push_back(q);
		g[q].push_back(p);
	}
	dfs(1, 0);
	int matching = dp[0][1];
	if((matching << 1) == n) printf("Second\n");
	else printf("First\n");
	return 0;
}