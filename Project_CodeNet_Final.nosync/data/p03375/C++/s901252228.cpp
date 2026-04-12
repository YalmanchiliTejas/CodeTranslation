#include <iostream>
#define llint long long

using namespace std;

llint n, mod;
llint S[3005][3005];
llint beki[3005][3005], beki2[3005];

const int FACT_MAX = 6005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n, llint m = mod)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%m) * (modpow(a, n-1, m)%m)) % m;
	}
	else{
		return modpow((a*a)%m, n/2, m) % m;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

int main(void)
{
	cin >> n >> mod;
	make_fact();
	
	for(int i = 0; i <= n; i++) S[i][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			S[i][j] = (j+1) * S[i-1][j] % mod + S[i-1][j-1];
			S[i][j] %= mod;
		}
	}
	beki[1][0] = beki2[0] = 1;
	for(int i = 1; i <= n; i++){
		beki[1][i] = beki[1][i-1] * 2, beki[1][i] %= mod;
		beki2[i] = beki2[i-1] * 2, beki2[i] %= mod-1;
	}
	for(int i = 0; i <= n; i++){
		beki[0][i] = 1;
		for(int j = 2; j <= n; j++){
			beki[j][i] = beki[j-1][i] * beki[1][i] % mod;
		}
	}
	for(int i = 0; i <= n; i++) beki2[i] = modpow(2, beki2[i]);
	
	llint ans = beki2[n];
	for(int i = 1; i <= n; i++){
		llint sum = 0;
		for(int j = 0; j <= i; j++){
			llint tmp = S[i][j]; tmp %= mod;
			tmp *= beki[j][n-i], tmp %= mod;
			tmp *= beki2[n-i], tmp %= mod;
			sum += tmp, sum %= mod;
		}
		sum *= comb(n, i), sum %= mod;
		
		if(i % 2) ans += mod - sum, ans %= mod;
		else ans += sum, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}