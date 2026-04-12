#include "bits/stdc++.h"
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
	ll x; // typedef long long ll;
	mint(ll x = 0) :x((x%mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const { return pow(mod - 2); }
	mint& operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
struct combination {
	vector<mint> fact, ifact;
	combination(int n) :fact(n + 1), ifact(n + 1) {
		assert(n < mod);
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
		ifact[n] = fact[n].inv();
		for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
	}
	mint operator()(int n, int k) {
		if (k < 0 || k > n) return 0;
		return fact[n] * ifact[k] * ifact[n - k];
	}
}c(200005);


//m^n
mint f(int m, int n) {
	if (0 == n) {
		return 1;
	}
	mint x = f(m, n / 2);
	x *= x;
	if (1 == n % 2) {
		x *= (mint)m;
	}
	return x;
}
// nCa
mint choose(long long n, long long a) {
	mint x = 1;
	mint y = 1;
	for (int m = 0; m < a; ++m) {
		x *= (mint)(n - m);
		y *= (mint)(a - m);
	}
	return x / y;
}
// nPk
mint nPk(int n, int a) {
	mint ret = choose(n, a);
	for (int n = 1; n <= a; ++n) {
		ret *= n;
	}
	return ret;
}


int main() {
	long long N, M,K;
	cin >> N >> M >> K;
	mint ans = choose(N * M - 2,K-2);
	mint anssub = 0;
	for (int n = 1;n<=N-1; ++n) {
		anssub += (mint)M*M*(N-n)*n;
	}
	for (int m = 1; m <= M - 1; ++m) {
		anssub += (mint)N*N*(M - m)*m;
	}
	ans *= anssub;
	cout << ans << endl;
	return 0;
}
