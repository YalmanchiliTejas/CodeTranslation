#include <iostream>
#include <string>

using namespace std;

long long dp[105][2][105];

int main() {
	string N; cin >> N;
	int n = N.size();
	int k; cin >> k;
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int smaller = 0; smaller < 2; ++smaller) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k <= (smaller ? 9 : N[i] - '0'); ++k) {
					dp[i + 1][smaller || k < N[i] - '0'][j + (k ? 1 : 0)] += dp[i][smaller][j];
				}
			}
		}
	}
	cout << dp[n][0][k] + dp[n][1][k] << endl;

	return 0;
}