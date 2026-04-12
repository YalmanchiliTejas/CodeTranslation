#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

int main() {
	std::string s;
	std::cin >> s;
	int n = 0;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'A') {
			if (s[i + 1] == 'C') {
				std::cout << "Yes" << std::endl;
				n += 1;
				break;
			}
		}
	}
	if (n == 0) {
		std::cout << "No" << std::endl;
	}

	return 0;
}