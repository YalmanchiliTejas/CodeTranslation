#include <string>
#include <iostream>
using namespace std;
int n; string s, dp[309][309];
int main() {
	while (cin >> s, s != "#END") {
		n = s.size();
		string ret;
		for (int i = 1; i < n; i++) {
			string l = s.substr(0, i), r = s.substr(i, n - i);
			for (int j = 1; j <= i; j++) {
				for (int k = 1; k <= n - i; k++) {
					if (l[j - 1] == r[k - 1]) dp[j][k] = dp[j - 1][k - 1] + r[k - 1];
					else if (dp[j][k - 1].size() > dp[j - 1][k].size()) dp[j][k] = dp[j][k - 1];
					else dp[j][k] = dp[j - 1][k];
				}
			}
			if (ret.size() < dp[i][n - i].size()) ret = dp[i][n - i];
		}
		cout << ret << endl;
	}
}