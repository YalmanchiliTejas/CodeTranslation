#include <iostream>
#include <cstdint>
#include <vector>

int main() {
	int64_t n;
	std::cin >> n;

	std::vector<int64_t> a(n);
	for (auto&& e : a)
		std::cin >> e;

	int64_t manipSum = 0;
	int64_t count = 0;
	do {
		manipSum = 0;
		for (auto&& e : a)
			manipSum += e / n;

		for (auto&& e : a) {
			auto tmp = manipSum - e / n;

			e %= n;
			e += tmp;
		}
		
		count += manipSum;
	} while (manipSum != 0);

	std::cout << count << std::endl;
}