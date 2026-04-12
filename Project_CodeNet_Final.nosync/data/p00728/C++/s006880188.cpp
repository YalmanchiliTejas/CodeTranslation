#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	while (std::cin >> n && n) {
		std::vector<int> p;

		for (int i = 0; i < n; i++) {
			int a; std::cin >> a;
			p.push_back(a);
		}

		std::sort(p.begin(), p.end());

		int sum = 0;
		for (int i = 1; i < p.size() - 1; i++) {
			sum += p[i];
		}

		std::cout << (sum / (n - 2)) << std::endl;
	}
}
