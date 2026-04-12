#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>

int main(void) {
	int a;

	std::cin >> a;
	
	if (a == 5 || a == 7 || a == 3) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}
	return 0;
}