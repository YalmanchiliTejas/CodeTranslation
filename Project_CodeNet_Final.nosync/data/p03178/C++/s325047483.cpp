#include <array>
#include <cstddef>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>

template <class T, std::size_t Dimension, ::size_t D> class mdv_inner {
public:
	using value_type = T;
	using size_type = std::size_t;

	using value_itr = typename std::vector<value_type>::iterator;
	using size_itr = typename std::array<size_type, Dimension>::const_iterator;
	using itr_diff = typename std::iterator_traits<value_itr>::difference_type;

	value_itr front_iterator;
	size_itr size_iterator;

	mdv_inner(const value_itr f, const size_itr s)
		: front_iterator(f), size_iterator(std::next(s)) {}

	auto operator[](const size_type index) {
		return mdv_inner<value_type, Dimension, D - static_cast<std::size_t>(1)>(
			front_iterator + static_cast<itr_diff>(*size_iterator * index),
			size_iterator);
	}
};
template <class T, std::size_t Dimension>
class mdv_inner<T, Dimension, static_cast<std::size_t>(1)> {
public:
	using value_type = T;
	using size_type = std::size_t;

	using value_itr = typename std::vector<value_type>::iterator;
	using size_itr = typename std::array<size_type, Dimension>::const_iterator;
	using itr_diff = typename std::iterator_traits<value_itr>::difference_type;

	value_itr front_iterator;

	mdv_inner(const value_itr f, const size_itr) : front_iterator(f) {}

	value_type &operator[](const size_type index) {
		return *(front_iterator + static_cast<itr_diff>(index));
	}
};

template <class T, std::size_t Dimension> class multi_dimensional_vector {
public:
	static_assert(static_cast<std::size_t>(0) < Dimension,
		"Dimension must be larger than 0");

	using value_type = T;
	using size_type = std::size_t;

	using value_itr = typename std::vector<value_type>::iterator;
	using size_itr = typename std::array<size_type, Dimension>::const_iterator;
	using itr_diff = typename std::iterator_traits<value_itr>::difference_type;

	std::vector<value_type> table;
	std::array<size_type, Dimension> value_size;

	multi_dimensional_vector(const std::array<size_type, Dimension> &a,
		const value_type &x)
		: value_size(), table() {
		std::partial_sum(a.crbegin(), a.crend(), value_size.rbegin(),
			std::multiplies<size_type>());
		table.assign(value_size.front(), x);
	}

	auto operator[](const size_type index) {
		return mdv_inner<value_type, Dimension, Dimension>(
			table.begin(), value_size.cbegin())[index];
	}
};

#include<algorithm>
#include<cstddef>
#include<iostream>
#include<string>

int main() {
	using usize = std::size_t;
	using u32 = unsigned int;

	static constexpr u32 MOD = 1000000007;


	std::string k;
	usize d;
	std::cin >> k >> d;
	std::reverse(k.begin(), k.end());
	usize n = k.size();

	multi_dimensional_vector<u32, 3> dp({ n + 1,d,2 }, 0);
	// i 文字目 | d の剰余が j | k 未満
	dp[n][0][0] = 1;

	const auto add=[](u32 &l, const u32 &r) {
		l = (l + r) % MOD;
	};

	for (usize i = n;i--;) {
		const usize c = k[i] - '0';
		for (usize j = 0;j != d;++j) {
			for (usize l = 0;l != c;++l) {
				add(dp[i][(j + l) % d][1], dp[i + 1][j][0]);
			}
			add(dp[i][(j + c) % d][0], dp[i + 1][j][0]);
			
			for (usize l = 0;l != 10;++l) {
				add(dp[i][(j + l) % d][1], dp[i + 1][j][1]);
			}
		}
	}

	std::cout << (dp[0][0][0] + dp[0][0][1] + MOD - 1) % MOD << std::endl;

	return 0;
}
