#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<ll, ll> P;


#define rep(a,n) for(int a = 0;a < n;a++)

const ll mod = 1000000007;

ll mpow(ll x, ll n) {
	ll ans = 1; x %= mod;
	while (n != 0) {
		if (n & 1) ans = ans * x % mod;
		x = x * x % mod;
		n = n >> 1;
	}
	return ans;
}

ll inv_mod(ll a) { return mpow(a, mod - 2); }

//階乗とその逆元を求めて計算に利用するクラス
class Factorial {
private:
	vector<ll> fac;
	vector<ll> ifac;
public:

	Factorial(ll N) {
		fac.push_back(1);
		for (int i = 0; i < N; i++) fac.push_back(fac[i] * (i + 1) % mod);
		ifac.resize(N + 1);
		ifac[N] = inv_mod(fac[N]);
		for (int i = 0; i < N; i++) ifac[N - 1 - i] = (ifac[N - i] * (N - i)) % mod;
	}

	ll fact(ll a) { return fac[a]; }
	ll ifact(ll a) { return ifac[a]; }

	ll cmb(ll a, ll b) {
		if (a == 0 && b == 0) return 1;
		if (a < b || a < 0 || b < 0) return 0;
		ll tmp = ifact(a - b) * ifact(b) % mod;
		return tmp * fac[a] % mod;
	}
	ll per(ll a, ll b) {
		if (a == 0 && b == 0) return 1;
		if (a < b || a < 0 || b < 0) return 0;
		return fac[a] * ifac[a - b] % mod;
	}
};

ll merge(ll n, ll m) {
	ll left = 0;
	for (int d = 1; d < n; d++) {
		left += (n - d) * d;
		left %= mod;
	}
	left *= m;
	left %= mod;
	left *= m;
	left %= mod;
	return left;
}

int main(void)
{
	ll n, m, k;
	cin >> n >> m >> k;

	Factorial f(n * m);
	auto c = f.cmb(n * m - 2, k - 2);
	auto a = merge(n, m);
	auto b = merge(m, n);
	auto sum = a + b;
	sum %= mod;
	sum *= c;
	sum %= mod;
	cout << sum << endl;
	return 0;
}