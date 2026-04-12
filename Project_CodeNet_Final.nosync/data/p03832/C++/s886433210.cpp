#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
typedef long long ll;
using namespace std;
long long const MOD = 1000000007;
long long const MAX = 1005;

//ax+by = (gcd of x and y)となるようにa,bを変更する
long long extgcd(long long x, long long y, long long &a, long long &b) {
	if (y == 0) {
		a = 1; b = 0;
		return x;
	}
	else {
		long long q = x / y; long long r = x % y;
		long long s;
		long long d = extgcd(y, r, s, a);
		b = s - a * q;
		return d;
	}
}

long long mod_inverse(long long x) {
	x %= MOD;
	long long a, b;
	a = b = 0;
	if (extgcd(x, MOD, a, b) != 1) {
		return -1;
	}
	else {
		return (MOD + a % MOD) % MOD;
	}
}

ll mod_pow(ll x, ll n) {
	if (n == 0) {
		return 1;
	}
	else {
		ll t = mod_pow(x, n / 2);

		if (n % 2 == 1) {
			return t * t%MOD*x%MOD;
		}
		else {
			return t * t%MOD;
		}
	}
}

//階乗をここに記憶
long long mod_fact[MAX];
long long mod_inv_fact[MAX];
ll mod_pow_inv_fact[MAX][MAX];

void prep_fact(long long n) {
	mod_fact[0] = 1;
	for (long long i = 1; i <= n; i++) {
		mod_fact[i] = (mod_fact[i - 1] * i) % MOD;
	}
}
void prep_inv(long long n) {
	for (long long i = 0; i <= n; i++) {
		mod_inv_fact[i] = mod_inverse(mod_fact[i]);
	}
	REP(i, 0, n) {
		REP(j, 0, n) {
			mod_pow_inv_fact[i][j] = mod_inverse(mod_pow(mod_fact[i], j));
		}
	}
}

long long nCr(long long n, long long r) {
	return (((mod_fact[n] * mod_inv_fact[r]) % MOD)*mod_inv_fact[n - r]) % MOD;
}


ll dp[MAX][MAX];

ll mod_m(ll x, ll y) {
	return (x*y) % MOD;
}

ll mod_p(ll x, ll y) {
	return (x + y) % MOD;
}
int main() {	
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	prep_fact(MAX - 1);
	prep_inv(MAX - 1);
	REP(i, 1, n) {
		dp[i][a-1] = 0;
	}
	dp[0][a-1] = 1;
	REP(j, a, b) {
		REP(i, 0, n) {
			ll dpij = dp[i][j-1];
			REP(k, c, min(d, i / j)) {
				ll cnt = dp[i - k * j][j - 1];
				cnt = mod_m(cnt, nCr(i, k*j));
				cnt = mod_m(cnt, mod_fact[k*j]);
				cnt = mod_m(cnt, mod_pow_inv_fact[j][k]);
				cnt = mod_m(cnt, mod_inv_fact[k]);
				dpij = mod_p(dpij, cnt);
			}
			dp[i][j] = dpij;
		}
	}
	cout << dp[n][b] << endl;
	/*
	REP(i, 0, n) {
		REP(j, a - 1, b) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
}