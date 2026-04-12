// 2016-11-25
#include <iostream>
#include <string>
#define L false
#define R true

bool b[26] = {L, L, L, L, L, L, L, R, R, R, R, R, R, R, R, R, L, L, L, L, R, L, L, L, R, L};

int main() {
	std::string s;
	int n;
	bool c;
	for (std::cin >> s; s[0] != '#'; std::cin >> s) {
		n = 0;
		c = b[s[0] - 'a'];
		for (int i = 1; i < s.length(); i++) {
			if (b[s[i] - 'a'] != c) {
				n++;
				c = b[s[i] - 'a'];
			}
		}
		std::cout << n << std::endl;
	}
	return 0;
}