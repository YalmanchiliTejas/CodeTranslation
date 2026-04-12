#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll modl = 1e9 + 7;

ll dp[10005][100][2];

ll solve(string& K, int D, int pos, int d, bool restr) {
	if (dp[pos][d][restr] != -1) return dp[pos][d][restr];
	ll ans = 0;
	int mx = (restr) ? K[pos] - '0' : 9;
	int l = K.length();
	if (pos == --l) {

		for (int i = 0; i <= mx; i++) {
			if (i % D == d)
				ans++;
		}
		return dp[pos][d][restr] = ans % modl;

	}

	for (int i = 0; i <= mx; i++) {
		ans = (( ans + solve(K, D, pos + 1, (D + d - i % D) % D, restr && (i == mx))) % modl);
	}

	return dp[pos][d][restr] = ans % modl;
}

int main() {

	memset(dp, -1, sizeof dp);

	string K;
	int D;

	cin >> K;
	cin >> D;


	cout << ((modl + solve(K, D, 0, 0, true) - 1) % modl);
	return 0;
}
