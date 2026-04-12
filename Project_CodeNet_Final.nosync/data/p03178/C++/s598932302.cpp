#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
const int MAXD = 105;
const int MAXP = 10005;
const LL MOD = 1000000007;

string K;
int N, D, dp[MAXP][MAXD];

int dfs(int pos, int rem, bool lim) {
	if (pos == N) return rem == 0;
	if (!lim && dp[pos][rem] != -1) return dp[pos][rem];

	int to = lim ? K[pos] + 1 : 10, res = 0;
	for (int i = 0; i < to; i++) {
		res = (res + dfs(pos + 1, (rem + i) % D, lim && i == K[pos])) % MOD;
	}
	
	if (!lim) dp[pos][rem] = res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	memset(dp, -1, sizeof(dp));
	
	cin >> K >> D;
	N = K.size();
	for (char &c : K) c -= '0';
	cout << (dfs(0, 0, true) - 1 + MOD) % MOD << "\n";
}
