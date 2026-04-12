#include <iostream>
#define  MOD 1000000007
#define int long long
using namespace std;

int mod_inv(int X){
	int a = X, b = MOD, u = 1, v = 0;
	while(b) {
		int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	if(u < 0) u += MOD;
	return u;
}

signed main(){
	int n,a,b,c,d,dp[1001][1001] = {},comb[1001][1001] = {},fact[1001] = {1,1};
	for(int i = 2;i <= 1000;i++) fact[i] = fact[i - 1] * i % MOD;
	for(int i = 0;i <= 1000;i++) {
		comb[i][0] = 1;
		comb[i][i] = 1;
		for(int j = 1;j < i;j++) comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
	}
	cin >> n >> a >> b >> c >> d;
	dp[a - 1][0] = 1;
	for(int i = a;i <= b;i++){
		for(int j = 0;j <= n;j++){
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			int now = dp[i - 1][j];
			for(int k = 1;k <= c - 1 && j + i * k <= n;k++) now = now * comb[n - j - ((k - 1) * i)][i] % MOD;
			for(int k = c;k <= d && j + i * k <= n;k++){
				now = now * comb[n - j - ((k - 1) * i)][i] % MOD;
				dp[i][j + i * k] = (dp[i][j + i * k] + now * mod_inv(fact[k]) % MOD) % MOD;
			}
		}
	}
	cout << dp[b][n] << endl;
	return 0;
}