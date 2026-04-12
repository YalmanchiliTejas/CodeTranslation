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
#include <numeric>
#include <complex>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


// Modint
struct Mint {
	static const ll mod = 998244353;
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
		if (val == 0) cerr << "WARNING: inv() is called with 0." << endl;
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

Mint pow(Mint a, ll b) {
	return a.pow(b);
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
	int n, s; cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<Mint> cnt(n*s + 2);
	cnt[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = s; j >= 0; j--) {
			Mint cf = 1;
			if (j == 0) cf *= i + 1;
			if (j + a[i] == s) cf *= n - i;
			cnt[j + a[i]] += cf*cnt[j];
		}
	}
	cout << cnt[s] << endl;
	return 0;
}
