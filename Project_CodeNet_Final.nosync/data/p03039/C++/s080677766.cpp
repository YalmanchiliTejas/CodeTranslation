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
constexpr long long int Mod = 1000000007L;
int main() {
	int n, m, k; std::cin >> n >> m >> k;
	std::vector<long long int> factorial(n * m + 1, 1);
	std::vector<long long int> inverse(n * m + 1, 1);
	std::vector<long long int> inverse_factorial(n * m + 1, 1);
	for (auto i = 2; i <= n * m; ++i) {
		factorial[i] = (factorial[i - 1] * i) % Mod;
		inverse[i] = (Mod - (inverse[Mod % i] * (Mod / i) % Mod)) % Mod;
		inverse_factorial[i] = (inverse_factorial[i - 1] * inverse[i]) % Mod;
	}
	long long int result = 0;
	for (long long int h = 1; h < n; ++h) {
		auto score = ((n - h) * m) * h;
		result += score;
		result %= Mod;
	}
	for (long long int w = 1; w < m; ++w) {
		auto score = ((m - w) * n) * w;
		result += score;
		result %= Mod;
	}
	for (long long int h = 1; h < n; ++h) for (long long int w = 1; w < m; ++w) {
		auto score = ((n - h) * (m - w) * 2) * (h + w);
		result += score;
		result %= Mod;
	}
	auto others = ((factorial[n * m - 2] * inverse_factorial[n * m - k]) % Mod * inverse_factorial[k - 2]) % Mod;
	result = (result * others) % Mod;
	std::cout << result << std::endl;
}

