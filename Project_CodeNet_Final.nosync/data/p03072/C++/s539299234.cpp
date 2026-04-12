#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
#include <cmath>
#include <vector>
int main() {
	int n; std::cin >> n;
	std::vector<int> heights(n);
	for (auto& h : heights) std::cin >> h;
	std::vector<int> max_left(n, 0);
	for (auto i = 1; i < max_left.size(); ++i) max_left[i] = std::max(heights[i  - 1], max_left[i - 1]);
	auto count = 0;
	for (auto i = 0; i < n; ++i) {
		if (heights[i] >= max_left[i]) ++count;
	}
	std::cout << count << std::endl;
}