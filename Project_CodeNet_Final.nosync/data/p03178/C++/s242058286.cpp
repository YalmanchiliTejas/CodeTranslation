#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double lld;

const ll mod = 1000000007;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s; int d; cin >> s >> d;
	int k = s.length();

	vector<vector<vector<ll>>> dp(k + 1, vector<vector<ll>>(10, vector<ll>(d, 0)));

	for(int i = 0; i < 10; i++) {
		dp[0][i][i % d]++;
	}

	for(int i = 1; i <= k; i++) {
		for(int j = 0; j < 10; j++) {
			if(j == 0) {
				for(int x = 0; x < d; x++) {
					for(int y = 0; y < 10; y++) {
						dp[i][j][x] += dp[i - 1][y][x];
						dp[i][j][x] %= mod;
					}
				}
				continue;
			}
			for(int x = 0; x < d; x++) {
				dp[i][j][(x + 1) % d] += dp[i][j - 1][x];
			}
		}
	}

	ll ans = 0; int dsum = 0;
	for(int i = 0; i < k; i++) {
		int digit = s[i] - '0';
		for(int j = 0; j < digit; j++) {
			ans = ans + dp[k - 1 - i][j][(d - dsum) % d];
			ans = ans % mod;
		}
		dsum = (dsum + digit) % d;
	}
	ans = ans + (dsum % d == 0 ? 0: mod - 1);
	cout << ans % mod << endl;
}