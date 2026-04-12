
// E - Almost Everywhere Zero

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const int MOD = 1e9 + 7;

ll dp[101][2][4]; // dp[i][j][k]:個数, i:決めた桁数（左から）, j:未満フラグ, k:0でない数字の個数

ll solve(string N, int K) {
	dp[0][0][0] = 1;

	int L = N.size();

	for (int i=0; i<L; i++) {
		int D = N[i] - '0';

		// ==== 過去に対応する桁より小さい値を入れたことがない（dp[i][0][k]からの更新） ==== //

		// D未満を選ぶとき、更新先の未満フラグは1
		for (int d=0; d<D; d++) {
			if (d == 0) {
				dp[i+1][1][0] += dp[i][0][0];
				dp[i+1][1][1] += dp[i][0][1];
				dp[i+1][1][2] += dp[i][0][2];
				dp[i+1][1][3] += dp[i][0][3];
			} else {
				dp[i+1][1][1] += dp[i][0][0];
				dp[i+1][1][2] += dp[i][0][1];
				dp[i+1][1][3] += dp[i][0][2];
			}
		}

		// Dを選ぶとき、更新先の未満フラグは0
		int d = D;
		if (d == 0) {
			dp[i+1][0][0] += dp[i][0][0];
			dp[i+1][0][1] += dp[i][0][1];
			dp[i+1][0][2] += dp[i][0][2];
			dp[i+1][0][3] += dp[i][0][3];
		} else {
			dp[i+1][0][1] += dp[i][0][0];
			dp[i+1][0][2] += dp[i][0][1];
			dp[i+1][0][3] += dp[i][0][2];
		}

		// ==== 過去に対応する桁より小さい値を入れたことがある（dp[i][1][k]からの更新） ==== //
		// → 全て（0 以上 9 以下）の値が候補
		for (int d=0; d<=9; d++) {
			if (d == 0) {
				dp[i+1][1][0] += dp[i][1][0];
				dp[i+1][1][1] += dp[i][1][1];
				dp[i+1][1][2] += dp[i][1][2];
				dp[i+1][1][3] += dp[i][1][3];
			} else {
				dp[i+1][1][1] += dp[i][1][0];
				dp[i+1][1][2] += dp[i][1][1];
				dp[i+1][1][3] += dp[i][1][2];
			}
		}
	}

	return dp[L][0][K] + dp[L][1][K];
}

int main(){
	string N;
	int K;
	cin >> N >> K;

	ll ans = solve(N, K);

	cout << ans << endl;

	return 0;
}