#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <map>
#include <tuple>
#include <iostream>
#include <deque>
#include <array>
#include <set>
#include <functional>
#include <memory>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

int main() {
	int n; std::cin >> n;
	std::vector<int> nums(n); for (auto& num : nums) std::cin >> num;
	std::vector<int> colors(n, -1);
	for (const auto& num : nums) {
		*(std::lower_bound(colors.begin(), colors.end(), num) - 1) = num;
	}
	auto i = 0;
	for (; i < n && colors[i] == -1; ++i) {}
	std::cout << n - i << std::endl;
}