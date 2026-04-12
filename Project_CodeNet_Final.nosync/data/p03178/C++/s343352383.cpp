#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
void add(int &a, int b) {
	a = (a + b);
	if (a >= MOD)a -= MOD;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S;
	cin >> S;
	int N = S.size();
	int D;
	cin >> D;
	vector<vector<vector<int> > > dp(N + 1, vector<vector<int> >(D, vector<int>(2, 0)));
	dp[0][0][1] = 1;
	for (int i = 0; i < N; i++) {
		for (int d = 0; d < D; d++) {
			for (int j = 0; j < S[i] - '0'; j++) {
				add(dp[i + 1][(d + j) % D][0], dp[i][d][1]);
			}
			{
				int j = S[i] - '0';
				add(dp[i + 1][(d + j) % D][1], dp[i][d][1]);
			}
			for (int j = 0; j < 10; j++) {
				add(dp[i + 1][(d + j) % D][0], dp[i][d][0]);
			}
		}


	}
	int res = (dp[N][0][0] + dp[N][0][1] - 1 + MOD) % MOD;
	cout << res << endl;
}