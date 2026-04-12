#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> s(n);
	rep(i, 0, n) cin >> s[i];
	ll ans = 0;
	rep(i, 1, n) {
		int l = i, r = n - 1 - i;
		vector<ll> dp(n / i); dp[0] = 0;
		int idx = 1;
		while (l != r && l != r + i)
		{
			dp[idx] = dp[idx - 1] + s[l] + s[r];
			ans = max(ans, dp[idx]);
			idx++; l += i; r -= i;
			if (r <= 0 || r <= i) break;
		}
	}
	printf("%lld", ans);
	return 0;
}
