#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-12;

template <typename T>
void dump(T x) { cout << x << endl; }
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
inline ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
}
ll powm(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		ll d = powm(a, b / 2, c);
		return (d * d) % c;
	} else
		return (a * powm(a, b - 1, c)) % c;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

//ll dx[4] = {1, 0, -1, 0};
//ll dy[4] = {0, 1, 0, -1};

ll fact[214514];
ll inv[214514];

ll nCr(int n, int r) {
	ll ans = mod(mod(fact[n] * inv[n - r], MOD) * inv[r], MOD);
	return ans;
}

int main() {
	IOS();
	ll n, m, k;
	cin >> n >> m >> k;
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i]  = powm(fact[i], MOD - 2, MOD);
	}
	ll ans = 0;
	for (int i = 1; i <= n - 1; i++) {
		ll tmp = (n - i) * m * m;
		tmp	= (tmp * i) % MOD;
		ans += tmp;
		ans %= MOD;
	}
	for (int i = 1; i <= m - 1; i++) {
		ll tmp = (m - i) * n * n;
		tmp	= (tmp * i) % MOD;
		ans += tmp;
		ans %= MOD;
	}
	ans *= nCr(n * m - 2, k - 2);
	ans %= MOD;
	//dump(nCr(10, 0));
	dump(ans);
	return 0;
}