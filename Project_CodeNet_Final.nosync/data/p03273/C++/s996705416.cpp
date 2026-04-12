#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <numeric>
#include <iomanip>

int main(void) {
	int a, b;

	std::cin >> a >> b;

	std::vector<std::string> v(a);

	for (size_t i = 0; i < a; i++) {
		std::cin >> v[i];
	}

	std::vector<int> x(b), y(a);

	for (size_t i = 0; i < a; i++) {
		if (std::count(v[i].begin(), v[i].end(), '#') != 0) {
			y[i] = 1;
		}
	}

	for (size_t i = 0; i < b; i++) {
		int count = 0;
		for (size_t j = 0; j < a; j++) {
			if (v[j][i] == '#') {
				count++;
			}
		}

		if (count != 0) {
			x[i] = 1;
		}
	}

	for (size_t i = 0; i < a; i++) {
		for (size_t j = 0; j < b; j++) {
			if (y[i] != 0 && x[j] != 0) {
				std::cout << v[i][j];
			}
		}
		if (y[i] != 0)
		std::cout << std::endl;
	}

	return 0;
}