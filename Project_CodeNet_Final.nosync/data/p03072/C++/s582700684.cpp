#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
typedef long long LL;

int int_vector_find(std::vector<int> vec, int num) {
	auto itr = std::find(vec.begin(), vec.end(), num);
	int index = std::distance(vec.begin(), itr);

	if (index != vec.size()) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	std::vector<int> vec;
	int n;
	std::cin >> n;
	int ans = 1;

	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		vec.push_back(a);
	}

	for (int i = 1; i < n; ++i) {
		bool hoge = true;
		for (int j = 0; j < i; ++j) {
			if (vec[j] > vec[i]) {
				hoge = false;
			}
		}
		if (hoge) {
			ans++;
		}
	}

	std::cout << ans << std::endl;
}