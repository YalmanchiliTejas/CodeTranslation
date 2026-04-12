#include <iostream>
#include <string>
#include <algorithm>

int minCount[26];

int main() {
	int n;

	std::cin >> n;

	for (auto&& e : minCount)
		e = 114514;

	for (int i = 0; i < n; ++i) {
		std::string str;
		std::cin >> str;

		std::sort(str.begin(), str.end());

		int seek = 0;
		for (int i = 0; i < 26; ++i) {
			if (seek >= str.size())
				minCount[i] = 0;

			int old = seek;
			while (str[seek] == 'a' + i)
				++seek;

			minCount[i] = std::min(minCount[i], seek - old);
		}
	}

	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < minCount[i] && minCount[i] != 114514; ++j)
			std::cout << static_cast<char>('a' + i);

	std::cout << std::endl;
}