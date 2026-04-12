//#define NDEBUG
#define _CRT_SECURE_NO_WARNINGS
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

#include <algorithm>
#include <cstdio>
#include <utility>
#include <array>

int main() {
	using ull = unsigned long long;
	ull n, x;
	scanf("%llu%llu", &n, &x);
	static constexpr ::std::array<ull, 50>
		s{ { 1, 5, 13, 29, 61, 125, 253, 509, 1021, 2045, 4093, 8189, 16381, 32765, 65533, 131069, 262141, 524285, 1048573, 2097149, 4194301, 8388605, 16777213, 33554429, 67108861, 134217725, 268435453, 536870909, 1073741821, 2147483645, 4294967293, 8589934589, 17179869181, 34359738365, 68719476733, 137438953469, 274877906941, 549755813885, 1099511627773, 2199023255549, 4398046511101, 8796093022205, 17592186044413, 35184372088829, 70368744177661, 140737488355325, 281474976710653, 562949953421309, 1125899906842621, 2251799813685245} },
		p{ { 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647, 4294967295, 8589934591, 17179869183, 34359738367, 68719476735, 137438953471, 274877906943, 549755813887, 1099511627775, 2199023255551, 4398046511103, 8796093022207, 17592186044415, 35184372088831, 70368744177663, 140737488355327, 281474976710655, 562949953421311, 1125899906842623, } };
	ull ans{ 0 };
	while (n--&&x) {
		if (x >= s[n] + 2) {
			ans += p[n] + 1;
			x -= s[n] + 2;
		}
		else {
			--x;
		}
	}
	if (x) {
		++ans;
	}
	printf("%llu\n", ans);
	return 0;
}
