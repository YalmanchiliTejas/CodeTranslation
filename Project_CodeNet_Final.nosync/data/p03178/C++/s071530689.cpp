//#define NDEBUG
#include <cstddef>
#include <cstdint>
#include <vector>

using i8 = ::std::int_least8_t;
using i32 = ::std::int_least32_t;
using i64 = ::std::int_least64_t;
using u8 = ::std::uint_least8_t;
using u32 = ::std::uint_least32_t;
using u64 = ::std::uint_least64_t;
using isize = ::std::ptrdiff_t;
using usize = ::std::size_t;

template <class T = usize> class rep {
	const T f, l;

public:
	class itr {
		friend rep;
		T i;
		constexpr itr(T x) noexcept : i(x) {}

	public:
		void operator++() noexcept { ++i; }
		constexpr T operator*() const noexcept { return i; }
		constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
	};
	constexpr rep(const T first, const T last) noexcept : f(first), l(last) {}
	constexpr itr begin() const noexcept { return itr(f); }
	constexpr itr end() const noexcept { return itr(l); }
};
template <class T = usize> class revrep {
	const T f, l;

public:
	class itr {
		friend revrep;
		T i;
		constexpr itr(T x) noexcept : i(x) {}

	public:
		void operator++() noexcept { --i; }
		constexpr T operator*() const noexcept { return i; }
		constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
	};
	constexpr revrep(const T first, const T last) noexcept : f(first), l(last) {}
	constexpr itr begin() const noexcept { return itr(l - 1); }
	constexpr itr end() const noexcept { return itr(f - 1); }
};
template <class T> bool amax(T &a, const T &b) {
	return a <= b ? (a = b, 1) : 0;
}
template <class T> bool amin(T &a, const T &b) {
	return b <= a ? (a = b, 1) : 0;
}
template <class T> bool asmax(T &a, const T &b) {
	return b <= a ? 0 : (a = b, 1);
}
template <class T> bool asmin(T &a, const T &b) {
	return a <= b ? 0 : (a = b, 1);
}
template <class T> using vec_alias = ::std::vector<T>;
template <class T> auto md_vec(usize n, const T &value) {
	return ::std::vector<T>(n, value);
}
template <class... Args> auto md_vec(usize n, Args... args) {
	return ::std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
}
template <class T> const T &as_const(const T &v) noexcept { return v; }
template <class T> constexpr T difference(const T &a, const T &b) {
	return a <= b ? b - a : a - b;
}
#include <cassert>
#include <cstdint>

