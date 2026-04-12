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
#include<utility>

#include<boost/multi_array.hpp>
#include<boost/variant.hpp>
#include<boost/optional.hpp>
#include<boost/optional/optional_io.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>
#include<boost/range/size.hpp>
#include<boost/multiprecision/cpp_int.hpp>

#include<cstdlib>
#include<ctime>

#define FOREACH_STRUCT2(arg0,arg1,rng)\
for(auto const& p:rng)\
for(bool f = true;f;)\
for(auto const& arg0=std::get<0>(p); f;)\
for(auto const& arg1=std::get<1>(p); f; f=false)

#define FOREACH_STRUCT3(arg0, arg1, arg2, rng)\
for(auto const& p:rng)\
for(bool f=true;f;)\
for(auto const& arg0=std::get<0>(p);f;)\
for(auto const& arg1=std::get<1>(p);f;)\
for(auto const& arg2=std::get<2>(p);f;f=false)

#define DEFINE_STRUCT2(arg0, arg1, stc)\
auto const& arg0=std::get<0>(stc);\
auto const& arg1=std::get<1>(stc)

#define DEFINE_STRUCT3(arg0, arg1, arg2, stc)\
DEFINE_STRUCT2(arg0, arg1, stc);\
auto const& arg2=std::get<2>(stc)

#define DUAL_REP(arg0,arg1, fmax, smax)\
for(int arg0:boost::irange<int>(0,fmax))\
for(int arg1:boost::irange<int>(0,smax))
#define TRIPLE_REP(arg0,arg1,arg2,fmax,smax,tmax)\
DUAL_REP(arg0,arg1,fmax,smax)\
for(int arg2:boost::irange<int>(0,tmax))

namespace lib
{
	using namespace boost::range;
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

	template<class T>constexpr T gcd(T a, T b)
	{
		return a > b ? gcd(b, a) : a == T() ? b : gcd(b%a, a);
	}

	constexpr int intlog2(std::int64_t x)
	{
		std::int64_t j = 2;
		for (auto i = 0; i < 63; ++i)
		{
			if (j > x)
			{
				return int(i);
			}
			j <<= 1;
		}
		return 63;
	}

	template<class T>using p_queue = std::priority_queue<T, std::vector<T>, std::greater<>>;

	struct union_find_light
	{
		std::vector<int> upper;
		union_find_light(std::size_t size):upper(size, -1) {}

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

	template<class T>auto factorial_array(std::size_t max)
	{
		std::vector<T> ret(max + 1);
		ret[0] = 1;
		for (auto i : boost::irange<std::size_t>(1, max + 1))
		{
			ret[i] = ret[i - 1] * T(i);
		}
		return ret;
	}

	auto const first = [](auto p) {return p.first; };
	auto const second = [](auto p) {return p.second; };

	auto maxf = [](auto a, auto b) {return std::max(a, b); };
	auto minf = [](auto a, auto b) {return std::min(a, b); };

	template<class T>using dual_array = boost::multi_array<T, 2>;
	template<class T>using optional_dual_array = boost::multi_array<boost::optional<T>, 2>;
	namespace detail
	{
		template<class T>struct graph_t
		{
			typedef std::vector<std::map<int, T>> type;
		};
		template<>struct graph_t<void>
		{
			typedef std::vector<std::set<int>> type;
		};
	}
	template<class T = void>using graph = typename detail::graph_t<T>::type;
	template<class T>constexpr T min_value = std::numeric_limits<T>::min();
	template<class T>constexpr T max_value = std::numeric_limits<T>::max();
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
		template<class T, std::size_t... Is>void write_tuple(std::ostream& ost, T const& tuple, std::index_sequence<Is...>)
		{
			write(ost, std::get<Is>(tuple)...);
		}
		template<class... Ts>void write(std::ostream& ost, std::tuple<Ts...>const& tuple)
		{
			write_tuple(ost, tuple, std::make_index_sequence<sizeof...(Ts)>());
		}
		template<class T0, class T1>void write(std::ostream& ost, std::pair<T0, T1>const& pair)
		{
			write(ost, pair.first, pair.second);
		}
		template<class T>void write(std::ostream& ost, boost::optional<T>const& opt)
		{
			if (opt)
			{
				write(ost, *opt);
			}
			else
			{
				write(ost, "--");
			}
		}
		template<class T>void write(std::ostream& ost, std::vector<T>const& vec)
		{
			auto size = vec.size();
			if (size == 0)
			{
				return;
			}
			write(ost, vec[0]);
			for (auto i : boost::irange<std::size_t>(1, size))
			{
				ost << " ";
				write(ost, vec[i]);
			}
		}
		template<class T>void write(std::ostream& ost,lib::dual_array<T> const& ar)
		{
			auto a = ar.shape()[0];
			auto b = ar.shape()[1];
			write(ost, ar[0][0]);
			for (auto i : boost::irange<std::size_t>(1, b))
			{
				write(ost, " ", ar[0][i]);
			}
			for (auto i : boost::irange<std::size_t>(1, a))
			{
				ost << std::endl;
				write(ost, ar[i][0]);
				for (auto j : boost::irange<std::size_t>(1, b))
				{
					write(ost, " ", ar[i][j]);
				}
			}
		}
	}
	void write_line()
	{
		std::cout << std::endl;
	}
	template<class...Ts>void write_line(Ts const&... args)
	{
		detail::write(std::cout, args...);
		std::cout << std::endl;
	}
	void debug()
	{
		std::cerr << std::endl;
	}
	template<class...Ts>void debug(Ts const&... args)
	{
		detail::write(std::cerr, args...);
		std::cerr << std::endl;
	}
	template<class Range>void write_range(Range const& rng)
	{
		for (auto const& v : rng)
		{
			write_line(v);
		}
	}
	template<class Range>void debug_range(Range const& rng)
	{
		for (auto const& v : rng)
		{
			debug(v);
		}
	}
}

