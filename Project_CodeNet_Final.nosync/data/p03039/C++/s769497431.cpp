#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCALc
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
template<typename T, typename l>
void getv(T& a, int n, l f) {
	a.resize(n);
	for (auto& i : a)
		cin >> i, f(i);
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, k, fact[200100];

ll binpow(ll a, ll n) {
	if (n == 0)
		return 1;
	if (n & 1)
		return (binpow(a, n - 1) * a) % mod;
	else {
		ll b = binpow(a, n / 2);
		return (b * 1ll * b) % mod;
	}
}

ll nck(ll n, ll k) {
	return (((fact[n] * binpow(fact[k], mod - 2)) % mod)
			* binpow(fact[n - k], mod - 2)) % mod;
}

ll sum(ll n) {
	return (((n * (n + 1)) % mod) * binpow(2, mod - 2)) % mod;
}

int main() {
	doin();
	fact[0] = 1;
	cin >> n >> m >> k;
	for (ll i = 1; i <= (n * m); i++)
		fact[i] = (i * fact[i - 1]) % mod;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ll cont = (sum(i) + sum(n - i - 1)) % mod;
			cont *= m;
			cont%=mod;
			cont += (n*sum(m-j-1))%mod;
			cont%=mod;
			cont += (n*sum(j))%mod;
			cont%=mod;
			cont *= nck(n*m - 2, k - 2);
			cont%=mod;
			(ans += cont)%=mod;
		}
	}
	cout << (ans*binpow(2, mod-2))%mod << "\n";
}
