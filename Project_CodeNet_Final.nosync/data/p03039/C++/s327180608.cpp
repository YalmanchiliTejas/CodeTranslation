#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ll long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl


// ax+by=1の解
ll extgcd(ll a, ll b, ll& x, ll& y) {
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}
// mod mでのaの逆数
ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}
// nの階乗 mod p
ll factorial(int n, int p) {
	ll r = 1;
	for (int i = 1; i <= n; i++)
		r = (r * i) % p;
	return r;
}
// nPr mod p
ll permutation(int n, int r, int p) {
	ll a = 1;
	for (int i = n - r + 1; i <= n; i++)
		a = (a * i) % p;
	return a;
}
// nCr mod p
ll combination(int n, int r, int p) {
	if (r == 0 || r == n) return 1;
	if (r > n / 2) r = n - r;
	ll numerator = permutation(n, r, p);
	ll denominator = factorial(r, p) % p;
	ll inv = mod_inverse(denominator, p);
	return (numerator * inv) % p;
}


signed main() {

	int N, M, K;
	cin >> N >> M >> K;

	int ans1 = 0;
	for (int i = 1; i <= M - 1; i++) {
		ans1 += i * (M - i);
		ans1 %= mod;
	}
	int ans2 = 0;
	for (int i = 1; i <= N - 1; i++) {
		ans2 += i * (N - i);
		ans2 %= mod;
	}
	int ans = ((((ans1 * N)%mod) * N)%mod) + ((((ans2 * M)%mod) * M)%mod);

	ans *= combination(N * M - 2, K - 2, mod);
	ans %= mod;

	cout << ans << endl;

	return 0;
}
