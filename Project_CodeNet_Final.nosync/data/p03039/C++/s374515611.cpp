#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<ll> Vl;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;


//===

const ll mod = static_cast<ll>(1e9 + 7);

ll mpow(ll a, ll n) {
	ll res = 1;
	while (n != 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

ll mfrac(ll a) {
	ll res = 1;
	for (ll i = 2; i <= a; ++i) res = res * i % mod;
	return res;
}

ll mcomb(ll n, ll k) {
	ll res;
	res = mfrac(n) * mpow(mfrac(k), mod - 2) % mod;
	res = res * mpow(mfrac(n - k), mod - 2) % mod;
	return res;
}


int main() {
	ll N, M, K;
	cin >> N >> M >> K;

	vector<Pll> cells;
	for (ll i = 0; i < N * M; ++i) {
		cells.emplace_back(i / M, i % M);
	}

	ll ans = 0;
	ll ans_x = 0, ans_y = 0;
	ll cmb = mcomb(N * M - 2, K - 2);
	for (ll i = 1; i < N; ++i) {
		ll tmp;
		tmp = (N - i) * mpow(M, 2) % mod;
		tmp = tmp * i % mod;
		ans_x = (ans_x + tmp) % mod;
	}
	for (ll i = 1; i < M; ++i) {
		ll tmp;
		tmp = (M - i) * mpow(N, 2) % mod;
		tmp = tmp * i % mod;
		ans_y = (ans_y + tmp) % mod;
	}


	ans = (ans_x + ans_y) * cmb % mod;

	cout << ans << endl;
}