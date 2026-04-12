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

int main() {
	constexpr long long int MOD = 1000000007;
	int n, m, k; std::cin >> n >> m >> k;
	std::vector<long long int> factorial(n * m + 1, 1);
	auto inv = factorial;
	auto inverse = factorial;
	for (auto i = 2; i < factorial.size(); ++i) {
		factorial[i] = i * factorial[i - 1] % MOD;
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
		inverse[i] = inv[i] * inverse[i - 1] % MOD;
	}
	long long int result = 0;
	for (long long int y = 0; y < n; ++y) {
		for (long long int x = -m + 1; x < m; ++x) {
			if (y == 0 && x <= 0) continue;
			const auto h = n - y;
			const auto w = m - std::abs(x);
			const auto d = y + std::abs(x);
			const auto comb = factorial[n * m - 2] * inverse[k - 2] % MOD * inverse[n * m - k] % MOD;
			result += h * w * d % MOD * comb % MOD;
			result %= MOD;
		}
	}
	std::cout << result << std::endl;
}
