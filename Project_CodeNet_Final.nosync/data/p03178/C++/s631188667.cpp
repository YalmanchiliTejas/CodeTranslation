#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

string s;
int d;
const ll mod = 1e9 + 7;
const ll N = 1e4 + 7;

ll dp[N][107][2];

ll solve(int idx, int sum, bool less) {
	if (idx == s.size()) {
		return (sum%d == 0);
	}

	ll& ans = dp[idx][sum][less];
	if (~ans) {
		return ans;
	}
	ans = 0;
	if (less) {
		for (int i = 0; i < 10; i++) {
			ans += solve(idx + 1, (sum + i) % d, less);
			ans %= mod;
		}
	}
	else {
		for (int i = 0; (i + '0') < s[idx]; i++) {
			ans += solve(idx + 1, (sum + i) % d, 1);
			ans %= mod;
		}
		ans += solve(idx + 1, (sum + s[idx] - '0') % d, 0);
		ans %= mod;
	}
	return ans;
}





int main() {
	cin >> s >> d;
	memset(dp, -1, sizeof dp);
	cout << (solve(0, 0, 0) - 1 + mod) % mod;


}