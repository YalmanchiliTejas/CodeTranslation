#include<iostream>

int main(void){
	int r = 0;
	int g = 0;
	int b = 0;

	std::cin >> r >> g >> b;

	if( ((r * 100) + (g * 10) + b) % 4 == 0){
		std::cout << "YES";
	}
	else
		std::cout << "NO";

	return 0;
}