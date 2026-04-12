#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = std::int_fast64_t;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

#ifndef INCLUDED_MODINT_HPP
#define INCLUDED_MODINT_HPP

#include <iostream>

template <std::uint_fast64_t Modulus>
class modint {
	using u32 = std::uint_fast32_t;
	using u64 = std::uint_fast64_t;
	using i64 = std::int_fast64_t;

	inline u64 apply(i64 x) { return (x < 0 ? x + Modulus : x); };

public:
	u64 a;
	static constexpr u64 mod = Modulus;

	constexpr modint(const i64& x = 0) noexcept: a(apply(x % (i64)Modulus)) {}

	constexpr modint operator+(const modint& rhs) const noexcept { return modint(*this) += rhs; }
	constexpr modint operator-(const modint& rhs) const noexcept { return modint(*this) -= rhs; }	
	constexpr modint operator*(const modint& rhs) const noexcept { return modint(*this) *= rhs; }
	constexpr modint operator/(const modint& rhs) const noexcept { return modint(*this) /= rhs; }
	constexpr modint operator^(const u64& k) const noexcept { return modint(*this) ^= k; }
	constexpr modint operator^(const modint& k) const noexcept { return modint(*this) ^= k.value(); }
	constexpr modint operator-() const noexcept { return modint(Modulus - a); }
	constexpr modint operator++() noexcept { return (*this) = modint(*this) + 1; }
	constexpr modint operator--() noexcept { return (*this) = modint(*this) - 1; }
	const bool operator==(const modint& rhs) const noexcept { return a == rhs.a; };
	const bool operator!=(const modint& rhs) const noexcept { return a != rhs.a; };
	const bool operator<=(const modint& rhs) const noexcept { return a <= rhs.a; };
	const bool operator>=(const modint& rhs) const noexcept { return a >= rhs.a; };
	const bool operator<(const modint& rhs) const noexcept { return a < rhs.a; };
	const bool operator>(const modint& rhs) const noexcept { return a > rhs.a; };
	constexpr modint& operator+=(const modint& rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) a -= Modulus;
		return *this;
	}
	constexpr modint& operator-=(const modint& rhs) noexcept {
		if (a < rhs.a) a += Modulus;
		a -= rhs.a;
		return *this;
	}
	constexpr modint& operator*=(const modint& rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr modint& operator/=(modint rhs) noexcept {
		u64 exp = Modulus - 2;
		while (exp) {
			if (exp % 2) (*this) *= rhs;
			
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}
	constexpr modint& operator^=(u64 k) noexcept {
		auto b = modint(1);
		while(k) {
			if(k & 1) b = b * (*this);
			(*this) *= (*this);
			k >>= 1;
		}
		return (*this) = b;
	}
	constexpr modint& operator=(const modint& rhs) noexcept {
		a = rhs.a;
		return (*this);
	}

	constexpr u64& value() noexcept { return a; }
	constexpr const u64& value() const noexcept { return a; }
	explicit operator bool() const { return a; }
	explicit operator u32() const { return a; }

	const modint inverse() const {
		return modint(1) / *this;
	}
	const modint pow(i64 k) const {
		return modint(*this) ^ k;
	}

	friend std::ostream& operator<<(std::ostream& os, const modint& p) {
		return os << p.a;
	}
	friend std::istream& operator>>(std::istream& is, modint& p) {
		u64 t;
		is >> t;
		p = modint(t);
		return is;
	}
};

#endif

using mint = modint<998244353>;

int main() {
	int n, s; scanf("%d%d", &n, &s); std::vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	mint ans = 0;
	std::vector<mint> dp(s + 1);
	for(int i = 0; i < n; i++) {
		dp[0] += 1;
		std::vector<mint> nxt = dp;
		for(int j = 0; j < s; j++) {
			int to = j + a[i];
			if(to > s) continue;
			
			nxt[to] += dp[j];
		}
		dp.swap(nxt);

		ans += dp[s];
	}

	printf("%lld\n", ans.value());
	return 0;
}
