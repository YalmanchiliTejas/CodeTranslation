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
#include <cassert>
#include <utility>

template <class CommutativeMonoid, template <class> class Container>
class fenwick_tree {

public:
	using value_structure = CommutativeMonoid;
	using value_type = typename value_structure::value_type;
	using container_type = Container<value_type>;
	using const_reference = typename container_type::const_reference;
	using size_type = typename container_type::size_type;

private:
	size_type base_size;
	container_type tree;
	static size_type getsize(const size_type size) {
		size_type ret = 1;
		while (ret < size)
			ret <<= 1;
		return ret;
	}

public:
	fenwick_tree() : base_size(0), tree() {}
	explicit fenwick_tree(const size_type size)
		: base_size(getsize(size)), tree(size + 1, value_structure::identity()) {}

	bool empty() const { return size() == 0; }
	size_type size() const { return tree.size() - 1; }

	value_type fold(size_type last) const {
		assert(last <= size());
		value_type ret = value_structure::identity();
		for (; last; last &= last - 1)
			ret = value_structure::operation(tree[last], ::std::move(ret));
		return ret;
	}
	template <class F> size_type search(const F &f) const {
		if (f(value_structure::identity()))
			return 0;
		size_type i = 0, k = base_size;
		value_type acc = value_structure::identity();
		while (k >>= 1)
			if ((i | k) < tree.size() &&
				!f(value_structure::operation(acc, tree[i | k])))
				acc = value_structure::operation(::std::move(acc), tree[i |= k]);
		return i + 1;
	}

	void add(size_type index, const value_type &value) {
		assert(index < size());
		for (++index; index < tree.size(); index += index & ~index + 1)
			tree[index] = value_structure::operation(::std::move(tree[index]), value);
	}
};
#include <algorithm>
#include <limits>
template <class T> class max_monoid {
public:
	using value_type = T;
	static value_type operation(const value_type &x, const value_type &y) {
		return ::std::max(x, y);
	}
	static value_type identity() {
		return ::std::numeric_limits<value_type>::lowest();
	}
	static value_type reverse(const value_type &x) { return x; }
};



#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <cstdio>

int main() {
	usize n;
	::std::cin >> n;
	::std::vector<i64> a(n), sum(n + 1, 0);
	for (const auto i : rep<>(0, n)) {
		::std::cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	auto dp = md_vec(n + 1, n + 1, i64(0));
	for (const auto w : rep<>(1, n + 1)) {
		for (const auto i : rep<>(0, n + 1 - w)) {
			const usize l = i, r = i + w;
			dp[l][r] = sum[r] - sum[l] -
				::std::min(dp[l + 1][r], dp[l][r - 1]);
		}
	}
	::std::cout << dp[0][n] * 2 - sum[n] << ::std::endl;
	return 0;
}
