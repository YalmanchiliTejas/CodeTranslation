#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll MOD = (ll)1e9 + 7;
const int N = 200010;

inline ll exgcd (ll a, ll b, ll &x, ll &y) {
	if (a == 0) return x = 0,y = 1,b;
	ll xn, yn, g;
	g = exgcd(b % a, a, xn, yn),x = yn - xn * (b / a),y = xn;
	return g;
}

inline ll inv (ll a, ll b) {ll x, y, g;return g = exgcd(a, b, x, y), g!=1?-1:(x % b + b) % b;}
inline ll sub (ll a, ll b, ll p) {ll res = a - b;return res<0?res+p:res;}
inline ll add (ll a, ll b, ll p) {ll res = a + b;return res>=p?res-p:res;}
inline ll mul (ll a, ll b, ll p) {return ((a % p) * (b % p)) % p;}

inline ll qpow (ll a, ll b, ll p) {
	if (b == 1) return a % p;
	if (b & 1) return mul(a, qpow(a, b - 1, p), p);
	else {
		ll x = qpow(a, b / 2, p);
		return mul(x, x, p);
	}
}

ll fact[N], n, m, k;

inline ll calc (ll r, ll c) {
	ll a = r * (r - 1) + (n - r) * (n - r + 1), b = c * (c - 1) + (m - c) * (m - c + 1);
	return add(mul(a, m, MOD), mul(b, n, MOD), MOD);
}

int main () {
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i, MOD);
	scanf("%lld %lld %lld", &n, &m, &k);
	ll f = mul(fact[n * m - 2], mul(inv(fact[k - 2], MOD),inv(fact[n * m - k], MOD), MOD), MOD),res = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) res = add(res, mul(f, calc(i, j), MOD), MOD);
	res = mul(res, inv(4, MOD), MOD),
	printf("%lld\n", res);
}