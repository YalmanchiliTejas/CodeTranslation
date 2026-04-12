#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

typedef long long ll;

int n;
string num;
ll dp[2][4][MAXN];

ll solve(int state, int k, int p) {
	if (p == n) return (k == 0) ? 1 : 0;
	if (k < 0) return 0;
	if (dp[state][k][p] != -1) return dp[state][k][p];
	if (!state) {
		return dp[state][k][p] = 9 * solve(state, k - 1, p+1) + solve(state, k, p+1);
	} else {
		ll dist = num[p] - '0';
		if (dist == 0) {
			return dp[state][k][p] = solve(state, k, p+1);
		} else {
			return dp[state][k][p] = solve(state, k-1, p+1) + (dist - 1) * solve(1 - state, k-1, p+1) + solve(1 - state, k, p + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	int k;
	cin >> num >> k;
	n = (int)num.size();
	
	cout << solve(1, k, 0) << endl;
	return 0;
}
