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
		T operator*() const noexcept { return i; }
		bool operator!=(const itr x) const noexcept { return i != x.i; }
	};
	constexpr rep(const T first, const T last) noexcept : f(first), l(last) {}
	itr begin() const noexcept { return itr(f); }
	itr end() const noexcept { return itr(l); }
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
		T operator*() const noexcept { return i; }
		bool operator!=(const itr x) const noexcept { return i != x.i; }
	};
	constexpr revrep(const T first, const T last) noexcept : f(first), l(last) {}
	itr begin() const noexcept { return itr(l - 1); }
	itr end() const noexcept { return itr(f - 1); }
};
template <class T> bool maxi(T &a, const T &b) {
	return a <= b ? (a = b, 1) : 0;
}
template <class T> bool mini(T &a, const T &b) {
	return b <= a ? (a = b, 1) : 0;
}
template <class T> bool smaxi(T &a, const T &b) {
	return b <= a ? 0 : (a = b, 1);
}
template <class T> bool smini(T &a, const T &b) {
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

#include <cassert>
#include <cstdint>

template <template <class> class Container> class eratosthenes {
	using uint64 = ::std::uint_fast64_t;

public:
	using container_type = Container<uint64>;
	using size_type = typename container_type::size_type;

protected:
	container_type c;
	size_type s;

public:
	eratosthenes() : c(), s(0) {}
	explicit eratosthenes(const size_type size)
		: c((size >> 6) + 1, ~static_cast<uint64>(0)), s(size) {
		c[0] ^= 3;
		for (size_type i = 2; i * i < size; ++i)
			if (c[i >> 6] >> (i & 0x3F) & 1)
				for (size_type j = i * i; j < size; j += i)
					c[j >> 6] &= ~(static_cast<uint64>(1) << (j & 0x3F));
	}

	bool empty() const { return !s; }
	size_type size() const { return s; }

	bool test(const size_type i) const {
		assert(i < size());
		return c[i >> 6] >> (i & 0x3F) & 1;
	}
	bool operator[](const size_type i) const {
		assert(i < size());
		return c[i >> 6] >> (i & 0x3F) & 1;
	}
};

template <class T> T difference(const T &a, const T &b) {
	return a <= b ? b - a : a - b;
}


#include <array>
#include <algorithm>
#include <iostream>
#include <utility>

int main() {
	u32 x;
	::std::cin >> x;
	::std::cout << (x == 7 || x == 5 || x == 3 ? "YES" : "NO") << ::std::endl;
	return 0;
}
