#include <iostream>
#include <algorithm>
using namespace std;

long long dp[3009][3009], N, A[3009];

long long dfs(int L, int R) {
	if (L > R) return 0;
	if (dp[L][R] != (1LL << 60)) return dp[L][R];

	if ((R - L) % 2 == (N - 1) % 2) {
		// 先手
		long long A1 = A[L] + dfs(L + 1, R);
		long long A2 = A[R] + dfs(L, R - 1);

		dp[L][R] = max(A1, A2);
		return dp[L][R];
	}
	else {
		// 後手
		long long A1 = -A[L] + dfs(L + 1, R);
		long long A2 = -A[R] + dfs(L, R - 1);

		dp[L][R] = min(A1, A2);
		return dp[L][R];
	}
}

int main() {
	for (int i = 0; i < 3009; i++) { for (int j = 0; j < 3009; j++) dp[i][j] = (1LL << 60); }

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cout << dfs(1, N) << endl;
	return 0;
}