#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	vector<int> P(1<<N);
	for (int i = 0;i < 1 << N;++ i) cin >> P[i];
	
	static int dp[19][1<<18]; // dp[i][j]: 高さi, 左からj番目を開始点とするトーナメントの勝者
	for (int i = 0;i < 1 << N;++ i) dp[0][i] = P[i];
	for (int i = 1;i <= N;++ i) {
		for (int j = 0;j < 1 << N;++ j) {
			int left = dp[i - 1][j];
			int right = dp[i - 1][(j + (1 << i - 1)) % (1 << N)];
			int x = min(left, right), y = max(left, right); // 前のトーナメントにおける勝者2名, x≦y
			dp[i][j] = S[y - x - 1] == '0' ? x : y;
		}
	}
	for (int i = 0;i < 1 << N;++ i) cout << dp[N][i] << endl;
}
