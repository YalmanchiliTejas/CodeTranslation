#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int n, m;
string s;
int dp[212123];
int dpsum[212123];
bool nonmono;

// msize EVEN
void non(int msize) {
	assert(msize % 2 == 0);
	dp[0] = 1;
	dpsum[0] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dpsum[i-2];
		if (i-msize-2 >= 0) {
			dp[i] += MOD - dpsum[i-msize-2];
			dp[i] %= MOD;
		}
		dpsum[i] = (dp[i] + dpsum[i-2]) % MOD;
	}
	int ans = dp[n];
	for (int i = 1; i < n; i++) {
		// first colour must be i + 1 + evener
		int x = i + 1;
		if (x % 2 != 0) x++;
		// x now even
		if (x > msize) break;
		ans = (ans + dpsum[n-x]) % MOD;
		if (n-msize-2 >= 0) {
			ans += MOD - dpsum[n-msize-2];
			ans %= MOD;
		}
	}
	cout << ans << '\n';
}

void mono() {
	dp[0] = 1;
	dpsum[0] = 1;
	dpsum[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dpsum[i-2];
		dpsum[i] = (dpsum[i-1] + dp[i]) % MOD;
	}
	int ans = dp[n] + 1;
	for (int i = 0; i <= n-2; i++) {
		ans = (ans + dpsum[i]) % MOD;
	}
	cout << ans << '\n';
}

int main() {
	cin >> n >> m >> s;
	for (int i = 1; i < m; i++) {
		if (s[i] != s[0]) {
			nonmono = true;
			break;
		}
	}
	if (nonmono) {
		int msize = n;
		if (msize % 2 == 1) msize--;
		int fcur = -1;
		int cur = 0;
		for (int i = 0; i < m; i++) {
			if (s[i] == s[0]) cur++;
			else if (cur) {
				if (fcur == -1) fcur = cur;
				if (cur % 2 == 1) {
					cur++;
					msize = min(msize, cur);
				}
				cur = 0;
			}
		}
		fcur += 2;
		if (fcur % 2 == 1) fcur--;
		msize = min(fcur, msize);
		//cout << msize << '\n';
		non(msize);
	} else {
		mono();
	}
	return 0;
}

