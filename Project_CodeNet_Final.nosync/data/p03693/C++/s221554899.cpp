#include <iostream>

int main(int argc, char const *argv[]) {
	int r,g,b;
	std::cin >> r >> g >> b;
	r = 100 * r + 10 * g + b;
	r %= 4;
	if (r == 0) {
		std::cout << "YES" << '\n';
	}
	else{
		std::cout << "NO" << '\n';
	}
	return 0;
}
