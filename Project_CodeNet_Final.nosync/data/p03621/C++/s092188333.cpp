#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define mod 998244353

using namespace std;

string a, b;
llint n, m, t;

const int FACT_MAX = 200005;
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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> a >> b;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == '1' && b[i] == '1') m++;
		else if(a[i] == '1' && b[i] == '0') t++;
	}
	n = m+t;
	if(t == 0){
		llint ans = fact[n] * fact[n] % mod;
		cout << ans << endl;
		return 0;
	}
	
	llint ans = 0;
	for(int i = 0; i <= m; i++){
		llint tmp = comb(m, i) * fact[m-i] % mod;
		tmp *= fact[i] * fact_inv[i+t] % mod, tmp %= mod;
		llint sum = 0;
		for(int j = 0; j <= t; j++){
			if(j % 2) sum += mod - comb(t, j) * modpow(t-j, i+t) % mod, sum %= mod;
			else sum += comb(t, j) * modpow(t-j, i+t) % mod, sum %= mod;
		}
		tmp *= sum, tmp %= mod;
		ans += tmp, ans %= mod;
	}
	ans *= fact[n] * fact[t] % mod, ans %= mod;
	cout << ans << endl;
	
	return 0;
}