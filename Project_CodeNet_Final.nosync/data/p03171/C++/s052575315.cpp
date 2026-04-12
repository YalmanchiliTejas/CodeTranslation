#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 3003;
ll dp[N][N];
int a[N];

int main() {
	int n;
	scanf("%d", &n);
	bool b = n & 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		dp[i][i] = b ? a[i] : -a[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int l = 0, r = i - 1; r < n; l++, r++) {
			if (b ^ (i & 1)) {
				dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r]);
			} else {
				dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r]);
			}
		}
	}
	printf("%lld", dp[0][n-1]);
	return 0;
}
