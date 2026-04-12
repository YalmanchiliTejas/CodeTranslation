#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <random>
#include <cmath>
#include <climits>
int lower_bound(const std::vector<int> &array, const int target) {
	int left = 0, right = array.size() - 1;
	while (left < right) {
		if (array[(left + right) / 2] < target) {
			left = (left + right) / 2 + 1;
		}
		else {
			right = (left + right) / 2;
		}
	}
	return right;
}
int search(const int init, const int next, const std::vector<int> &numbers, std::vector<std::vector<bool>> &is_searched) {
	auto pos = lower_bound(numbers, next);
	if (numbers[pos] != next) return 1;
	else {
		if (is_searched[init][pos - init]) return 1;
		else {
			is_searched[init][pos - init] = true;
			return search(pos, next - numbers[init] + next, numbers, is_searched) + 1;
		}
	}
}
int main() {
	int n; std::cin >> n;
	std::vector<int> numbers(n); for (auto &n : numbers) std::cin >> n;
	std::sort(numbers.begin(), numbers.end());
	std::vector<std::vector<bool>> is_searched(n); for (auto i = 0; i < n; ++i) is_searched[i] = std::vector<bool>(n - i, false);
	auto max = 0;
	for (auto i = 0; i < n; ++i) {
		for (auto j = i + 1; j < n; ++j) {
			auto len = search(i, numbers[j], numbers, is_searched);
			if (len > max) max = len;
		}
	}
	std::cout << max << std::endl;
}
