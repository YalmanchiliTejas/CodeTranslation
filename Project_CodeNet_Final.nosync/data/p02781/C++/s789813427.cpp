#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < (int) b; i++)
#define F0R(i, a) FOR (i, 0, a)
#define GO(to, a) for (auto to : a)

#define f first
#define s second
#define eb emplace_back
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()

int k;
int dp [105][5];

string cur;

int solve (int n, int m, bool tight) {
	if (m > k) return 0;
	if (n < 0) {
		return (m == k);
	}
	if (tight && ~dp[n][m]) return dp[n][m];
	int tot = 0;
	int lim = cur[n] - '0';
	for (int i = 0; i <= (tight ? 9 : lim); i++) {
		if (i) {
			tot += solve (n - 1, m + 1, tight | (i < lim));
		} else {
			tot += solve (n - 1, m, tight | (i < lim));
		}
	}
	return (tight ? dp[n][m] = tot : tot);
}

void GetSolve (string w) {
	memset (dp, -1, sizeof(dp));
	cur = w;
	reverse (all(cur));
	cout << solve (sz(w) - 1, 0, false) << '\n';
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string w;
	cin >> w >> k;
	GetSolve (w);
  return 0;
}