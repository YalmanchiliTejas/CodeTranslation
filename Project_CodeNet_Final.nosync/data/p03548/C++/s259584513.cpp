#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long LL;
int main() {
	int x = 0, y = 0, z = 0;
	std::cin >> x >> y >> z;
	for (int i = 0; i < x; i++) {
		if (y*i + z*(i + 1) == x) {
			std::cout << i << std::endl;
			return 0;
		}else
		if (y*i + z*(i + 1) > x) {
			std::cout << i-1 << std::endl;
			return 0;
		}
	}
}