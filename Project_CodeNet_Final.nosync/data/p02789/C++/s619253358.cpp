#include <iostream>

int main() {
	int N;
	std::cin >> N;

	int M;
	std::cin >> M;

	char a[] = "Yes";
	char b[] = "No";

	if (N == M) {
		std::cout << a << std::endl;
	}
	else {
		std::cout << b << std::endl;
	}
	return 0;
}