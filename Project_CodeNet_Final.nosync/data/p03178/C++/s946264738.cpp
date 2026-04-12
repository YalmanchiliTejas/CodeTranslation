#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second

#ifdef LOCAL
#include "/Users/swad/Desktop/CP/debug.h"
#endif

// const int N = int(1e5) + 10;
const int MOD = int(1e9) + 7;



int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	string k; cin >> k;
	int n = k.size();
	reverse(k.begin(), k.end());
	k = "0" + k;
	int d; cin >> d;

	vector<vector<int>> dp1(n, vector<int>(d, 0));
	dp1[0][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int r = 0; r < d; r++) {
			for (int digit = 0; digit < 10; digit++) {
				(dp1[i][r] += dp1[i - 1][(r - digit % d + d) % d]) %= MOD;
			}
		}
	}

	vector<vector<int>> dp2(n + 1, vector<int>(d, 0));
	dp2[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int r = 0; r < d; r++) {
			dp2[i][r] = dp2[i - 1][(r - (k[i] - '0') + d) % d];
			for (int digit = 0; digit < k[i] - '0'; digit++) {
				(dp2[i][r] += dp1[i - 1][(r - digit % d + d) % d]) %= MOD;
			}
		}
	}

	cout << (dp2[n][0] + MOD - 1) % MOD << endl;

	return 0;
}