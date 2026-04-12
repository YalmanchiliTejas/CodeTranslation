#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <climits>
#include <numeric>
#include <bitset>
#include <random>
#include <tuple>
#include <initializer_list>
#include <fstream>
#include <cctype>
#include <string>
#include <cfloat>
#include <array>


constexpr long long int MOD = 1000000007;
long long int power(long long int base, int exp) {
	switch (exp) {
	case 0: return 1L;
	case 1: return base % MOD;
	default: return power(base * base % MOD, exp >> 1) * power(base, exp & 1) % MOD;
	}
}
long long int solve(int position, int diff, bool is_use, const std::vector<long long int>& values, std::vector<std::vector<std::vector<long long int>>>& memo) {
	if (position >= values.size()) return (diff == 0) ? 0 : LONG_MIN / 2;
	if (diff < -1 || 1 < diff) return LLONG_MIN / 2;
	if (memo[position][diff + 1][is_use] != LLONG_MIN) return memo[position][diff + 1][is_use];
	long long int result{ LLONG_MIN };
	if (!is_use) {
		if (position % 2 == 1) {
			result = std::max(result, solve(position + 1, diff, true, values, memo) + values[position]);
		}
		else {
			result = std::max(result, solve(position + 1, diff - 1, true, values, memo) + values[position]);
		}
	}
	if (position % 2 == 1) {
		result = std::max(result, solve(position + 1, diff + 1, false, values, memo));
	}
	else {
		result = std::max(result, solve(position + 1, diff, false, values, memo));
	}
	return memo[position][diff + 1][is_use] = result;
}
int main() {
	int n; std::cin >> n;
	std::vector<long long int> values(n); for (auto& v : values) std::cin >> v;
	std::vector<std::vector<std::vector<long long int>>> memo(n, std::vector<std::vector<long long int>>(3, std::vector<long long int>(2, LLONG_MIN)));
	for (auto i = 1; i < n; i += 1000) {
		solve(n - i, 0, false, values, memo);
	}
	std::cout << solve(0, 0, false, values, memo) << std::endl;
}