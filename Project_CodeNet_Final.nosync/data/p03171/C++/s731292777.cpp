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
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<vector<int> >dp(N, vector<int>(N, 0));
	if (N % 2 == 0) {
		for (int i = 0; i < N; i++) {
			dp[i][i] = -A[i];
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			dp[i][i] = A[i];
		}
	}
	for (int l = 2; l <= N; l++) {
		for (int i = 0; i + l - 1 < N; i++) {
			if ((l + N) % 2 == 0) {
				dp[i][i + l - 1] = max(A[i] + dp[i + 1][i + l - 1],
					A[i + l - 1] + dp[i][i + l - 1 - 1]);
			}
			else {
				dp[i][i + l - 1] = min(-A[i] + dp[i + 1][i + l - 1],
					-A[i + l - 1] + dp[i][i + l - 1 - 1]);
			}
		}
	}
	cout << dp[0][N - 1] << endl;
}