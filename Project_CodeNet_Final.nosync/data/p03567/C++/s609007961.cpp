#include<iostream>
#include<string>
std::string S;
int main() {
	std::cin >> S;
	int size = S.size();
	for (int i = 0; i < size - 1; i++) {
		if (S[i] == 'A') {
			if (S[i + 1] == 'C') {
				std::cout << "Yes" << std::endl;
				return 0;
			}
		}
	}
	std::cout << "No" << std::endl;
	return 0;
}