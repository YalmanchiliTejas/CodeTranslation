#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e4 + 7;
const ll mod = 1e9 + 7;


string s;
int d;

ll dp[N][107][2];

ll solve(int idx, int sum, bool good) {
	if (idx == s.size()) {
		return (sum % d == 0);
	}

	if (dp[idx][sum][good] != -1) {
		return dp[idx][sum][good];
	}

	ll ans = 0;
	if (good) {
		for (int i = 0; i < 10; i++) {
			ans += solve(idx+1, (sum + i) % d, good);
			ans %= mod;
		}
	}
	else {
		for (int i = 0; i < (s[idx] - '0'); i++) {
			ans += solve(idx + 1, (sum + i) % d, 1);
			ans %= mod;
		}
		ans += solve(idx + 1, (sum + s[idx] - '0') % d, 0);
		ans %= mod;
	}

	return dp[idx][sum][good] = ans;
}







int main() {
	cin >> s >> d;
	memset(dp, -1, sizeof dp);
	cout << (solve(0, 0, 0) - 1 + mod) % mod;

}