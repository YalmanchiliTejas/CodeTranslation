#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stdio.h>

using namespace std;

int main() {
	string S;
	std::cin >> S;

	int l = S.length();
	char c = S[0];
	for (int i = 1; i < l; i++) {
		if (c != S[i]) {
			std::cout << "Yes" << endl;
			return 0;
		}
	}

	std::cout << "No" << endl;

	return 0;
}