#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;

#define rep(a,n) for(int a = 0;a < n;a++)
#define repi(a,b,n) for(int a = b;a < n;a++)

const ull mod = 1000000007;

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

int main(void)
{
	ll n, m, k;
	cin >> n >> m >> k;
	Factorial f(n * m);
	ll comb = f.cmb(n * m - 2, k - 2);
	ll x = 0;
	rep(i, n) {
		ll dist = i;
		ll count = n - i;
		ll select = m * m;
		ll num = (dist * count * select) % mod;
		x += (num * comb) % mod;
		x %= mod;
	}
	swap(n, m);
	rep(i, n) {
		ll dist = i;
		ll count = n - i;
		ll select = m * m;
		ll num = (dist * count * select) % mod;
		x += (num * comb) % mod;
		x %= mod;
	}
	cout << x << endl;
	return 0;
}
