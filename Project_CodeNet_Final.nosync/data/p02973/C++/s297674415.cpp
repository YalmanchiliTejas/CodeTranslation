#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> lis;
	while(n--) {
		int x;
		std::cin >> x;
		x = -x;
		int id = std::upper_bound(lis.begin(), lis.end(), x) - lis.begin();
		if((int) lis.size() == id) lis.push_back(0);
		lis[id] = x;
	}
	std::cout << lis.size() << '\n';
}