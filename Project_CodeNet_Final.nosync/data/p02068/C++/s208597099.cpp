#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
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

std::vector<int> primes(const int upper_limit) {
	std::vector<bool> is_prime(upper_limit + 1, true);
	for (auto i = 2; i * i <= upper_limit; ++i) {
		if (is_prime[i]) {
			for (auto j = i * i; j <= upper_limit; j += i) {
				is_prime[j] = false;
			}
		}
	}
	std::vector<int> result;
	for (auto i = 2; i <= upper_limit; ++i) {
		if (is_prime[i]) result.push_back(i);
	}
	return result;
}
std::vector<int> prime_factors(int number, const std::vector<int>& prime) {
	std::vector<int> result;
	for (const auto p : prime) {
		if (number % p == 0) {
			while (number % p == 0) {
				number /= p;
			}
			result.push_back(p);
		}
		if (p * p > number) {
			if (number != 1) result.push_back(number);
			return result;
		}
	}
	if (number != 1) result.push_back(number);
	return result;
}
long long int sum_if_friend_with(const int k, const std::vector<int>& number) {
	long long int result = 0;
	for (const auto n : number) if (n % k == 0) result += n;
	return result;
}
int main() {
	auto prime = primes(static_cast<int>(std::ceil(std::sqrt(1001000000))));
	int n; std::cin >> n;
	std::vector<int> number(n); for (auto& a : number) std::cin >> a;
	std::vector<std::vector<int>> factors(n); for (auto i = 0; i < n; ++i) factors[i] = prime_factors(number[i], prime);
	std::set<int> all_factors;
	for (const auto& factor : factors) 
		for (const auto f : factor)
			all_factors.insert(f);
	long long int max = 0LL;
	for (const auto f : all_factors) {
		max = std::max(max, sum_if_friend_with(f, number));
	}
	std::cout << max << std::endl;
}


