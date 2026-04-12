#include <iostream>
#include <cassert>

template<int Modulus>
struct modint {
	using value_type = int;

	static constexpr int mod = Modulus;
	static_assert(mod > 1, "Modulus must be greater than 1");

private :
	value_type x;

	template<class T>
	static constexpr value_type normalize (T value) noexcept {
		if (value < 0) {
			value = (-value) % mod;
			return (value ? value : mod - value);
		}
		return (value % mod);
	}

public :
	explicit constexpr modint () noexcept : x(0) { }

	template<class T>
	constexpr modint (T value) noexcept : x(normalize(value)) { }

	constexpr modint operator+ () const noexcept {
		return modint(*this);
	}

	constexpr modint operator- () noexcept {
		if (x != 0) x = mod - x;
		return modint(*this);
	}

	constexpr modint &operator+= (const modint &p) noexcept {
		if ((x += p.x) >= mod) x -= mod;
		return (*this);
	}

	constexpr modint &operator-= (const modint &p) noexcept {
		if ((x += mod - p.x) >= mod) x -= mod;
		return (*this);
	}

	constexpr modint &operator*= (const modint &p) noexcept {
		x = (int)(1LL * x * p.x % mod);
		return (*this);
	}

	constexpr modint &operator/= (const modint &p) noexcept {
		return ((*this) *= p.inverse());
	}

	constexpr modint operator+ (const modint &p) const noexcept {
		return (modint(*this) += p);
	}

	constexpr modint operator- (const modint &p) const noexcept {
		return (modint(*this) -= p);
	}

	constexpr modint operator* (const modint &p) const noexcept {
		return (modint(*this) *= p);
	}

	constexpr modint operator/ (const modint &p) const noexcept {
		return (modint(*this) /= p);
	}

	constexpr bool operator== (const modint &p) const noexcept {
		return (x == p.x);
	}

	constexpr bool operator!= (const modint &p) const noexcept {
		return (x != p.x);
	}

	constexpr modint pow (long long exp) const noexcept {
		modint value(1), buff(x);
		while (exp) {
			if (exp & 1) value *= buff;
			buff *= buff;
			exp >>= 1;
		}
		return value;
	}

	constexpr modint inverse () const noexcept {
		return pow(mod - 2);
	}

	friend std::ostream &operator<< (std::ostream &os, const modint &p) {
		return (os << p.x);
	}

	friend std::istream &operator>> (std::istream &is, modint &p) {
		long long v;
		is >> v;
		p = modint(v);
		return (is);
	}

};

#include <bits/stdc++.h>
struct fastio { fastio() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); } } _fastio_;
template<class T> bool chmin (T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> bool chmax (T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }

constexpr int MOD = 1'000'000'007;

int main() {
	int n;
	std::cin >> n;
	std::vector<modint<MOD>> a(n), s(n + 1, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		s[i + 1] = s[i] + a[i];
	}
	
	modint<MOD> ans = 0;
	for (int i = 0; i < n; i++) {
		modint<MOD> sum = s[n] - s[i + 1];
		ans += (sum * a[i]);
	}
	
	std::cout << ans << '\n';
	return 0;
}