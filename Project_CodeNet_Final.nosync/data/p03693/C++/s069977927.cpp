#include <iostream>

int main()
{
	int a, b, c;

	std::cin >> a >> b >> c;

	int total = a * 100 + b * 10 + c;

	bool ans;
	if (total % 4 == 0) {
		ans = true;
	} else {
		ans = false;
	}

	std::cout << (ans ? "YES" : "NO") << std::endl;
	return 0;
}