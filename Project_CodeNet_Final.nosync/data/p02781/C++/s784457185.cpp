#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long mod = 1000000007;

string S;
int N, K, A[1009];
long long dp[1009][5][2];

int main() {
	cin >> S >> K; N = S.size();
	for (int i = 0; i < S.size(); i++) A[i] = (S[N - 1 - i] - '0');

	dp[101][0][1] = 1;
	for (int i = 100; i >= 0; i--) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k < 2; k++) {
				if (dp[i + 1][j][k] == 0) continue;

				for (int l = 0; l < 10; l++) {
					if (k == 1 && l > A[i]) continue;
					int c1 = i, c2 = j, c3 = k;
					if (l != 0) c2 += 1;
					if (k == 1 && l < A[i]) c3 = 0;
					dp[c1][c2][c3] += dp[i + 1][j][k];
				}
			}
		}
	}

	cout << dp[0][K][0] + dp[0][K][1] << endl;
	return 0;
}