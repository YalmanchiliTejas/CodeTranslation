#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cfloat>
#include <climits>
#include <cassert>
#include <random>

long long int lower_fact(long long int n, int k) {
	return (k == 0) ? 1 : n * lower_fact(n - 1, k - 1);
}
long long int comb(int n, int r) {
	if (n < r) return 0;
	else return lower_fact(n, r) / lower_fact(r, r);
}
long long int power(long long int base, int exp) {
	switch (exp) {
	case 0: return 1LL;
	case 1: return base;
	default: return power(base, exp & 1) * power(base * base, exp >> 1);
	}
}
long long int count_below(const std::string& str, int k, int digit) {
	if (k == 0) return 1;
	if (digit == str.size()) return 0;
	long long int result = 0;
	for (auto i = 1; i < 10; ++i) {
		if (str[digit] > '0' + i) {
			result += comb(str.size() - digit - 1, k - 1) * power(9, k - 1);
		}
		else if (str[digit] == '0' + i) {
			result += count_below(str, k - 1, digit + 1);
		}
	}
	if (str[digit] == '0') {
		result += count_below(str, k, digit + 1);
	}
	else {
		result += comb(str.size() - digit - 1, k) * power(9, k);
	}
	return result;
}

int main(){
	std::string str; std::cin >> str;
	int k; std::cin >> k;
	std::cout << count_below(str, k, 0) << std::endl;
}
