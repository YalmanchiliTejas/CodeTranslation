#include <iostream>

int main() {
	int h, w;
	std::cin >> h >> w;

	int count = 0;
	for (int i = 0; i < h * w; ++i) {
		char c;
		std::cin >> c;

		if (c == '#')
			++count;
	}

	if (count == h + w - 1)
		std::cout << "Possible" << std::endl;
	else
		std::cout << "Impossible" << std::endl;
}