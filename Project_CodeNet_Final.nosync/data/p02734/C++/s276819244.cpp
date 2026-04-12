#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define ll long long
#define SIZE 3010
#define rep(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
void io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
const ll mod = 998244353;
ll n, s, a[SIZE], dp[SIZE], ans;

int main() {
	io(); cin >> n >> s;
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