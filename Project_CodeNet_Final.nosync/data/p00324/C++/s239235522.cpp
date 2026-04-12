#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <random>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cfloat>
#include <set>
#include <map>
int main() {
	int n; std::cin >> n;
	std::map<long long int, int> map;
	int d;
	long long int prev = 0;
	auto max = 0;
	map.insert(std::make_pair(0, 0));
	for (auto i = 1; i <= n; ++i) {
		std::cin >> d;
		prev += d;
		auto res = map.emplace(std::make_pair(prev, i));
		if (!res.second) {
			if (max < i - (*res.first).second) max = i - (*res.first).second;
		}
	}
	std::cout << max << std::endl;
}
