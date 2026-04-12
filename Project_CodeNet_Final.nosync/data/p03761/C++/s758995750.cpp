#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string *S;

int dp[51][51];
string dp2[51][51];

string func(string x, string y)
{
	for (int i = 0; i < 51; ++i) {
		for (int j = 0; j < 51; ++j) {
			dp[i][j] = 0;
			dp2[i][j] = "";
		}
	}

	for (unsigned int i = 0; i < x.length(); i++) {
		for (unsigned int j = 0; j < y.length(); j++) {
			if (x[i] == y[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				dp2[i + 1][j + 1] = dp2[i][j] + x[i];
			} else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				if (dp[i][j + 1] > dp[i + 1][j]) {
					dp2[i + 1][j + 1] = dp2[i][j + 1];
				} else {
					dp2[i + 1][j + 1] = dp2[i + 1][j];
				}
			}
		}
	}
	return dp2[x.length()][y.length()];
}

int main(void)
{

	cin >> n;
	S = new string[n];
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
		sort(S[i].begin(), S[i].end());
	}
	
	for (int j = 0; j < n - 1; ++j) {
		for (int i = 1; i < n; ++i) {
			S[i] = func(S[j], S[i]);
		}
	}

	cout << S[n-1] << endl;

	return 0;
}