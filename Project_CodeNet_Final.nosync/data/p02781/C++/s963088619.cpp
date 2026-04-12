#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string N;
	cin >> N;
	int K;
	cin >> K;

	int n = N.size(); // Nの桁数

	ll dp[110][2][5] = {};  // dp[i][j][k] =:条件を満たす数字の個数,(i:上からのi桁目まで, j:N未満確定であるかのフラグ, k:0でない数の総数)

	dp[0][0][0] = 1; // 初期化
	rep(i, n) {  
		rep(j, 2) {  
			rep(k, 4) { // 制約より(k <= 3)のみループすればいい
				int lim = j ? 9 : N[i] - '0'; // i+1桁目に配置することのできる数の最大値
				rep(d, lim + 1) { // 配置できる数までループ
					dp[i + 1][j || d < lim][k + (d > 0)] += dp[i][j][k]; // dが0でないなら(0以上なら)kに1足す
				}
			}
		}
	}

	cout << dp[n][0][K] + dp[n][1][K] << '\n'; // 未満確定じゃないのを足すのを忘れないように！
	return 0;
}
