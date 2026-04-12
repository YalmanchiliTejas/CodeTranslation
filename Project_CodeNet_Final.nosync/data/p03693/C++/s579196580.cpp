#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	int z = 100 * a + 10 * b + c;
	if (z % 4 == 0)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
}
