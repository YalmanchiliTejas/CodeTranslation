#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

int main() {
	int n;
	std::cin >> n;

	std::deque<int> d;
	for (int i = 0; i < n; i++) {
		int t;
		std::cin >> t;

		if (i % 2 == 0) {
			d.push_back(t);
		} else {
			d.push_front(t);
		}
	}
	
	if (n % 2 == 0) {
		for (int i = 0; i < n; i++) {
			std::cout << d[i] << ' ';
		}
	} else {
		for (int i = n - 1; i >= 0; i--) {
			std::cout << d[i] << ' ';
		}
	}
}

