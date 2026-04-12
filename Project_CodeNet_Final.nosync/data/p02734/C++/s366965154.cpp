#include <bits/stdc++.h>
#define ll long long
#define M 33010
#define rep(i, a, b) for (int i = a; i<= b; ++i)
using namespace std;
const ll mod = 998244353;
ll n, s, a[M], dp[M], ans;

int main() {
	int n, s; cin >> n >> s;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) {
		for (int j = s; j >= a[i]; --j) {
			dp[j] += dp[j - a[i]];
			dp[j] %= mod;
		}
		if (a[i] <= s) dp[a[i]] = (dp[a[i]] + i) % mod;
		ans = (ans + dp[s]) % mod;
	}
	cout << ans;
}