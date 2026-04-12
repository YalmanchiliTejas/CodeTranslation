#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 200;
const int MAXK = 100;

int main() {
	string s;
	int k;
	cin >> s >> k;
	vector<vector<vector<int>>> dp(s.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
	// empty string without non-zero digit equal is 1
	dp[0][0][1] = 1;

	for (int i = 1; i <= s.size(); ++i) {
		// current digit
		int cur = s[i - 1] - '0';

		for (int j = 0; j <= k; ++j) {
			// fill 0 to smaller
			dp[i][j][0] = dp[i - 1][j][0];

			// fill 1-9 to smaller
			if (j) {
				dp[i][j][0] += dp[i - 1][j - 1][0] * 9;
			}

			// fill 0 to equal if cur > 0
			if (cur) {
				dp[i][j][0] += dp[i - 1][j][1];
			}

			// fill 1 to (cur-1) to equal
			if (cur > 1 && j) {
				dp[i][j][0] += dp[i - 1][j - 1][1] * (cur - 1);
			}

			// fill cur to equal
			if (cur) {
				if (j) {
					dp[i][j][1] += dp[i - 1][j - 1][1];
				}
			}
			else {
				dp[i][j][1] += dp[i - 1][j][1];
			}
		}
	}
	cout << dp[s.size()][k][0] + dp[s.size()][k][1] << endl;
	return 0;
}