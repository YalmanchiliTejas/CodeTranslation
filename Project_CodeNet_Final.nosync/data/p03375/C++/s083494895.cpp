#include<iostream>
#include<algorithm>

using namespace std;

typedef long long Int;

Int n;
Int MOD;
Int ans;
Int dp[3100][3100];
Int frac[108000];
Int rfrac[108000];
Int pow(Int a, Int b){
	if(b == 0)return 1;
	Int res = pow(a, b / 2);
	res *= res;res %= MOD;
	if(b % 2 == 1)res *= a;
	return res % MOD;
}

Int rev(Int x){
	return pow(x, MOD-2);
}

Int C(Int n, Int k){
	return frac[n] * rfrac[n-k]  % MOD * rfrac[k] % MOD;
}


Int powpow2(int x){
	Int res = 2;
	while(x--){
		res *= res;
		res %= MOD;
	}
	return res;
}


Int hoge(Int k){
	Int ans = 0;
	Int pp = powpow2(n-k);
	Int poyo = 1;
	Int pupu = pow(2,(n-k));
	for(int i = 0;i <= k;i++){
		ans += dp[k][i] * poyo % MOD * pp % MOD;ans %= MOD;
		poyo *= pupu;poyo %= MOD;
	}
	return ans * C(n, k) % MOD;
}

int main(){
	dp[0][0] = 1;
	cin >> n >> MOD;
	for(int i = 0;i <= 3000;i++){
		if(i == 0)frac[i] = 1;
		else frac[i] = frac[i-1] * i % MOD;
		rfrac[i] = rev(frac[i]);
	}
	ans = powpow2(n);
	for(int i = 1;i <= 3000;i++){
		for(int j = 0;j <= 3000;j++){
			dp[i][j] += dp[i-1][j] * (j+1) % MOD;
			if(j) dp[i][j] += dp[i-1][j-1];
			dp[i][j] %= MOD;
		}
	}
	
	for(int i = 1;i <= n;i++){
		if(i % 2 == 1)ans -= hoge(i);
		else ans += hoge(i);
		ans %= MOD;
	}
	if(ans < 0)ans += MOD;
	cout << ans << endl;
	return 0;
}
