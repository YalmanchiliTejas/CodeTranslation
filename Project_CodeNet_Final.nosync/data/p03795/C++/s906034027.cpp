#include<iostream>

int main() {
	int n,x,y;
	std::cin >> n;

	x = n * 800;
	y = n / 15 * 200;

	std::cout << x - y << std::endl;

	return 0;
}