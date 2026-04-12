#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <map>
#include <cstdio>

int main() {
	std::string s;

	std::cin >> s;

	if (s[0] == s[1] && s[1] == s[2]) {
		std::cout << "No" << std::endl;
	}
	else {
		std::cout << "Yes" << std::endl;
	}

	return 0;
}
