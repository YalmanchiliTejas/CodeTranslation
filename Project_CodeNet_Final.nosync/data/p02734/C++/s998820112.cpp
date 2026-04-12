#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int N, S;
int A[3000 + 10];

ll dp[3000 + 10][3000 + 10][3];//0->まだ取り始めていない　1->Lが決まっていて、Rが未定 2->LもRも決まってる

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)cin >> A[i];

	dp[0][0][0] = 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			(dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
			(dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;//何も決めてない+ここでLを決めた
			(dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= MOD;//何も決めてない+ここでRを決めた+ここでLとRを決めた
			if (j + A[i] <= S) {
				(dp[i + 1][j + A[i]][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
				//何かしらを選ぶので、無からLを選ぶのと、Lの後に別の要素を選ぶのを、まとめてかける。dp[i][jが0でない][0]=0だし
				(dp[i + 1][j + A[i]][2] += dp[i][j][0] + dp[i][j][1]) %= MOD;
				//ここでj+A[i]の和を足して、そのままRを選んで区間を閉じた場合。if文外のように、後ろで閉じてもいい。
			}
		}
	}
	cout << dp[N][S][2] << endl;
	return 0;
}