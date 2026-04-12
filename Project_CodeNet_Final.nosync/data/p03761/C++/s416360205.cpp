#include <iostream>
#include <string>
#include <vector>

int main(void) {
	// input
	int n;
	std::cin >> n;
	std::vector<std::string> s(n);
	for(int i = 0; i < n; ++i) std::cin >> s[i];

	std::vector<std::vector<int>> n_char(n);
	for(int i = 0; i < n; ++i) {
		n_char[i].resize(26);
		int len_s = s[i].size();
		for(int j = 0; j < len_s; ++j) n_char[i][s[i][j] - 'a'] += 1;
	}

	for(int k = 0; k < 26; ++k) {
		int n_char_min = 9999;
		for(int i = 0; i < n; ++i) n_char_min = (n_char[i][k] < n_char_min ? n_char[i][k] : n_char_min);
		for(int j = 0; j < n_char_min; ++j) std::cout << (char)('a' + k);
	}

	std::cout << std::endl;

	return 0;
}
