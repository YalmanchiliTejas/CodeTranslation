#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#define llint long long
#define mod 998244353
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

const int FACT_MAX = 10000005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
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

llint n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	make_fact();
	
	llint ans = 0, mul = modpow(2, n/2), inv2 = modpow(2, mod-2);
	for(int i = n/2+1; i <= n; i++){
		mul *= inv2, mul %= mod;
		ans += mul * comb(n, i) % mod, ans %= mod;
	}
	ans *= 2, ans %= mod;
	ans = modpow(3, n) - ans + mod, ans %= mod;
	cout << ans << endl;

	return 0;
}