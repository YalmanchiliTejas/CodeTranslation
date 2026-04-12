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
			return base*base;
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
	template<class T>void sort(std::vector<T>& vec)
	{
		std::sort(vec.begin(), vec.end());
	}

	template<class T>auto lower_bound(std::vector<T>const& vec, T v)
	{
		return std::distance(vec.begin(), std::lower_bound(vec.begin(), vec.end(), v));
	}
	template<class T>auto upper_bound(std::vector<T>const& vec, T v)
	{
		return std::distance(vec.begin(), std::upper_bound(vec.begin(), vec.end(), v));
	}

	struct scope_exit
	{
		std::function<void(void)> func;
		scope_exit(std::function<void(void)> f):func(f)
		{

		}
		~scope_exit()
		{
			func();
		}
	};

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

	static constexpr int intlog2(int x)
	{
		for (int i = 0, j = 2; i < 32; ++i, j <<= 1)
		{
			if (j > x)
			{
				return i;
			}
		}
		return 32;
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

void Main()
{
	std::int64_t N;
	std::cin >> N;
	std::vector<std::int64_t> vec(N);
	std::int64_t sum{};
	for (auto& v : vec)
	{
		std::cin >> v;
		sum += v;
	}
	std::int64_t count{};
	while (*std::max_element(vec.begin(), vec.end()) >= N)
	{
		std::int64_t c{};
		for (auto& v : vec)
		{
			auto u = v / N;
			c += u;
			v -= u*(N + 1);
		}
		for (auto& v : vec)
		{
			v += c;
		}
		count += c;
	}
	std::cout << count << std::endl;
}