template <::std::uint_least32_t Modulus> class modint {
	using u32 = ::std::uint_least32_t;
	using u64 = ::std::uint_least64_t;
	using i64 = ::std::int_fast64_t;
	class optimize_tag_t {};
	static constexpr optimize_tag_t optimize_tag{};

public:
	using value_type = u32;
	value_type a;

private:
	static constexpr value_type cst(i64 x) noexcept {
		x %= static_cast<i64>(Modulus);
		if (x < static_cast<i64>(0)) {
			x += static_cast<i64>(Modulus);
		}
		return static_cast<value_type>(x);
	}

	constexpr modint(optimize_tag_t, const value_type &x) noexcept : a(x) {}

public:
	constexpr modint() noexcept : a(static_cast<value_type>(0)) {}
	constexpr modint(const i64 &x) noexcept : a(cst(x)) {}
	constexpr value_type value() const noexcept { return a; }
	constexpr modint operator+(const modint &o) const noexcept {
		return modint(optimize_tag,
			a + o.a < Modulus ? a + o.a : a + o.a - Modulus);
	}
	constexpr modint operator-(const modint &o) const noexcept {
		return modint(optimize_tag, a < o.a ? a + Modulus - o.a : a - o.a);
	}
	constexpr modint operator*(const modint &o) const noexcept {
		return modint(
			optimize_tag,
			static_cast<value_type>(static_cast<u64>(a) * static_cast<u64>(o.a) %
				static_cast<u64>(Modulus)));
	}
	constexpr modint operator/(const modint &o) const {
		return modint(
			optimize_tag,
			static_cast<value_type>(static_cast<u64>(a) * static_cast<u64>((~o).a) %
				static_cast<u64>(Modulus)));
	}
	modint &operator+=(const modint &o) noexcept {
		if ((a += o.a) >= Modulus)
			a -= Modulus;
		return *this;
	}
	modint &operator-=(const modint &o) noexcept {
		if (a < o.a)
			a += Modulus;
		a -= o.a;
		return *this;
	}
	modint &operator*=(const modint &o) noexcept {
		a = static_cast<value_type>(static_cast<u64>(a) * static_cast<u64>(o.a) %
			static_cast<u64>(Modulus));
		return *this;
	}
	modint &operator/=(const modint &o) {
		a = static_cast<u64>(a) * (~o).a % Modulus;
		return *this;
	}
	constexpr modint inverse() const noexcept {
		assert(a != static_cast<value_type>(0) && "0 does not have inverse");
		return pow(static_cast<u64>(Modulus - static_cast<value_type>(2)));
	}
	constexpr modint operator~() const noexcept { return inverse(); }
	constexpr modint operator-() const noexcept {
		if (a == static_cast<value_type>(0)) {
			return modint(optimize_tag, static_cast<value_type>(0));
		}
		else {
			return modint(optimize_tag, Modulus - a);
		}
	}
	modint &operator++() noexcept {
		if (++a == Modulus) {
			a = static_cast<value_type>(0);
		}
		return *this;
	}
	modint &operator--() noexcept {
		if (a == static_cast<value_type>(0)) {
			a = Modulus;
		}
		--a;
		return *this;
	}
	constexpr bool operator==(const modint &o) const noexcept { return a == o.a; }
	constexpr bool operator!=(const modint &o) const noexcept { return a != o.a; }
	constexpr bool operator<(const modint &o) const noexcept { return a < o.a; }
	constexpr bool operator<=(const modint &o) const noexcept { return a <= o.a; }
	constexpr bool operator>(const modint &o) const noexcept { return a > o.a; }
	constexpr bool operator>=(const modint &o) const noexcept { return a >= o.a; }
	constexpr explicit operator bool() const noexcept { return a; }
	constexpr explicit operator value_type() const noexcept { return a; }
	modint pow(u64 x) const noexcept {
		u64 t = a, u = 1;
		while (x) {
			if (x & 1)
				u = u * t % Modulus;
			t = (t * t) % Modulus;
			x >>= 1;
		}
		return modint(optimize_tag, static_cast<value_type>(u));
	}
};
#include <array>
#include <cstddef>
#include <cstdint>

::std::size_t ctz64(const ::std::uint_fast64_t c) {
#ifdef __has_builtin
	return __builtin_ctzll(c);
#else
	static const ::std::array<::std::size_t, 64> table = {
		0,  1,  2,  7,  3,  13, 8,  27, 4,  33, 14, 36, 9,  49, 28, 19,
		5,  25, 34, 17, 15, 53, 37, 55, 10, 46, 50, 39, 29, 42, 20, 57,
		63, 6,  12, 26, 32, 35, 48, 18, 24, 16, 52, 54, 45, 38, 41, 56,
		62, 11, 31, 47, 23, 51, 44, 40, 61, 30, 22, 43, 60, 21, 59, 58 };
	return table[(c & ~c + 1) * 0x218A7A392DD9ABFULL >> 58 & 0x3F];
#endif
}
#include <cstddef>
#include <cstdint>

::std::size_t popcount64(::std::uint_fast64_t c) {
#ifdef __has_builtin
	return __builtin_popcountll(c);
#else
	c = (c & 0x5555555555555555ULL) + (c >> 1 & 0x5555555555555555ULL);
	c = (c & 0x3333333333333333ULL) + (c >> 2 & 0x3333333333333333ULL);
	c = (c + (c >> 4)) & 0x0F0F0F0F0F0F0F0FULL;
	return static_cast<::std::size_t>(c * 0x0101010101010101ULL >> 56 & 0x7f);
#endif
}



#include <algorithm>
#include <iostream>
#include <utility>
#include <string>

int main() {
	using mint = modint<1000000007>;
	::std::string s;
	::std::cin >> s;
	usize d;
	::std::cin >> d;
	::std::vector<mint> dp(d);
	usize cur = 0;
	for(const auto c:s){
		::std::vector<mint> nt(d);
		for (const auto i : rep<>(0, d)) {
			for (const auto k : rep<>(0, 10)) {
				nt[(i + k) % d] += dp[i];
			}
		}
		for (const auto i : rep<>(0, c - '0')) {
			++nt[(cur + i) % d];
		}
		cur = (cur + c - '0') % d;
		dp = ::std::move(nt);
	}
	if (cur != 0) {
		--dp[0];
	}
	::std::cout << dp[0].value() << ::std::endl;
	return 0;
}