namespace adaptor = boost::adaptors;

typedef std::pair<std::int64_t, std::int64_t> int64pair;

std::int64_t run(std::vector<int64pair>const& target,int N)
{
	std::vector<std::pair<std::int64_t, bool>> vec(2 * N);
	int i = 0;
	FOREACH_STRUCT2(x, y, target)
	{
		vec[2 * i] = std::make_pair(std::min(x, y), false);
		vec[2 * i + 1] = std::make_pair(std::max(x, y), true);
		++i;
	}
	lib::sort(vec);
	std::int64_t bmin;
	int count = 1;
	std::int64_t min;
	int index;
	for (int i : boost::irange(1, 2 * N))
	{
		if (vec[i].second)
		{
			bmin = vec[i].first;
			index = i;
			break;
		}
	}
	for (int i : boost::irange(1, 2 * N))
	{
		if (!vec[i].second)
		{
			if (++count == N)
			{
				min = (vec[i].first - vec[0].first)*(vec[2 * N - 1].first - bmin);
				break;
			}
		}
	}
	std::vector<int> indexes(N);
	std::map<std::int64_t, int> blues;
	for (int i : boost::irange(0, N))
	{
		indexes[i] = i;
		++blues[target[i].first];
	}
	lib::sort(indexes, lib::make_compare([&](int i) {return target[i].first; }));
	for (int i : boost::irange(0, N))
	{
		int ind = indexes[i];
		--blues[target[ind].first];
		++blues[target[ind].second];
		if (blues[target[ind].first] == 0)
		{
			blues.erase(target[ind].first);
		}
		auto first = std::begin(blues)->first;
		auto last = std::prev(std::end(blues))->first;
		min = std::min(min, (vec[2 * N - 1].first - vec[0].first)*(last - first));
	}
	return min;
}

namespace lib
{
	struct randomizer
	{
		std::mt19937_64 random;
		randomizer():random()
		{
			std::random_device device{};
			std::array<unsigned, 623> init;
			for (auto& v : init)
			{
				v = device();
			}
			std::seed_seq seq(init.begin(), init.end());
			random = std::mt19937_64(seq);
		}
		std::int64_t operator()()
		{
			return random();
		}
		std::int64_t operator()(std::int64_t max)//[0, max]の範囲
		{
			std::uniform_int_distribution<std::int64_t> dist(0, max);
			return dist(random);
		}
		std::int64_t operator()(std::int64_t min, std::int64_t max)//[min, max]の範囲
		{
			std::uniform_int_distribution<std::int64_t> dist(min, max);
			return dist(random);
		}
		template<class RandomAccessRange>void shuffle(RandomAccessRange& rng)
		{
			std::shuffle(std::begin(rng), std::end(rng), random);
		}
	};
}

std::int64_t greedy(std::vector<int64pair>const& target, int N)
{
	std::int64_t min = lib::max_value<std::int64_t>;
	for (int f : boost::irange(0, 1 << N))
	{
		std::int64_t rmin = lib::max_value<std::int64_t>;
		std::int64_t rmax = lib::min_value<std::int64_t>;
		std::int64_t bmin = lib::max_value<std::int64_t>;
		std::int64_t bmax = lib::min_value<std::int64_t>;
		for (int i : boost::irange(0, N))
		{
			DEFINE_STRUCT2(x, y, target[i]);
			if (f&(1 << i))
			{
				rmin = std::min(rmin, x);
				rmax = std::max(rmax, x);
				bmin = std::min(bmin, y);
				bmax = std::max(bmax, y);
			}
			else
			{
				rmin = std::min(rmin, y);
				rmax = std::max(rmax, y);
				bmin = std::min(bmin, x);
				bmax = std::max(bmax, x);
			}
		}
		min = std::min(min, (rmax - rmin)*(bmax - bmin));
	}
	return min;
}

void Main()
{
	int N;
	std::cin >> N;
	std::vector<int64pair> target(N);
	for (auto& p : target)
	{
		std::int64_t x, y;
		std::cin >> x >> y;
		p = std::make_pair(std::min(x, y), std::max(x, y));
	}
	out::write_line(run(target, N));
}

int main()
{
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	std::cout << std::fixed;
	Main();
}