#include <iostream>
#include <string>

int main() {
	int n, k;
	std::string s;

	std::cin >> n;
	std::cin >> s;
	std::cin >> k;

	char ch = s[k - 1];
	std::string str_out;
	for(int i = 0; i < n; ++i) {
		if(ch == s[i]) str_out.push_back(s[i]);
		else str_out.push_back('*');
	}

	std::cout << str_out << std::endl;

	return 0;
}
