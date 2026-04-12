#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>

constexpr long long int MOD = 1000000007;
long long int power(long long int base, long long int exp) {
	switch (exp) {
	case 0: return 1L;
	case 1: return base % MOD;
	default: return power(base, exp % 2) * power(base * base % MOD, exp / 2) % MOD;
	}
}
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	long long int w, h; std::cin >> w >> h;
	const long long int point = (w + 1) * (h + 1);
	const long long int sum = point * (point - 1) % MOD * (point - 2) % MOD * power(6, MOD - 2) % MOD;
	long long int minus = 0;
	for (auto i = 0; i <= w; ++i) for (auto j = 0; j <= h; ++j) if (i != 0 || j != 0) {
		const auto count = (w - i + 1) * (h - j + 1);
		minus += (gcd(i, j) - 1) * count % MOD * ((i == 0 || j == 0) ? 1 : 2);
		minus %= MOD;
	}
	std::cout << ((sum - minus) % MOD + MOD) * power(2, point - 3) % MOD << '\n';
}
