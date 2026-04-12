#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long go(std::vector<long long> a) {
	int n = (int) a.size();
	long long ans = 0;
	while(1) {
		long long got = 0;
		for(auto &x : a) {
			got += x / n;
			x = (x % n) - x / n;
		}
		ans += got;
		if(got == 0) break;
		for(auto &x : a) {
			x += got;
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::cout << go(a) << '\n';
}