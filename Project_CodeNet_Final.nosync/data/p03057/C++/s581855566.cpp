#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int N, M;
string S;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> S;
	if (S[0] == 'B') {
		for (char& c : S) {
			c ^= 'B' ^ 'R';
		}
	}
	assert(S[0] == 'R');

	if (S == string(M, S[0])) {
		// there are no consecutive Bs
		array<array<ll, 2>, 2> dp = {};
		dp[0][0] = dp[1][1] = 1;
		for (int i = 1; i < N; i++) {
			array<array<ll, 2>, 2> ndp = {};
			for (int a = 0; a < 2; a++) {
				for (int b = 0; b < 2; b++) {
					for (int c = 0; c < 2; c++) {
						if (b || c) {
							ndp[a][c] = (ndp[a][c] + dp[a][b]) % MOD;
						}
					}
				}
			}
			swap(dp, ndp);
		}

		ll ans = 0;
		for (int a = 0; a < 2; a++) {
			for (int b = 0; b < 2; b++) {
				if (a || b) {
					ans = (ans + dp[a][b]) % MOD;
				}
			}
		}
		cout << ans << endl;
		return 0;
	}

	if (N % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}

	bool foundBlue = false;
	int maxRed = N-1;
	int cntRed = 0;
	for (char c : S) {
		if (c == 'R') {
			cntRed++;
		} else {
			assert(c == 'B');
			if (foundBlue) {
				if (cntRed % 2 == 1) {
					maxRed = min(maxRed, cntRed);
				}
			} else {
				maxRed = min(maxRed, cntRed + 1);
			}
			foundBlue = true;
			cntRed = 0;
		}
	}

	assert(maxRed >= 1);
	maxRed = (maxRed + 1) / 2;
	N /= 2;

	vector<ll> dp(N+1);
	dp[0] = 1;
	ll sum = dp[0];
	for (int i = 1; i <= N; i++) {
		if (i - maxRed - 1 >= 0) sum = (sum - dp[i - maxRed - 1] + MOD) % MOD;
		dp[i] = sum;
		sum = (sum + dp[i]) % MOD;
	}

	ll ans = 0;
	for (int i = 1; i <= maxRed; i++) {
		ans = (ans + i * dp[N - i]) % MOD;
	}
	ans = ans * 2 % MOD;
	cout << ans << endl;

	return 0;
}
