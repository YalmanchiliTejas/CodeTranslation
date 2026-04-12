#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <climits>
#include <stack>
#include <string>
#include <random>
#include<set>
#include <iomanip>
#include <climits>
long long int min(const std::vector<int> &series, const int left, const int right, std::vector<std::vector<long long int>> &memo);
long long int max(const std::vector<int> &series, const int left, const int right, std::vector<std::vector<long long int>> &memo) {
	if (left == right) {
		return series[left];
	}
	else if (memo[left][right - left] != LLONG_MIN) return memo[left][right - left];
	else {
		return memo[left][right - left] = std::max(min(series, left + 1, right, memo) + series[left], min(series, left, right - 1, memo) + series[right]);
	}
}
long long int min(const std::vector<int> &series, const int left, const int right, std::vector<std::vector<long long int>> &memo) {
	if (left == right) {
		return -series[left];
	}
	else {
		return std::min(max(series, left + 1, right, memo) - series[left], max(series, left, right - 1, memo) - series[right]);
	}
}
long long int solve(const std::vector<int> &series) {
	std::vector<std::vector<long long int>> memo(series.size());
	for (auto i = 0; i < memo.size(); ++i) {
		memo[i] = std::vector<long long int>(series.size() - i, LLONG_MIN);
	}
	return max(series, 0, series.size() - 1, memo);
}
int main() {
	int n; std::cin >> n;
	std::vector<int> series(n);
	for (auto &s : series) std::cin >> s;
	std::cout << solve(series) << std::endl;
}