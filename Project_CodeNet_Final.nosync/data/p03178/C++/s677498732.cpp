#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
string K;
int D, dp[10002][101][2];

int solve (int i, int rem, bool f) {
	if (dp[i][rem][f] != -1) return dp[i][rem][f];
	if (i == (int)K.length()) return dp[i][rem][f] = (rem == 0);
	int ret = 0;
	if (f)
		for (int j=0; j<10; ++j)
			ret = (ret + solve(i + 1, (rem + j) % D, 1)) % M;
	else {
		ret = (ret + solve(i + 1, (rem + (K[i]-'0')) % D, 0)) % M;
		for (int j=0; j<(K[i]-'0'); ++j)
			ret = (ret + solve(i + 1, (rem + j) % D, 1)) % M;
	}
	return dp[i][rem][f] = ret;
}

int main ()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> D;
	memset(dp, -1, sizeof(dp));
	cout << max(0, (solve(0, 0, 0) - 1 + M) % M) << '\n';
	return 0;
}
