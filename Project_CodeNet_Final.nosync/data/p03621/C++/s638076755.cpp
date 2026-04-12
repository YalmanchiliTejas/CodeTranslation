#include <bits/stdc++.h>
#define MOD 998244353
#define MAXT 1100000
using namespace std;
typedef long long LL;
LL powmod(LL a, LL n){
	if(n == 0) return 1;
	if(n % 2) return (a * powmod(a,n-1)) % MOD;
	return powmod((a*a) % MOD,n/2);
}

LL inv(LL a){
	return powmod(a,MOD-2);
}

LL fact[MAXT];
LL invfact[MAXT];
LL pow2[MAXT];
LL invpow2[MAXT];
int main(){
	LL inv2 = inv(2);
	for(int i = 0; i < MAXT; i++){
		if(i == 0){
			fact[i] = 1;
			pow2[i] = 1;
			continue;
		}
		pow2[i] = (2 * pow2[i-1]) % MOD;
		fact[i] = (i*fact[i-1]) % MOD;
	}
	invfact[MAXT-1] = inv(fact[MAXT-1]);
	invpow2[MAXT-1] = inv(pow2[MAXT-1]);
	for(LL j = MAXT-2; j >= 0; j--){
		invfact[j] = ((j+1) * invfact[j+1]) % MOD;
		invpow2[j] = (2 * invpow2[j+1]) % MOD;
	}
	string a, b;
	cin >> a >> b;
	int n11 = 0;
	int n10 = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == '1' && b[i] == '1') n11++;
		if(a[i] == '1' && b[i] == '0') n10++;
	}
	LL ans = 0;
	LL dp[2][11000];
	for(LL n = 0; n <= n10; n++){
		for(LL i = 0; i < 11000; i++){
			dp[n%2][i] = 0;
		}
		if(n == 0){
			dp[0][0] = 1;
			continue;
		}
		for(LL i = 0; i < 11000; i++){
			dp[n%2][i] += (n*n)*(dp[1-n%2][i]) % MOD;
			if(i > 0) dp[n%2][i] += (n*i)*(dp[n%2][i-1]) % MOD;
			dp[n%2][i] %= MOD;
		}
	}
	for(int a = 0; a <= n11; a++){
		LL cur = 1;
		cur = (cur * fact[n11]) % MOD;
		cur = (cur * invfact[a]) % MOD;
		cur = (cur * invfact[n11-a]) % MOD;
		cur = (cur * dp[n10 % 2][n11-a]) % MOD;

		cur = (cur * fact[n11+n10]) % MOD;
		cur = (cur * invfact[a]) % MOD;
		cur = (cur * invfact[n11+n10-a]) % MOD;

		cur = (cur * fact[a]) % MOD;
		cur = (cur * fact[a]) % MOD;
		ans = (ans + cur) % MOD;
		//cout << cur << endl;
	}
	cout << ans << endl;
}
