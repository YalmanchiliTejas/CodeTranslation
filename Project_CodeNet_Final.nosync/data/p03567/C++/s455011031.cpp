#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <numeric>


int main()
{
	std::string s;

	std::cin >> s;

	for (size_t i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == 'A' && s[i + 1] == 'C') {
			std::cout << "Yes" << std::endl;
			return 0;
		}
	}

	std::cout << "No" << std::endl;

	return 0;

}
