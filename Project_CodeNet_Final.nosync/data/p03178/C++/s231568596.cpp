#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 10000;
const int MAXD = 100;
int dp[MAXN+1][MAXD][2];

void add_self(int& a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int d;
	cin >> s >> d;
	
	int n = s.length();
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			int k = s[i] - '0';
			add_self(dp[i+1][(j+k)%d][0], dp[i][j][0]);

			for (int x = 0; x < k; x++) {
				add_self(dp[i+1][(j+x)%d][1], dp[i][j][0]);
			}
			
			for (int x = 0; x < 10; x++) {
				add_self(dp[i+1][(j+x)%d][1], dp[i][j][1]);
			}
		}
	}
	
	int answer = (dp[n][0][0] + dp[n][0][1]) % MOD - 1;	// exclude 0
	if (answer < 0) answer += MOD;
	cout << answer << endl;
}
