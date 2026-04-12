#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits>


int64_t getAllPattyNumber(const int64_t l) {
	int64_t result = 1L;
	for (int64_t i = 0; i < l + 1; ++i) {
		result *= 2L;
	}
	return result - 1;
//	return std::pow(2, l + 1) - 1;
}

int64_t getAllLayerNumber(const int64_t l) {
	int64_t result = 1L;
	for (int64_t i = 0; i < l + 2; ++i) {
		result *= 2L;
	}
	return result - 3;
	//	return std::pow(2, l + 2) - 3;
}

int64_t getPattyNumber(const int64_t n, const int64_t x) {
	const auto current_all_layer_number = getAllLayerNumber(n);
	if (current_all_layer_number < x) {
		return -1;
	}
	if (n == 0) {
		return 1;
	}
	if (x == 1) {
		// first one is bans if n > 0
		return 0;
	}
	if (x == current_all_layer_number) {
		return getAllPattyNumber(n);
	}
	const auto previous_patty_number = getAllPattyNumber(n - 1);
	if (x == (current_all_layer_number + 1) / 2) {
		return previous_patty_number + 1;
	}
	if (x < (current_all_layer_number + 1) / 2) {
		return getPattyNumber(n - 1, x - 1);
	}
	else {
		return previous_patty_number + 1 +
			getPattyNumber(n - 1, x - (current_all_layer_number + 1) / 2);
	}
}
int main() {
	int64_t n, x;
	std::cin >> n >> x;
	std::cout << getPattyNumber(n, x) << std::endl;
}