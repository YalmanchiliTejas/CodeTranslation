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
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>

#include<cstdlib>
#include<ctime>

namespace lib
{
	using namespace boost::range;
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

	template<class T, class... Ts>auto make_array(T const& val, Ts const&... vals)
	{
		return std::array<T, sizeof...(Ts)+1>{val, vals...};
	}


	template<class Selector>auto make_compare(Selector selector)
	{
		return [=](auto const& lhs, auto const& rhs) {return selector(lhs) < selector(rhs); };
	}

	template<class Iterator>auto make_range(Iterator first, Iterator last)
	{
		struct return_type
		{
			Iterator first;
			Iterator last;
			auto begin()const
			{
				return first;
			}
			auto end()const
			{
				return last;
			}
		};
		return return_type{ first, last };
	}

	auto irange(std::int64_t first, std::int64_t last)
	{
		return boost::irange(first, last);
	}

	template<class T>auto get_factorial_array(std::size_t size)
	{
		std::vector<T> ret(size + 1);
		ret[0] = 1;
		for (std::size_t i = 1; i <= size; ++i)
		{
			ret[i] = ret[i - 1] * T(i);
		}
		return ret;
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
	std::cout << std::fixed;
	Main();
}

typedef lib::modnum<1000000007> mod_t;

void Main()
{
	std::int64_t N, K;
	std::cin >> N >> K;
	std::int64_t count = 0;
	if (K == 0)
	{
		std::cout << N * N << std::endl;
	}
	else
	{
		for (std::int64_t b = K + 1; b <= N; ++b)
		{
			auto x = N / b;
			auto c = x * (b - K) + ((N%b) >= K ? (N%b) - K + 1 : 0);
			count += c;
		}
		std::cout << count << std::endl;
	}
}