#include <iostream>
#include <algorithm>
using namespace std;

int N, A[6009];
int dp[2009][2009], dp2[2009][2009];
int AllMax = 0;
int SubMax[2009];

void solve(int a1, int a2, int a3) {
	int offset = 0;
	if (a1 == a2 && a2 == a3) offset = 1;

	// 最初
	dp2[a1][a2] = max(dp2[a1][a2], AllMax - offset);
	dp2[a1][a3] = max(dp2[a1][a3], AllMax - offset);
	dp2[a2][a1] = max(dp2[a2][a1], AllMax - offset);
	dp2[a2][a3] = max(dp2[a2][a3], AllMax - offset);
	dp2[a3][a1] = max(dp2[a3][a1], AllMax - offset);
	dp2[a3][a2] = max(dp2[a3][a2], AllMax - offset);

	// 1 つペアが作れる場合
	dp2[a1][a2] = max(dp2[a1][a2], dp[a3][a3] + 1 - offset);
	dp2[a1][a3] = max(dp2[a1][a3], dp[a2][a2] + 1 - offset);
	dp2[a2][a1] = max(dp2[a2][a1], dp[a3][a3] + 1 - offset);
	dp2[a2][a3] = max(dp2[a2][a3], dp[a1][a1] + 1 - offset);
	dp2[a3][a1] = max(dp2[a3][a1], dp[a2][a2] + 1 - offset);
	dp2[a3][a2] = max(dp2[a3][a2], dp[a1][a1] + 1 - offset);

	// 2 つペアが作れる場合
	if (a1 == a2) {
		for (int i = 1; i <= N; i++) dp2[i][a3] = max(dp2[i][a3], max(dp[i][a1], dp[a1][i]) + 1 - offset);
		for (int i = 1; i <= N; i++) dp2[a3][i] = max(dp2[a3][i], max(dp[i][a1], dp[a1][i]) + 1 - offset);
	}
	if (a1 == a3) {
		for (int i = 1; i <= N; i++) dp2[i][a2] = max(dp2[i][a2], max(dp[i][a1], dp[a1][i]) + 1 - offset);
		for (int i = 1; i <= N; i++) dp2[a2][i] = max(dp2[a2][i], max(dp[i][a1], dp[a1][i]) + 1 - offset);
	}
	if (a2 == a3) {
		for (int i = 1; i <= N; i++) dp2[i][a1] = max(dp2[i][a1], max(dp[i][a2], dp[a2][i]) + 1 - offset);
		for (int i = 1; i <= N; i++) dp2[a1][i] = max(dp2[a1][i], max(dp[i][a2], dp[a2][i]) + 1 - offset);
	}

	// その他
	for (int i = 1; i <= N; i++) dp2[i][a1] = max(dp2[i][a1], SubMax[i] - offset);
	for (int i = 1; i <= N; i++) dp2[i][a2] = max(dp2[i][a2], SubMax[i] - offset);
	for (int i = 1; i <= N; i++) dp2[i][a3] = max(dp2[i][a3], SubMax[i] - offset);
	for (int i = 1; i <= N; i++) dp2[a1][i] = dp2[i][a1];
	for (int i = 1; i <= N; i++) dp2[a2][i] = dp2[i][a2];
	for (int i = 1; i <= N; i++) dp2[a3][i] = dp2[i][a3];

	// DP の更新
	for (int i = 1; i <= N; i++) { dp[i][a1] = max(dp[i][a1], dp2[i][a1]); dp2[i][a1] = -(1 << 30); }
	for (int i = 1; i <= N; i++) { dp[i][a2] = max(dp[i][a2], dp2[i][a2]); dp2[i][a2] = -(1 << 30); }
	for (int i = 1; i <= N; i++) { dp[i][a3] = max(dp[i][a3], dp2[i][a3]); dp2[i][a3] = -(1 << 30); }
	for (int i = 1; i <= N; i++) { dp[a1][i] = max(dp[a1][i], dp2[a1][i]); dp2[a1][i] = -(1 << 30); }
	for (int i = 1; i <= N; i++) { dp[a2][i] = max(dp[a2][i], dp2[a2][i]); dp2[a2][i] = -(1 << 30); }
	for (int i = 1; i <= N; i++) { dp[a3][i] = max(dp[a3][i], dp2[a3][i]); dp2[a3][i] = -(1 << 30); }
	for (int i = 1; i <= N; i++) { AllMax = max(AllMax, dp[i][a1]); SubMax[i] = max(SubMax[i], dp[i][a1]); SubMax[a1] = max(SubMax[a1], dp[i][a1]); }
	for (int i = 1; i <= N; i++) { AllMax = max(AllMax, dp[i][a2]); SubMax[i] = max(SubMax[i], dp[i][a2]); SubMax[a2] = max(SubMax[a2], dp[i][a2]); }
	for (int i = 1; i <= N; i++) { AllMax = max(AllMax, dp[i][a3]); SubMax[i] = max(SubMax[i], dp[i][a3]); SubMax[a3] = max(SubMax[a3], dp[i][a3]); }
}

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= 3 * N; i++) cin >> A[i];
	
	// 初期化
	for (int i = 1; i <= N; i++) {
		SubMax[i] = -(1 << 30);
		for (int j = 1; j <= N; j++) { dp[i][j] = -(1 << 30); dp2[i][j] = -(1 << 30); }
	}
	dp[A[1]][A[2]] = 0; SubMax[A[1]] = 0;
	dp[A[2]][A[1]] = 0; SubMax[A[2]] = 0;
	AllMax = 0;

	// 計算
	for (int i = 1; i <= N - 1; i++) {
		solve(A[3 * i], A[3 * i + 1], A[3 * i + 2]);
	}

	// 答えを求める
	int Answer = -(1 << 30);
	int offset = 0;
	for (int i = 1; i <= N - 1; i++) {
		if (A[3 * i] == A[3 * i + 1] && A[3 * i + 1] == A[3 * i + 2]) offset += 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int ret = dp[i][j] + offset;
			if (i == j && j == A[3 * N]) ret += 1;
			Answer = max(Answer, ret);
		}
	}

	// 出力
	cout << Answer << endl;
	return 0;
}