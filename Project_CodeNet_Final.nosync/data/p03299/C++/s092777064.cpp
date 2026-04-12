
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int n, m, l[105], r[105];
ll h[105], a[105], dp[105][2];
ll Pow(ll a, int x) {
	ll res = 1;
	while (x) {
		if (x & 1) (res *= a) %= mod;
		(a *= a) %= mod;
		x >>= 1; 
	}
	return res;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		a[i] = h[i];
	}
	sort(a + 1, a + 1 + n);
	m = unique(a + 1, a + 1 + n) - a - 1;
	for (int i = m; i >= 1; i--) {
		for (int j = 1; j <= n; j++) {
			if (h[j] > a[i]) {
				if (h[j - 1] > a[i]) {
					dp[j][0] = dp[j - 1][0];
					dp[j][1] = dp[j - 1][1];
				}
				if (h[j - 1] == a[i]) {
					dp[j][0] = (dp[j][0] + dp[j][1]) % mod;
					dp[j][1] = (2 * dp[j][1]) % mod;
					dp[j][0] = dp[j - 1][0] * dp[j][0] % mod;
					dp[j][1] = dp[j - 1][1] * dp[j][1] % mod * Pow(2, mod - 2) % mod;
				}
				if (h[j - 1] < a[i]) {
					dp[j][0] = (dp[j][0] + dp[j][1]) % mod;
					dp[j][1] = (2 * dp[j][1]) % mod;
				}
			}
			if (h[j] == a[i]) {
				if (h[j - 1] >= h[j]) {
					dp[j][0] = dp[j - 1][0] * 2 % mod;
					dp[j][1] = dp[j - 1][1];
				} 
				else {
					dp[j][0] = 2;
					dp[j][1] = 2;
				}
			}
		}
		for (int j = n; j >= 1; j--) {
			if (h[j] >= a[i] && h[j + 1] >= a[i]) {
				dp[j][0] = dp[j + 1][0];
				dp[j][1] = dp[j + 1][1];
			}
		}
		for (int j = n; j >= 1; j--) {
			int k = a[i] - a[i - 1] - 1;
			dp[j][0] = (dp[j][0] + dp[j][1] * (Pow(2, k) - 1) % mod) % mod,
			dp[j][1] = dp[j][1] * Pow(2, k) % mod;
		}
	}
	cout << dp[1][0];
}
