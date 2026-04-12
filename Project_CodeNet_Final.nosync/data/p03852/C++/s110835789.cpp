#include<iostream>
#include<vector>

int main() {
	bool flag=false;
	char word;
	std::vector<char> vowel{'a','i','u','e','o'};

	std::cin >> word;

	for (int i = 0; i < 5; i++) {
		if (word == vowel[i]) {
			flag = true;
		}
	}

	if (false == flag) {
		std::cout << "consonant" << std::endl;
	}
	else {
		std::cout << "vowel" << std::endl;
	}

	return 0;
}