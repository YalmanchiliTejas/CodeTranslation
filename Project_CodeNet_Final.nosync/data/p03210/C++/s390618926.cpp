#include<stdio.h>
#include<iostream>
#include<fstream>

int main() {
	int x = 0;

	std:: cin >> x;

	if (x < 1 || x > 9) {
		std::cout << "error" << std::endl;
	}
	else if (x == 3 || x == 5 || x == 7) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}

}