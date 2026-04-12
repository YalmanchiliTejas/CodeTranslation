#include <iostream>
using namespace std;

const long MOD = 1e9 + 7;
long n, m, k, ans, t, div6;

long powMod(long x, long n, long mod){
	if (n == 1) return (x % mod);
	else if (n % 2 == 0){
		long t = powMod(x, n/2, mod);
		return (t*t) % mod;
	}
	else{
		return (x*powMod(x, n-1, mod)) % mod;
	}
}

long combMod(long n, long k, long mod){
	long a = min(k, n-k);
	long b = 1;
	long c = 1;
	for (int i = 1; i <= a; ++i){
		b = (b*i) % mod;
	}
	for (int i = n-a+1; i <= n; ++i){
		c = (c*i) % mod;
	}
	b = powMod(b, mod-2, mod);
	return (b*c) % mod;
}

int main(){
	cin >> n >> m >> k;
	div6 = powMod(6L, MOD-2, MOD);
	t = powMod(m, 2, MOD);
	t = (t*(n-1)) % MOD;
	t = (t*n) % MOD;
	t = (t*(n+1)) % MOD;
	ans = t;
	t = powMod(n, 2, MOD);
	t = (t*(m-1)) % MOD;
	t = (t*m) % MOD;
	t = (t*(m+1)) % MOD;
	ans = (ans + t) % MOD;
	ans = (ans*div6) % MOD;
	ans = (ans*combMod(n*m-2, k-2, MOD)) % MOD;
	cout << ans;
}