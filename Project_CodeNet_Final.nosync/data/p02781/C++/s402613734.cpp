#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
	string s;
	int K;
	cin >> s;
	cin >> K;

	int size = s.size();

	// 通り数 = dp[i][j][k]
	// i桁目まで決めた時
	// j個の非ゼロ
	// k = 0 : そのまではNと一緒、1 : N以下が確定してる 

	int dp[size][K + 1][2]; 
	int cur = s[0] - '0';
	rep(i, size) {
		rep(j, K + 1) {
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;
		}
	}

	dp[0][0][0] = 0;        // 0個の非ゼロ c****  c > 0 （全部0）
	dp[0][1][0] = 1;        // 1個の非ゼロ c****  c > 0

	dp[0][0][1] = 1;        // 0個の非ゼロ x**** x = 0　（全部0）
	dp[0][1][1] = cur - 1;  // 1個の非ゼロ x**** x < c

	for (int i = 1; i < size; i++) {
		int cur = s[i] - '0';
		dp[i][0][0] = 0;
		dp[i][0][1] = 1;

		for (int j = 1; j < K + 1; j++) {
			if (cur == 0) {
				dp[i][j][0] = dp[i - 1][j][0];

				dp[i][j][1] = dp[i - 1][j - 1][0] * 0 
							+ dp[i - 1][j - 1][1] * 9
							+ dp[i - 1][j][0] * 0
							+ dp[i - 1][j][1] * 1;
			} else {
				dp[i][j][0] = dp[i - 1][j - 1][0];

				dp[i][j][1] = dp[i - 1][j - 1][0] * (cur - 1) 
							+ dp[i - 1][j - 1][1] * 9
							+ dp[i - 1][j][0] * 1
							+ dp[i - 1][j][1] * 1;
			}

		}

	}

	cout << dp[size - 1][K][0] + dp[size - 1][K][1] << endl;

	return 0;
}