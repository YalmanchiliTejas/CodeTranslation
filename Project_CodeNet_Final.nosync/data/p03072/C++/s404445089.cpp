#include <iostream>
#include <string>
#include <vector>

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int N, r = 0, max = 0;
	std::cin >> N;
	std::vector<int> H(N);

	for (auto &h : H) {
		std::cin >> h;
		if (max <= h) {
			r++;
			max = h;
		}
	}

	std::cout << r << std::endl;
	return 0;
}
