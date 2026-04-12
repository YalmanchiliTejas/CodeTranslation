#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<boost/multi_array.hpp>
#include<boost/variant.hpp>
#include<boost/optional.hpp>

#include<cstdlib>
#include<ctime>

namespace lib
{
	template<std::uint64_t Mod>struct modnum;
	template<class T>constexpr T pow(T base, std::size_t p)
	{
		if (p == 0)
		{
			return T(1);
		}
		else if (p == 1)
		{
			return base;
		}
		else if (p == 2)
		{
			return base * base;
		}
		else if (p % 2 == 0)
		{
			return pow(pow(base, p / 2), 2);
		}
		else
		{
			return pow(pow(base, p / 2), 2)*base;
		}
	}
	template<std::uint64_t Mod>constexpr auto inverse(modnum<Mod> const&);

	template<std::uint64_t Mod>struct modnum
	{
		static constexpr auto mod = Mod;
		std::uint64_t val;
		modnum() = default;
		constexpr modnum(std::uint64_t v):val(v%Mod)
		{

		}

		constexpr modnum& operator+=(modnum const& v)
		{
			val += v.val;
			val %= mod;
			return *this;
		}
		constexpr modnum& operator-=(modnum const& v)
		{
			val += mod - v.val;
			val %= mod;
			return *this;
		}
		constexpr modnum& operator*=(modnum const& v)
		{
			val *= v.val;
			val %= mod;
			return *this;
		}
		constexpr modnum& operator/=(modnum const& v)
		{
			return operator*=(inverse(v));
		}
	};
	template<std::uint64_t Mod>constexpr auto operator+(modnum<Mod> lhs, modnum<Mod>const& rhs)
	{
		return lhs += rhs;
	}
	template<std::uint64_t Mod>constexpr auto operator-(modnum<Mod> lhs, modnum<Mod>const& rhs)
	{
		return lhs -= rhs;
	}
	template<std::uint64_t Mod>constexpr auto operator*(modnum<Mod> lhs, modnum<Mod>const& rhs)
	{
		return lhs *= rhs;
	}
	template<std::uint64_t Mod>constexpr auto operator/(modnum<Mod> lhs, modnum<Mod>const& rhs)
	{
		return lhs /= rhs;
	}

	template<std::uint64_t Mod>constexpr auto inverse(modnum<Mod>const& base)
	{
		return pow(base, Mod - 2);
	}

	template<class T>constexpr auto clamp(T v)
	{
		return std::max(v, T());
	}
	template<class T>void sort(T& vec)
	{
		std::sort(vec.begin(), vec.end());
	}
	template<class T, class Compare>void sort(T& vec, Compare&& compare)
	{
		std::sort(vec.begin(), vec.end(), std::forward<Compare>(compare));
	}


	template<class T>auto lower_bound(std::vector<T>const& vec, T v)
	{
		return std::distance(vec.begin(), std::lower_bound(vec.begin(), vec.end(), v));
	}
	template<class T>auto upper_bound(std::vector<T>const& vec, T v)
	{
		return std::distance(vec.begin(), std::upper_bound(vec.begin(), vec.end(), v));
	}

	template<int val>using int_tag = std::integral_constant<int, val>;

	template<class Return, class Argument>struct minimam_searcher
	{
		Return operator()(std::function<Return(Argument)> func, Argument beg, Argument end)const
		{
			Return min = std::numeric_limits<Return>::max();
			for (; beg != end; ++beg)
			{
				min = std::min(min, func(beg));
			}
			return min;
		}
	};
	template<class Return, class Argument>constexpr minimam_searcher<Return, Argument> minimam{};

	template<class T>T gcd(T a, T b)
	{
		if (a > b)
		{
			return gcd(b, a);
		}
		if (a == T())
		{
			return b;
		}
		return gcd(b%a, a);
	}

	static constexpr std::int64_t intlog2(std::int64_t x)
	{
		for (std::int64_t i = 0, j = 2; i < 64; ++i, j <<= 1)
		{
			if (j > x)
			{
				return i;
			}
		}
		return 64;
	}

	struct segtree
	{
		std::vector<std::int64_t> tree;
		std::size_t depth_;
		segtree(std::size_t depth):tree(std::size_t(1) << (depth + 1)), depth_(depth)
		{

		}

		void change(std::size_t index, std::int64_t val)
		{
			change(index, val, 0);
		}

		std::int64_t get(std::size_t left, std::size_t right)//[left, right]の範囲
		{
			return get(left, right + 1, 0, 1, 0);
		}

		void increment(std::size_t index)
		{
			increment(index, 0);
		}

		void decrement(std::size_t index)
		{
			decrement(index, 0);
		}
	private:
		std::int64_t change(std::size_t index, std::int64_t val, std::size_t dep)
		{
			auto shift = std::size_t(1) << dep;
			auto s = std::size_t(1) << (depth_ - dep);
			if (dep == depth_)
			{
				std::swap(tree[shift + index / s - 1], val);
				return val;
			}
			else
			{
				auto v = change(index, val, dep + 1);
				tree[shift + index / s - 1] += val - v;
				return v;
			}
		}

