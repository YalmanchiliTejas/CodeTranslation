#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
 
const int MOD = 998244353;
int N, S;
vector<int> v;
int dp[3005][3005];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> S;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];
 
	//f(i, j)=k인 0 <= j <= i의 개수
	// 점화식 dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i]] % MOD
	// 기저사례 dp[i][0] = 1
 
	int ans = 0;
	for (int i = 0; i < N; i++) dp[i][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= S; j++) {
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j] %= MOD;
		}
		for (int j = v[i]; j <= S; j++) {
			dp[i + 1][j] += dp[i][j - v[i]];
			dp[i + 1][j] %= MOD;
		}
//		cout << dp[i + 1][S] << '\n';
 
		ans += dp[i + 1][S];
		ans %= MOD;
	}
 
	cout << ans << '\n';
	return 0;
}