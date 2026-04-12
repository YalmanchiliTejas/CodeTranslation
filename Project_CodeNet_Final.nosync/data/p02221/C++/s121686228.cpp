#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <climits>
#include <numeric>
#include <queue>
#include <cmath>
#include <iomanip>
#include <array>
#include <string>
int winner(const int depth, int from, int until, const std::vector<std::vector<int>>& calculated, const std::string& state) {
	const auto length = 1 << depth;
	if (from + length == until && (calculated.front().size() <= from || until <= calculated.front().size())) 
		return calculated.front().size() <= from ? calculated[depth][from - calculated.front().size()] : calculated[depth][from];
	const auto a = winner(depth - 1, from, from + (length >> 1), calculated, state);
	const auto b = winner(depth - 1, from + (length >> 1), until, calculated, state);
	const auto x = std::min(a, b);
	const auto y = std::max(a, b);
	return state[y - x - 1] == '0' ? x : y;
}
int main() {
	int n; std::cin >> n;
	std::string str; std::cin >> str;
	std::vector<int> permutation(1 << n);
	for (auto& p : permutation) std::cin >> p;
	std::vector<std::vector<int>> calculated;
	calculated.push_back(permutation);
	for (auto d = 0; d < n; ++d) {
		std::vector<int> winner; winner.reserve(calculated.back().size() >> 1);
		const auto length = 1 << calculated.size();
		for (auto i = 0; i + length <= permutation.size(); ++i) {
			const auto x = std::min(calculated.back()[i], calculated.back()[i + (length >> 1)]);
			const auto y = std::max(calculated.back()[i], calculated.back()[i + (length >> 1)]);
			if (str[y - x - 1] == '0') 
				winner.push_back(x);
			else 
				winner.push_back(y);
		}
		calculated.push_back(winner);
	}
	for (auto i = 0; i < permutation.size(); ++i) {
		std::cout << winner(calculated.size() - 1, i, i + permutation.size(), calculated, str) << '\n';
	}
}

//https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/KUPC/3147