		std::int64_t get(std::size_t a, std::size_t b, std::size_t left, std::size_t right, std::size_t dep)
		{
			auto lshift = left << (depth_ - dep);
			auto rshift = right << (depth_ - dep);
			if (a <= lshift && rshift <= b)
			{
				return tree[(std::size_t(1) << dep) + left - 1];
			}
			else if (rshift <= a || b <= lshift)
			{
				return 0;
			}
			else
			{
				return
					get(a, b, left << 1, left + right, dep + 1) +
					get(a, b, left + right, right << 1, dep + 1);
			}
		}

		void increment(std::size_t index, std::size_t dep)
		{
			auto shift = std::size_t(1) << dep;
			auto s = std::size_t(1) << (depth_ - dep);
			++tree[shift + index / s - 1];
			if (dep != depth_)
			{
				increment(index, dep + 1);
			}
		}

		void decrement(std::size_t index, std::size_t dep)
		{
			auto shift = std::size_t(1) << dep;
			auto s = std::size_t(1) << (depth_ - dep);
			--tree[shift + index / s - 1];
			if (dep != depth_)
			{
				decrement(index, dep + 1);
			}
		}
	};
	template<class T, int N>class binary_indexed_tree
	{
		std::array<T, N> ar;
	public:
		binary_indexed_tree(T val = 0)//全ての要素をvalで初期化する
			:ar{}
		{
			for (int i = 1; i <= N; ++i)
			{
				ar[i - 1] = (i&-i)*val;
			}
		}
		void add(T val, int index)//index番の要素にvalを足す
		{
			++index;
			for (; index <= N; index += index & -index)
			{
				ar[index - 1] += val;
			}
		}
		T get(int index)const//0からindex番までの要素の和を返す
		{
			T ret{};
			for (++index; index > 0; index -= index & -index)
			{
				ret += ar[index - 1];
			}
			return ret;
		}
	};

	template<class T>using p_queue = std::priority_queue<T, std::vector<T>, std::greater<>>;

	template<class T>auto max(std::vector<T>const& vec)
	{
		return *std::max_element(vec.begin(), vec.end());
	}
	template<class T>auto min(std::vector<T>const& vec)
	{
		return *std::min_element(vec.begin(), vec.end());
	}

	struct union_find_light
	{
		std::vector<int> upper;
		union_find_light(std::size_t size):upper(size, -1)
		{

		}

		int group(int index)
		{
			if (upper[index] == -1)
			{
				return index;
			}
			else
			{
				auto ret = group(upper[index]);
				upper[index] = ret;
				return ret;
			}
		}

		bool merge(int x, int y)
		{
			auto gx = group(x);
			auto gy = group(y);
			if (gx != gy)
			{
				upper[gx] = gy;
				return true;
			}
			return false;
		}

		std::map<int, std::set<int>> get()
		{
			std::map<int, std::set<int>> ret;
			for (int i = 0; i < upper.size(); ++i)
			{
				ret[group(i)].emplace(i);
			}
			return ret;
		}
	};

	template<class T, class Selector>void orderby(std::vector<T>& vec, Selector select)
	{
		lib::sort(vec, [=](T const& lhs, T const& rhs) {return select(lhs) < select(rhs); });
	}

	template<class T, class Selector, class U, std::size_t I>auto partition_points(T const& vec, Selector select, std::array<U, I>const& val)
	{
		auto first = std::begin(vec);
		auto last = std::end(vec);
		std::array<decltype(first), I> ret;
		for (std::size_t i = 0; i < I; ++i)
		{
			ret[i] = std::partition_point(first, last, [=](auto const& lhs) {return select(lhs) < val[i]; });
			first = ret[i];
		}
		return ret;
	}

	template<class T, class... Ts>auto make_array(T const& val, Ts const&... vals)
	{
		return std::array<T, sizeof...(Ts)+1>{val, vals...};
	}
}

namespace std
{
	template<std::uint64_t Mod>decltype(auto) operator<<(ostream& ost, lib::modnum<Mod>const& v)
	{
		return ost << v.val;
	}
}

void Main();
int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	Main();
}

typedef lib::modnum<1000000007> mod_t;

void Main()
{
	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> xs(N);
	std::vector<std::pair<int, int>> ys(N);
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		xs[i] = std::make_pair(x, i);
		ys[i] = std::make_pair(y, i);
	}
	lib::sort(xs);
	lib::sort(ys);
	lib::p_queue<std::pair<int, std::pair<int, int>>> queue;
	for (int i = 1; i < N; ++i)
	{
		queue.emplace(xs[i].first - xs[i - 1].first, std::make_pair(xs[i].second, xs[i - 1].second));
		queue.emplace(ys[i].first - ys[i - 1].first, std::make_pair(ys[i].second, ys[i - 1].second));
	}
	lib::union_find_light set(N);
	std::int64_t sum{};

	while (queue.size())
	{
		auto size = queue.top().first;
		auto a = queue.top().second.first;
		auto b = queue.top().second.second;
		queue.pop();
		if (set.group(a) != set.group(b))
		{
			sum += size;
			set.merge(a, b);
		}
	}
	std::cout << sum << std::endl;
}