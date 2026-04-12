#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
	int n; cin >> n;
	int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];

	ll pre_sum[n + 1] = {};
	pre_sum[1] = a[1];
	for (int i = 3; i <= n; i += 2)
		pre_sum[i] = pre_sum[i - 2] + a[i];

	ll dp[n + 1] = {};
	for (int i = 2; i <= n; i++) {
		if (i & 1) {
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		} else {
			dp[i] = max(pre_sum[i - 1], dp[i - 2] + a[i]);
		}
	}

	cout << dp[n];
}