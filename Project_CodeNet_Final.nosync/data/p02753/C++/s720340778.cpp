#include<iostream>

int main() {
	char s[4], tmp[2];
	bool flag = false;
	std::cin >> s;
	tmp[0] = s[0];
	for (int i = 1; i < 3; i++) {
		if (tmp[0] != s[i]) {
			tmp[0] = s[i];
			flag = true;
		}
	}

	if (flag)std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;

	return 0;
}