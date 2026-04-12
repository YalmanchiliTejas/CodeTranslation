#include <bits/stdc++.h>
#define MAX (ll)(3e3 + 7)
#define INF (ll)(1e5 + 7)
#define MOD (ll)(998244353)
#define PI (double)(3.14159265)
#define IO ios_base :: sync_with_stdio (false);
#define LOG 20

using namespace std;
using ll = long long;

ll dp[MAX][MAX];
int main () {
	ll n, s;
	cin >> n >> s;
	ll ar[n];
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		dp[i][0] = 1;
		cin >> ar[i];
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < MAX; j++) {
			dp[i][j] %= MOD;
			dp[i + 1][j] += dp[i][j];
			if (j + ar[i] == s) {
				ans += (dp[i][j] * (n - i)) % MOD;
				ans %= MOD;
			}
			if (j + ar[i] < MAX) {
				dp[i + 1][j + ar[i]] += dp[i][j];
			}
		}
	}
	cout << ans << "\n";
}
		
