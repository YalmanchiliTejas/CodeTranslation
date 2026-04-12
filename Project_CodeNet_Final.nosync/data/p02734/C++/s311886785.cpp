#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <climits>
#include <bitset>
#include <random>
#include <tuple>
#include <initializer_list>
#include <fstream>


int main() {
	constexpr long long int MOD = 998244353;
	std::cin.tie(nullptr); std::cin.sync_with_stdio(false);
	int n, s; std::cin >> n >> s;
	std::vector<int> number(n); for (auto& a : number)std::cin >> a;
	std::vector<long long int> pattern(3001); pattern[0] = 1;
	long long int result = 0;
	for (auto i = 0; i < n; ++i) {
		const auto a = number[i];
		for (auto j = 3000 - a; j > 0; --j) {
			pattern[j + a] += pattern[j];
			pattern[j + a] %= MOD;
		}
		pattern[a] += i + 1;
		pattern[a] += MOD;
		result += pattern[s];
		result %= MOD;
	}
	std::cout << result << std::endl;
}