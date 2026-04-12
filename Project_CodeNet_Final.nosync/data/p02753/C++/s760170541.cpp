#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

int main()
{
	std::string S;
	std::cin >> S;

	if ((S[0] == S[1]) && (S[0] == S[2])) {
		std::cout << "No" << std::endl;
		return 0;
	}

	std::cout << "Yes" << std::endl;

	return 0;
}