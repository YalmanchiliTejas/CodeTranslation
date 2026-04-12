#include<bits/stdc++.h>
#define MOD 1000000007
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll dp[1001][1001];
ll fact[1001];
ll mod_pow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1)res = (res*a) % MOD;
		a = (a*a) % MOD;
		b >>= 1;
	}
	return res;
}
ll ppow(ll a) {
	return mod_pow(a, MOD - 2);
}
ll perm(ll a, ll b) {//a個の中からb個選んで順列を作成
	return (fact[a] * ppow(fact[a - b])) % MOD;
}
ll calc(ll a, ll b, ll c) {
	return (((perm(a, b*c)*mod_pow(ppow(fact[c]), b)) % MOD)*ppow(fact[b])) % MOD;
}
int main() {
	fact[0] = 1;
	int n, a, b, c, d; scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	for (int i = 1; i <= n; i++)fact[i] = (fact[i - 1] * i) % MOD;
	rep(i, n)dp[i][0] = 1;
	for (int i = a - 1; i < b; i++) {
		for (int j = 0; j <= n; j++) {
			if (j)(dp[i + 1][j] += dp[i][j]) %= MOD;
			if (j - c*(i + 1) < 0)continue;
			for (int k = c; j - k*(i + 1) >= 0 && k <= d; k++) {
				ll o = calc(n - (j - k*(i + 1)), k, i + 1);
				(dp[i + 1][j] += dp[i][j - k*(i + 1)] * o) %= MOD;
			}
		}
	}
	cout << dp[b][n] << endl;
}