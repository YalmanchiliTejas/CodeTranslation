#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>
#include<boost/dynamic_bitset.hpp>
namespace adaptor = boost::adaptors;
namespace lib
{
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

	struct mod_t;
	constexpr mod_t inverse(mod_t v);
	struct mod_t
	{
		static constexpr std::uint64_t mod = 1000000007;
		std::uint64_t val;
		mod_t() = default;
		constexpr mod_t(std::uint64_t v) :val(v% mod)
		{
		}

		auto& clamp()
		{
			val %= mod;
			return *this;
		}
		auto& operator+=(mod_t const& v)
		{
			val += v.val;
			return clamp();
		}
		auto& operator-=(mod_t const& v)
		{
			val += mod - v.val;
			return clamp();
		}
		auto& operator*=(mod_t const& v)
		{
			val *= v.val;
			return clamp();
		}
		auto& operator/=(mod_t const& v)
		{
			return operator*=(inverse(v));
		}
	};
	auto operator+(mod_t lhs, mod_t const& rhs)
	{
		return lhs += rhs;
	}
	auto operator-(mod_t lhs, mod_t const& rhs)
	{
		return lhs -= rhs;
	}
	auto operator*(mod_t lhs, mod_t const& rhs)
	{
		return lhs *= rhs;
	}
	auto operator/(mod_t lhs, mod_t const& rhs)
	{
		return lhs /= rhs;
	}

	constexpr mod_t inverse(mod_t base)
	{
		return pow(base, mod_t::mod - 2);
	}
	decltype(auto)operator<<(std::ostream & ost, mod_t const& rhs)
	{
		return ost << rhs.val;
	}
}
using lib::mod_t;
template<class T>using p_queue = std::priority_queue<T, std::vector<T>, std::greater<>>;
typedef std::vector<std::map<int, std::int64_t>> graph_t;

void set(int N, int S, int T, std::vector<std::int64_t>& dist, std::vector<mod_t>& count, graph_t const& edge)
{
	p_queue<std::tuple<std::int64_t, int, int>> queue;
	dist[S] = 0;
	for (auto e : edge[S])
	{
		queue.emplace(e.second, e.first, S);
	}
	count[S] = 1;
	while (queue.size())
	{
		std::int64_t d;
		int now, prev;
		std::tie(d, now, prev) = queue.top();
		queue.pop();
		if (dist[now] < d)
		{
			continue;
		}
		count[now] += count[prev];
		if (dist[now] != d)
		{
			dist[now] = d;
			for (auto e : edge[now])
			{
				queue.emplace(e.second + d, e.first, now);
			}
		}
	}
}

mod_t run(int N, int S, int T, std::vector<std::map<int, std::int64_t>>const& edge)
{
	constexpr auto vmax = std::numeric_limits<std::int64_t>::max();
	std::vector<std::int64_t> taka(N, vmax), aoki(N, vmax);
	std::vector<mod_t> taka_count(N), aoki_count(N);
	set(N, S, T, taka, taka_count, edge);
	set(N, T, S, aoki, aoki_count, edge);
	auto shortest = taka[T];
	auto all = taka_count[T] * aoki_count[S];
	for (int i : boost::irange(0, N))
	{
		if (taka[i] + aoki[i] == shortest && taka[i] == aoki[i])
		{
			all -= lib::pow(taka_count[i], 2) * lib::pow(aoki_count[i], 2);
		}
		for (auto p : edge[i])
		{
			int index;
			std::int64_t d;
			std::tie(index, d) = p;
			if (taka[i] + d + aoki[index] == shortest &&
				taka[i] < shortest / 2 &&
				aoki[index] < shortest / 2)
			{
				all -= lib::pow(taka_count[i], 2) * lib::pow(aoki_count[index], 2);
			}
		}
	}
	return all;
}
void Main()
{
	int N, M;
	std::cin >> N >> M;
	int S, T;
	std::cin >> S >> T;
	--S; --T;
	std::vector<std::map<int, std::int64_t>> edge(N);
	for (auto i : boost::irange(0, M))
	{
		int u, v;
		std::int64_t d;
		std::cin >> u >> v >> d;
		--u; --v;
		edge[u][v] = edge[v][u] = d;
	}
	std::cout << run(N, S, T, edge) << std::endl;
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}
