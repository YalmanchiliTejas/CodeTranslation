#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	function<i64(i64,i64)> mpow = [&](i64 x, i64 y){
		if(y < 2)
			return (i64)(y ? x : 1);

		i64 tmp = mpow(x, y >> 1);
		return (tmp * tmp) % MOD * mpow(x, y & 1) % MOD;
	};

	vector<i64> fact(n + 5, 1), inv(n + 5, 1);
	for(int i = 1; i < n + 5; ++i){
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
	}

	vector<i64> dp(n + 1, 0);
	dp[n] = 1;

	for(int i = b; i >= a; --i){
		vector<i64> nex(n + 1, 0);
		for(int j = 0; j <= n; ++j){
			nex[j] = (dp[j] + nex[j]) % MOD;
			i64 p = fact[j];
			for(int k = 0; k < c; ++k)
				p = (p * inv[i]) % MOD;

			for(i64 k = j - (c * i), l = c; k >= 0 && l <= d; k -= i, ++l, p = (p * inv[i]) % MOD){
				nex[k] = (nex[k] + dp[j] * p % MOD * inv[k] % MOD * inv[l]) % MOD;
			}
		}
		dp = move(nex);
	}
	cout << dp[0] << endl;
}

