#include <iostream>
#include <string>
#include <set>

const char leftKey_[] = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b'};
const std::set<char> leftKey(leftKey_, leftKey_ + sizeof(leftKey_) / sizeof(leftKey_[0]));

bool isLeft(const char c)
{
	return leftKey.find(c) != leftKey.end();
}

int main()
{
	std::string str;
	while (std::cin >> str, str != "#") {
		int n = 0;
		bool left = isLeft(*str.begin());
		for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
			if (isLeft(*it) != left) {
				left = !left;
				++n;
			}
		}
		std::cout << n << std::endl;
	}
	return 0;
}