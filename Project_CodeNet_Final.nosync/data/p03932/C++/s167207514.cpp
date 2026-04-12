#include<bits/stdc++.h>
using namespace std;

int dp[200][200][200];
int a, b;
int c[200][200];
int dx[2] = { -1,0 }, dy[2] = { 0,-1 };
int saiki(int d, int e, int f, int g) {
	if (dp[d][e][f] != -1)return dp[d][e][f];
	for (int h = 0; h < 2; h++) {
		for (int i = 0; i < 2; i++) {
			int n = d + dx[h], m = e + dy[h];
			if (n < 0 || m < 0)continue;
			int x = f + dx[i], y = g + dy[i];
			if (x < 0 || y < 0)continue;
			int S = saiki(n, m, x, y);
			S += c[d][e]; S += c[f][g];
			if (d == f&&e == g)S -= c[d][e];
			dp[d][e][f] = max(dp[d][e][f], S);
		}
	}
	return dp[d][e][f];
}
signed main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &a, &b);
	for (int d = 0; d < a; d++) {
		for (int e = 0; e < b; e++) {
			scanf("%d", &c[d][e]);
		}
	}
	dp[0][0][0] = c[0][0];
	printf("%d\n", saiki(a - 1, b - 1, a - 1, b - 1));
}