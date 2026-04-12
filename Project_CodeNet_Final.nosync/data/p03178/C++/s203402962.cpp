#include<iostream>
#include<string>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

string K;
int D;

ll dp[10002][2][101];
//dp[i][j][k] := i - 1桁目(1-idx)まで決定済みで、これからi番目を決定する
//jが1ならばKとスレスレの状態、0ならばそうでない
//kはその時の各桁の和のmod D

int main() {
	cin >> K >> D;
	dp[0][1][0] = 1;
	for (int i = 0; i <= K.size(); i++) {
		for (int j = 0; j < 2; j++) {
			for (int amari = 0; amari <= D; amari++) {
				dp[i][j][amari] %= MOD;
				int limit = j ? K[i] - '0': 9;
				for (int keta_val = 0; keta_val <= limit; keta_val++) {
					dp[i + 1][(!j) ? 0 : ((keta_val == limit) ? 1 : 0)][(amari + keta_val) % D]
						+= dp[i][j][amari];
				}

			}
		}
	}
	//000...000はレグレーション違反なので、その分を引く
	cout << (dp[K.size()][0][0] + dp[K.size()][1][0] - 1 + MOD) % MOD << endl;

	return 0;
}