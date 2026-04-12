#include <iostream>
using namespace std;
const long long INF = 1LL << 60;
long long a[3001];
long long dp[2][3001][3001];
long long calc(int who, int i, int j) {
	if (who == 0) {
		if (dp[0][i][j] != -INF) return dp[0][i][j];
		if (i == j) return dp[0][i][j] = a[i];
		return dp[0][i][j] = max(calc(1, i + 1, j) + a[i], calc(1, i, j - 1) + a[j]);
	} else {
		if (dp[1][i][j] != INF) return dp[1][i][j];
		if (i == j) return dp[1][i][j] = -a[i];
		return dp[1][i][j] = min(calc(0, i + 1, j) - a[i], calc(0, i, j - 1) - a[j]);
	}
}
int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			dp[0][i][j] = -INF;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			dp[1][i][j] = INF;
		}
	}
	cout << calc(0, 1, N) << endl;
}
