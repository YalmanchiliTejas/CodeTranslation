#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>
#include<boost/operators.hpp>
#include<boost/dynamic_bitset.hpp>

namespace adaptor = boost::adaptors;

void Main()
{
	int N;
	std::cin >> N;
	std::multiset<int> maxes;
	int first;
	std::cin >> first;
	maxes.emplace(first);
	for (int i : boost::irange(1, N))
	{
		int a;
		std::cin >> a;
		auto ite = maxes.lower_bound(a);
		if (ite != maxes.cbegin())
		{
			--ite;
			maxes.erase(ite);
		}
		maxes.emplace(a);
	}
	std::cout << maxes.size() << std::endl;
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}