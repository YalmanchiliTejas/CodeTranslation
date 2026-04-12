#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <numeric>

int main() {
	int n;

	std::cin >> n;

	std::string s;

	std::cin >> s;

	int k;

	std::cin >> k;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[k - 1] != s[i]) {
			s[i] = '*';
		}
	}

	std::cout << s << std::endl;
	return 0;
}