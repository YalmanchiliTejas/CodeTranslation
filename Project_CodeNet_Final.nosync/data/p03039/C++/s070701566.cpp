#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


// Modint
struct Mint {
	static const ll mod = (ll)(1e9 + 7);
	ll val;

	Mint() { val = 0; }
	Mint(ll a) { val = a; verify_value(); }

	void verify_value() {
		if (val >= mod) val %= mod;
		if (val < 0) val %= mod, val += mod;
	}

	Mint pow(ll p) const {
		Mint cur = Mint(val), ret = 1;
		while (p > 0) {
			if (p & 1) ret *= cur;
			cur *= cur;
			p >>= 1LL;
		}
		return ret;
	}
	Mint inv() const {
		if (val == 0) cerr << "CAUTION: inv() is called with 0." << endl;
		return pow(mod - 2);
	}

	Mint operator+() const { return *this; }
	Mint operator-() const { return Mint(mod - val); }

	Mint operator+=(const Mint &a) {
		val += a.val;
		if (val >= mod) val -= mod;
		return Mint(val);
	}
	Mint operator*=(const Mint &a) {
		val *= a.val;
		if (val >= mod) val %= mod;
		return Mint(val);
	}
	Mint operator-=(const Mint &a) { return *this += -a; }
	Mint operator/=(const Mint &a) { return *this *= a.inv(); }

	Mint operator++() { return *this += Mint(1); }
	Mint operator--() { return *this -= Mint(1); }
	Mint operator++(int) {
		Mint ret = *this;
		++(*this);
		return ret;
	}
	Mint operator--(int) {
		Mint ret = *this;
		--(*this);
		return ret;
	}

	operator ll() const { return val; }
};

Mint operator+(const Mint &a, const Mint &b) {
	ll ret = a.val + b.val;
	if (ret >= Mint::mod) ret -= Mint::mod;
	return Mint(ret);
}
Mint operator*(const Mint &a, const Mint &b) {
	ll ret = a.val * b.val;
	if (ret >= Mint::mod) ret %= Mint::mod;
	return Mint(ret);
}
Mint operator-(const Mint &a, const Mint &b) { return a + (-b); }
Mint operator/(const Mint &a, const Mint &b) { return a * b.inv(); }

ostream &operator<<(ostream &out, const Mint &a) { return out << a.val; }
istream &operator>>(istream &in, Mint &a) {
	in >> a.val;
	a.verify_value();
	return in;
}


// Combinatorics
constexpr int MAX_N = 2000003;
Mint fact[MAX_N], inv[MAX_N];

void init_fact() {
	fact[0] = inv[0] = 1;
	for (ll i = 1; i < MAX_N; i++) {
		fact[i] = fact[i - 1] * Mint(i);
		inv[i] = fact[i].inv();
	}
}

// aCb
Mint C(int a, int b) {
	if (a < b) return 0;
	Mint res = fact[a];
	res *= inv[b];
	res *= inv[a - b];
	return res;
}

// aPb
Mint P(int a, int b) {
	if (a < b) return 0;
	return fact[a] * inv[a - b];
}

// aHb
Mint H(int a, int b) {
	if (b == 0) return 1;
	return C(a + b - 1, b);
}

int main() {
	// 2 * 1 * 2 / 2 = 2
	// . . x . .
	// 1 2 3 4 5
	// (3 - 1)*3 / 2
	// (5 - 3)*(5 - 3 + 1) / 2
	init_fact();
	Mint n, m, k; cin >> n >> m >> k;
	Mint ans = 0;
	for (Mint i = 1; i <= n; i++) {
		for (Mint j = 1; j <= m; j++) {
			ans += m*(i - Mint(1))*i / Mint(2);
			ans += m*(n - i)*(n - i + Mint(1)) / Mint(2);
			ans += n*(j - Mint(1))*j / Mint(2);
			ans += n*(m - j)*(m - j + Mint(1)) / Mint(2);
		}
	}
	cout << C((ll)n*(ll)m - 2, (ll)k - 2) * ans / Mint(2) << endl;
	return 0;
}
