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
#include <iterator>
#include <utility>

template <class Monoid, template <class> class Container> class segment_tree {
public:
	using value_structure = Monoid;
	using value_type = typename value_structure::value_type;
	using container_type = Container<value_type>;
	using const_reference = typename container_type::const_reference;
	using size_type = typename container_type::size_type;

protected:
	static size_type getsize(const size_type size) {
		size_type ret = 1;
		while (ret < size)
			ret <<= 1;
		return ret;
	}

	size_type size_;
	container_type tree;

	size_type base_size() const { return tree.size() >> 1; }
	void recalc(const size_type index) {
		tree[index] =
			value_structure::operation(tree[index << 1], tree[index << 1 | 1]);
	}

public:
	segment_tree() : size_(0), tree() {}
	explicit segment_tree(const size_type size)
		: size_(size), tree(getsize(size) << 1, value_structure::identity()) {}
	template <class InputIterator>
	segment_tree(InputIterator first, InputIterator last)
		: size_(::std::distance(first, last)), tree() {
		const size_type cap = getsize(size_);
		tree.reserve(cap << 1);
		tree.resize(cap, value_structure::identity());
		tree.insert(tree.end(), first, last);
		tree.resize(cap << 1, value_structure::identity());
		for (size_type i = cap - 1; i; --i)
			recalc(i);
	}

	bool empty() const { return !size_; }
	size_type size() const { return size_; }

	const_reference operator[](const size_type index) const {
		assert(index < size());
		return tree[index + base_size()];
	}
	value_type fold(size_type first, size_type last) const {
		assert(first <= last);
		assert(first <= size());
		assert(last <= size());
		value_type ret_l = value_structure::identity(),
			ret_r = value_structure::identity();
		for (first += base_size(), last += base_size(); first < last;
			first >>= 1, last >>= 1) {
			if (first & 1)
				ret_l = value_structure::operation(::std::move(ret_l), tree[first++]);
			if (last & 1)
				ret_r = value_structure::operation(tree[last - 1], ::std::move(ret_r));
		}
		return value_structure::operation(::std::move(ret_l), ::std::move(ret_r));
	}
	template <class F> size_type search(const F &f) const {
		if (f(value_structure::identity()))
			return 0;
		if (!f(tree[1]))
			return size() + 1;
		value_type acc = value_structure::identity();
		size_type i = 1;
		while (i < base_size())
			if (!f(value_structure::operation(acc, tree[i <<= 1])))
				acc = value_structure::operation(::std::move(acc), tree[i++]);
		return i - base_size() + 1;
	}

	template <class F> void update(size_type index, const F &f) {
		assert(index < size());
		index += base_size();
		tree[index] = f(::std::move(tree[index]));
		while (index >>= 1)
			recalc(index);
	}
};

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




#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <set>
#include<array>
#include<queue>

#include<string>

int main() {
	using mint = modint<1000000007>;

	u64 a_, b_, x_;
	std::cin >> a_ >> b_ >> x_;
	mint a(a_), b(b_), x(x_);
	if (x_ < a_) {
		std::cout << x.a << std::endl;
	}
	else {
		std::cout << (x + b*mint((x_ - a_) / (a_ - b_) + 1)).a << std::endl;
	}
	return 0;
}

