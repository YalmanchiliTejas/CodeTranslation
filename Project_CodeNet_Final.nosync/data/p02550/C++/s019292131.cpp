#line 1 "main.cpp"
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

#line 2 "/home/ecasdqina/cpcpp/libs/library_cpp/data_structure/segment_tree.hpp"

#line 5 "/home/ecasdqina/cpcpp/libs/library_cpp/data_structure/segment_tree.hpp"

#line 2 "/home/ecasdqina/cpcpp/libs/library_cpp/data_structure/monoid.hpp"

#line 4 "/home/ecasdqina/cpcpp/libs/library_cpp/data_structure/monoid.hpp"

namespace cplib {
template<class T, T id = T{}> struct add_monoid {
	using value_type = T;

	T a;

	constexpr add_monoid(T a): a(a) {}
	static constexpr add_monoid operation(const add_monoid& l, const add_monoid& r) { return add_monoid{l.a + r.a}; }
	static constexpr add_monoid identity() { return add_monoid{id}; };
	constexpr add_monoid inverse() { return add_monoid{-a}; }
	constexpr T value() { return a; }
};

template<class T, T id = T{1}> struct mul_monoid {
	using value_type = T;

	T a;

	constexpr mul_monoid(T a): a(a) {}
	static constexpr mul_monoid operation(const mul_monoid& l, const mul_monoid& r) { return mul_monoid{l.a * r.a}; }
	static constexpr mul_monoid identity() { return mul_monoid{id}; };
	constexpr T value() { return a; }
};

template<class T, T id = T{}> struct max_monoid {
	using value_type = T;

	T a;

	constexpr max_monoid(T a): a(a) {}
	static constexpr max_monoid operation(const max_monoid& l, const max_monoid& r) { return max_monoid{std::max(l.a, r.a)}; }
	static constexpr max_monoid identity() { return max_monoid{id}; };
	constexpr T value() { return a; }
};

template<class T, T id = T{}> struct min_monoid {
	using value_type = T;

	T a;

	constexpr min_monoid(T a): a(a) {}
	static constexpr min_monoid operation(const min_monoid& l, const min_monoid& r) { return min_monoid{std::min(l.a, r.a)}; }
	static constexpr min_monoid identity() { return min_monoid{id}; };
	constexpr T value() { return a; }
};

template<class T, T& id> struct monoid {
	using value_type = T;

	T a;

	constexpr monoid(T a): a(a) {}
	static constexpr monoid operation(const monoid& l, const monoid& r) { return monoid{l.a + r.a}; }
	static constexpr monoid identity() { return monoid{id}; }
	constexpr monoid inverse() { return monoid{id.inverse()}; }
	constexpr T value() { return a; }
};
}
#line 7 "/home/ecasdqina/cpcpp/libs/library_cpp/data_structure/segment_tree.hpp"

namespace cplib {
template<class Monoid> class segment_tree {
public:
	using value_type = Monoid;
	using T = typename value_type::value_type;
	using usize = std::uint_fast32_t;

private:
	int n;
	std::vector<value_type> data;

private:
	usize base() const { return data.size() >> 1; }

public:
	segment_tree() = default;
	explicit segment_tree(usize n): n(n) {
		usize size = 1;
		while(size <= n) size <<= 1;
		data.assign(size << 1, value_type::identity());
	}
	template<class InputIt> explicit segment_tree(InputIt first, InputIt last)
	: segment_tree(std::distance(first, last)) {
		for(int index = 0; first != last; first++, index++) set(index, *first);
		build();
	}

	usize size() const { return n; }
	bool empty() const { return size() == 0; }
	void clear() {
		n = 0;
		data.clear();
	}
	void swap(segment_tree& r) {
		std::swap(n, r.n);
		data.swap(r.data);
	}

	T get(usize i) const { return data[i + base()].a; }
	void set(usize i, const value_type& x) { data[i + base()] = x; }

	void build() {
		for(usize i = (int)base() - 1; i > 0; i--)
			data[i] = value_type::operation(data[i * 2 + 0], data[i * 2 + 1]);
	}
	void change(usize i, const value_type& x) {
		data[i += base()] = x;
		while(i >>= 1) data[i] = value_type::operation(data[i * 2 + 0], data[i * 2 + 1]);
	}
	void update(usize i, const value_type& x) { change(i, value_type::operation(get(i), x)); }

	T fold(usize first, usize last) const {
		first += base();
		last += base();

		value_type lval = value_type::identity();
		value_type rval = value_type::identity();
		while(first != last) {
			if(first & 1) lval = value_type::operation(lval, data[first++]);
			if(last  & 1) rval = value_type::operation(data[--last], rval);
			first >>= 1;
			last  >>= 1;
		}
		return value_type::operation(lval, rval).a;
	}
	T fold_all() const { return data[1].a; }

	// return max{r | f(fold(l, r - 1)) = true}
	template<class F> usize search_right(int l, const F& f) const {
		if(l == size()) return base();

		l += base();
		value_type acc = value_type::identity();
		do {
			while(l % 2 == 0) l >>= 1;
			if(!f(value_type::operation(acc, data[l]))) {
				while(l < base()) {
					l = l << 1;
					if(f(value_type::operation(acc, data[l]))) {
						acc = value_type::operation(acc, data[l]);
						l += 1;
					}
				}
				return l - base();
			}
			acc = value_type::operation(acc, data[l]);
			l += 1;
		} while((l & -l) != l);
		return size();
	}

	// return min{l | f(fold(l, r - 1) = true}
	template<class F> usize search_left(int r, const F& f) const {
		if(r == 0) return 0;

		r += base();
		value_type acc = value_type::identity();
		do {
			r--;
			while(r > 1 and (r % 2)) r >>= 1;
			if(!f(value_type::operation(data[r], acc))) {
				while(r < base()) {
					r = r * 2 + 1;
					if(f(value_type::operation(data[r], acc))) {
						acc = value_type::operation(data[r], acc);
						r -= 1;
					}
				}
				return r + 1 - base();
			}
			acc = value_type::operation(data[r], acc);
		} while((r & -r) == r);
		return 0;
	}
};
}

// @docs docs/segment_tree.md
#line 18 "main.cpp"

int main() {
	i64 n; int x, m; scanf("%lld%d%d", &n, &x, &m);

	int loop = -1, length = 0;
	i64 tan = 0;
	{
		i64 now = x, tmp = x;
		std::vector<int> cnt(m, -1);
		std::vector<i64> sum(m, -1);
		for(int i = 0; i < 2 * m; i++) {
			if(sum[now] == -1) sum[now] = 0;
			else {
				loop = now;
				length = i - cnt[now];
				tan = tmp - sum[now];
				break;
			}

			cnt[now] = i;
			sum[now] = tmp;
			now = now * now % m;
			tmp += now;
		}
	}

	i64 ans = 0, now = x;
	while(n) {
		if(now == loop) break;

		ans += now;
		now = now * now % m;
		n--;
	}

	ans += n / length * tan;
	n %= length;

	while(n) {
		ans += now;
		now = now * now % m;
		n--;
	}

	printf("%lld\n", ans);
	return 0;
}
