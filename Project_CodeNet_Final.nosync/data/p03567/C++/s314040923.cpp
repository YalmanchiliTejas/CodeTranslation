#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	string str;
	std::cin >> str;
	for (size_t i = 0; i < str.size()-1; i++) {
		if (str[i] == 'A' && str[i+1] == 'C') {
			std::cout << "Yes" << '\n';
			return 0;
		}
	}
	std::cout << "No" << '\n';
	return 0;
}
