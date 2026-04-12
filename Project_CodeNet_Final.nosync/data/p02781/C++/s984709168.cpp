#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
	string S;
	int K;
	cin >> S >> K;
	int N = (int)S.size();
	// Ai以下を見て, Sと等しいか, 以下か
	vector<vector<ll>> dp_equal(N+1, vector<ll>(4, 0));
	vector<vector<ll>> dp_less(N+1, vector<ll>(4, 0));
	// 0個見て, 0でない数字が0個 つまり0
	dp_equal[0][0] = 1;

	for(int i=1;i<=N;i++) {
		int now = (int)(S[i-1] - '0');
		// i桁目まで全部0
		dp_less[i][0] = 1;
		for(int j=1;j<=K;j++) {
			// equal -> equalについて
			if(now > 0) dp_equal[i][j] = dp_equal[i-1][j-1];
			else dp_equal[i][j] = dp_equal[i-1][j];

			// less -> lessについて
			// 1~9のどれかを置ける
			dp_less[i][j] += dp_less[i-1][j-1] * 9;
			// 0を置く
			dp_less[i][j] += dp_less[i-1][j];

			// now == 0のときはequal -> lessにならない
			if(now > 0) {
				// 0を置く
				dp_less[i][j] += dp_equal[i-1][j];
				// equalからlessになる, 1以上now-1以下
				dp_less[i][j] += dp_equal[i-1][j-1] * (now - 1);
			}
		}
	}
	cout << dp_equal[N][K] + dp_less[N][K] << endl;
}