#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int a[200005];
long long dp[200005][3];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	int k = 1 + n % 2;
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = -INF;
		}
	}
	
	dp[0][0] = 0LL;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp[i][j] == -INF) continue;
			// skip
			if (j + 1 <= k) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
			}
			
			// no skip
			if ((i + j) % 2 == 0) {
				// pick
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1]);
			}
			else {
				// no pick
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			}
		}
	}
	
	printf("%lld\n", dp[n][k]);
}
