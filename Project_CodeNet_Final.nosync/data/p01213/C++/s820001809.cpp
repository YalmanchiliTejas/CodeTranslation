#include<iostream>
#include<string>
using namespace std;
int n; string S, dp[320][320];
int dp2[320][320];
inline string LCS(string &a1, string &a2) {
	for (int i = 0; i <= a1.size(); i++) {
		for (int j = 0; j <= a2.size(); j++)dp2[i][j] = -1;
	}
	dp2[0][0] = 0;
	for (int i = 0; i <= a1.size(); i++)dp[i][0] = "";
	for (int i = 0; i <= a2.size(); i++)dp[0][i] = "";
	for (int i = 0; i <= a1.size(); i++) {
		for (int j = 0; j <= a2.size(); j++) {
			if (i < a1.size() && j < a2.size() && a1[i] == a2[j]) {
				if (dp2[i + 1][j + 1] < dp2[i][j] + 1) {
					dp[i + 1][j + 1] = dp[i][j] + a1[i];
					dp2[i + 1][j + 1] = dp2[i][j] + 1;
				}
			}
			if (dp2[i + 1][j] < dp2[i][j]) { dp[i + 1][j] = dp[i][j]; dp2[i + 1][j] = dp2[i][j]; }
			if (dp2[i][j + 1] < dp2[i][j]) { dp[i][j + 1] = dp[i][j]; dp2[i][j + 1] = dp2[i][j]; }
		}
	}
	return dp[a1.size()][a2.size()];
}
int main() {
	while (cin >> S) {
		for (int i = 0; i < 102400; i++)dp[i / 320][i % 320] = "";
		if (S == "#END")break;
		n = S.size(); string V = "";
		for (int i = 1; i < n; i++) {
			string T = S.substr(0, i), U = S.substr(i, n - i);
			string W = LCS(T, U);
			if (V.size() < W.size())V = W;
		}
		cout << V << endl;
	}
	return 0;
}