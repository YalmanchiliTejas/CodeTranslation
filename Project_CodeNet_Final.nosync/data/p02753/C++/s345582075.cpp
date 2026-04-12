#include "bits/stdc++.h"
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/operators.hpp>
#include <boost/dynamic_bitset.hpp>

namespace adaptor = boost::adaptors;
using index_t = std::size_t;

void Main()
{
	std::string str;
	std::cin >> str;
	std::cout << (str == "AAA" || str == "BBB" ? "No" : "Yes") << std::endl;
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}