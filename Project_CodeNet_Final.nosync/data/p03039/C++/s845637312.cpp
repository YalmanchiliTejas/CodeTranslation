#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
// #define DEBUG_MODE
#ifdef DEBUG_MODE
	#define errp(...) fprintf(stderr, __VA_ARGS__)
	#define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
	#define errp(...)
	#define dbg(x) 
#endif

ll gcd_ext (ll a, ll b, ll &x, ll &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}

	ll xn, yn, g;
	g = gcd_ext(b % a, a, xn, yn);
	x = yn - xn * (b / a);
	y = xn;
	return g;
}

ll mod_inv (ll a, ll b) {
	ll x, y, g;
	g = gcd_ext(a, b, x, y);
	if (g != 1) return -1;
	return (x % b + b) % b; /* x may be negative */
}

ll sub (ll a, ll b, ll p) {
	ll res = a - b;
	if (res < 0) res += p;
	return res;
}

ll add (ll a, ll b, ll p) {
	ll res = a + b;
	if (res >= p) res -= p;
	return res;
}

ll mul (ll a, ll b, ll p) {
	return ((a % p) * (b % p)) % p;
}

ll bin_exp (ll a, ll b, ll p) { /* pow(a, b) % p */
	if (b == 1) return a % p;
	if (b & 1) return mul(a, bin_exp(a, b - 1, p), p);
	else {
		ll x = bin_exp(a, b / 2, p);
		return mul(x, x, p);
	}
}

const ll MOD = (ll)1e9 + 7;
const int N = 200010;
ll fact[N];
ll n, m, k;

ll calc (ll r, ll c) {
	ll a = r * (r - 1) + (n - r) * (n - r + 1);
	ll b = c * (c - 1) + (m - c) * (m - c + 1);
	return add(mul(a, m, MOD), mul(b, n, MOD), MOD);
}

int main () { 
#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = mul(fact[i - 1], i, MOD);

	scanf("%lld %lld %lld", &n, &m, &k);
	ll f = mul(fact[n * m - 2], mul(mod_inv(fact[k - 2], MOD),
		mod_inv(fact[n * m - k], MOD), MOD), MOD);

	ll res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			res = add(res, mul(f, calc(i, j), MOD), MOD);

	res = mul(res, mod_inv(4, MOD), MOD);
	printf("%lld\n", res);
}