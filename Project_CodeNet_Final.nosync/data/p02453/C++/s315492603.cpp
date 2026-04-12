#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	for (auto &v : vec) std::cin >> v;
	int q; std::cin >> q;
	for (auto i = 0; i < q; ++i) {
		int k;
		std::cin >> k;
		std::cout << std::lower_bound(vec.begin(), vec.end(), k) - vec.begin() << std::endl;
	}
}
