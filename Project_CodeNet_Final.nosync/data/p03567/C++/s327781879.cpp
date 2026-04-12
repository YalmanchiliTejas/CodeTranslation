#include <iostream>
#include <string.h>
int main(void) {
	char S[6] = {};

	std::cin >> S;

	if (strstr(S, "AC")) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	return 0;
}