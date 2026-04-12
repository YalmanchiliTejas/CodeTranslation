#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
 
using namespace std;
typedef long long ll;
 
const ll MOD = 1000000007;
int dp[10001][2][100];
int D;
 
int main() {
	string str;
	cin >> str >> D;
	dp[0][0][0] = 1;
	for (int i = 0; i <= str.size(); i++) {
		for (int j = 0; j < 2; j++) {
			int lim = j ? 9 : str[i] - '0';
			for (int k = 0; k < D; k++) {
				for (int d = 0; d <= lim; d++) {
					dp[i + 1][j || (lim > d)][(k + d) % D] += dp[i][j][k];
					dp[i + 1][j || (lim > d)][(k + d) % D] %= MOD;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < 2; i++) {
		ans += dp[str.size()][i][0];
		//cout << ans << endl;
	}
	cout << (ans - 1 + MOD) % MOD << endl;
	return 0;
}