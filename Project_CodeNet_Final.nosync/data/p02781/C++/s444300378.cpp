#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 200;
const int MAXK = 100;

int main() {
	string s;
	int k;
	cin >> s >> k;
	int dp[MAXN][MAXK + 1][2];
	memset(dp, 0, sizeof(dp));
	dp[0][0][1] = 1;
	for (int i = 1; i <= s.size(); ++i) {
		dp[i][0][0] = 1;
		dp[i][0][1] = 0;
		for (int j = 1; j <= k; ++j) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j - 1][0] * 9;
			if (s[i - 1] == '0') {
				dp[i][j][1] = dp[i - 1][j][1];
			}
			else {
				dp[i][j][1] = dp[i - 1][j - 1][1];
				dp[i][j][0] += dp[i - 1][j - 1][1] * (s[i - 1] - '0' - 1) + dp[i - 1][j][1];
			}
		}
	}
	cout << dp[s.size()][k][0] + dp[s.size()][k][1] << endl;
	return 0;
}