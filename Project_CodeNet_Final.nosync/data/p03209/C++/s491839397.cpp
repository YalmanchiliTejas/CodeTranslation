#include<iostream>
#include<iomanip>
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
#include<utility>

#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>
#include<boost/range/numeric.hpp>

#ifdef _MSC_FULL_VER
#include"randomizer.hpp"
#include"debug_print.hpp"
#endif

#include<cstdlib>
#include<ctime>

namespace lib
{
	template<class T>using pair = std::pair<T, T>;
	template<class T>constexpr T pow(T base, std::uint64_t p)
	{
		T ret = T(1);
		for (std::uint64_t i = 0; i <= 63; ++i)
		{
			if (((1ull << i) & p) != 0)
			{
				ret *= base;
			}
			base *= base;
		}
		return ret;
	}
	template<class T>using p_queue = std::priority_queue<T, std::vector<T>, std::greater<>>;

	struct union_find
	{
		std::vector<int> upper;
		union_find(std::size_t size):upper(size, -1) {}

		int group(int index)
		{
			if (upper[index] == -1)
			{
				return index;
			}
			else
			{
				return upper[index] = group(upper[index]);
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

		auto get()
		{
			std::map<int, std::set<int>> ret;
			for (int i = 0; i < upper.size(); ++i)
			{
				ret[group(i)].emplace(i);
			}
			return ret;
		}

		auto tops()
		{
			std::set<int> ret;
			for (int i = 0; i < upper.size(); ++i)
			{
				ret.emplace(group(i));
			}
			return ret;
		}

		bool is_same_group(int x, int y)
		{
			return group(x) == group(y);
		}
	};
}

namespace out
{
	namespace detail
	{
		template<class>struct void_out
		{
			typedef void type;
		};
		template<class T>auto write(std::ostream& ost, T const& val)
			->typename void_out<decltype(ost << val)>::type
		{
			ost << val;
		}
		template<class T, class... Ts>void write(std::ostream& ost, T const& val, Ts const&... nexts)
		{
			write(ost, val);
			ost << " ";
			write(ost, nexts...);
		}
	}
	void write_line()
	{
		std::cout << std::endl;
	}
	template<class...Ts>void write_line(Ts const&... args)
	{
		detail::write(std::cout, args...);
		write_line();
	}
	template<class Range>void write_range(Range const& rng)
	{
		for (auto const& v : rng)
		{
			write_line(v);
		}
	}
}

namespace adaptor = boost::adaptors;

void Main()
{
	int N;
	std::int64_t X;
	std::cin >> N >> X;
	std::vector<std::int64_t> size(N + 1);
	std::vector<std::int64_t> paty(N + 1);
	size[0] = 1;
	paty[0] = 1;
	for (int i : boost::irange(0, N))
	{
		size[i + 1] = 2 * size[i] + 3;
		paty[i + 1] = 2 * paty[i] + 1;
	}
	std::int64_t now = 0;
	for (int i : boost::irange(0, N) | adaptor::reversed)
	{
		if (size[i + 1] == X)
		{
			now += paty[i + 1];
			X -= size[i + 1];
			break;
		}
		else if (size[i] + 2 < X)
		{
			now += paty[i] + 1;
			X -= size[i] + 2;
		}
		else if (size[i] + 2 == X)
		{
			now += paty[i] + 1;
			X -= size[i] + 2;
			break;
		}
		else if (1 < X)
		{
			--X;
		}
		else if (1 == X)
		{
			--X;
			break;
		}
	}
	if (X == 1)
	{
		++now;
	}
	out::write_line(now);
}

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(5);
	Main();
}
