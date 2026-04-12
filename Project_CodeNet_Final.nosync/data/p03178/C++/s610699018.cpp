#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;
constexpr int MAX = 10010;

string s;
int d;
ll dp[10010][2][101];

int main() {
	cin >> s >> d;
	dp[0][0][0] = 1;
	int n = s.size();
	REP(i, n) {
		int now = s[i] - '0';

		// from j = 0
		REP(j, d + 1) {
			REP(k, now) (dp[i + 1][1][(j + k) % d] += dp[i][0][j]) %= MOD;
			(dp[i + 1][0][(j + now) % d] += dp[i][0][j]) %= MOD;
		}

		// from j = 1
		REP(j, d + 1) 
			REP(k, 10) (dp[i + 1][1][(j + k) % d] += dp[i][1][j]) %= MOD;
	}
	cout << ((dp[n][0][0] + dp[n][1][0]) % MOD + MOD - 1) % MOD;
	return 0;
}