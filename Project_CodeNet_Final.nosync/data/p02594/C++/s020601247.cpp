#include "bits/stdc++.h"
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/dynamic_bitset.hpp>
namespace adaptor = boost::adaptors;
using index_t = std::size_t;

namespace lib
{
	using graph_t = std::vector<std::set<index_t>>;
	template<class T>using weighted_graph_t = std::vector<std::map<index_t, T>>;

	struct max_t
	{
		template<class T>constexpr T operator()(T const& lhs, T const& rhs)const
		{
			return std::max(lhs, rhs);
		}
	};
	struct min_t
	{
		template<class T>constexpr T operator()(T const& lhs, T const& rhs)const
		{
			return std::min(lhs, rhs);
		}
	};

	constexpr max_t max;
	constexpr min_t min;

	template<class T>auto order_by(T func)
	{
		return [=](auto&& lhs, auto&& rhs)
		{
			return func(lhs) < func(rhs);
		};
	}

	template<class T>constexpr auto max_v = std::numeric_limits<T>::max();
	template<class T>constexpr auto min_v = std::numeric_limits<T>::min();

	template<class T>using p_queue = std::priority_queue<T, std::vector<T>, std::greater<>>;
}

void Main()
{
	int X;
	std::cin >> X;
	std::cout << (30 <= X ? "Yes" : "No") << std::endl;
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}