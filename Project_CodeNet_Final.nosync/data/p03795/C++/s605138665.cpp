#include<iostream>

int main(){
	int n;
	
	std::cin >> n;

	int y = n * 800;
	int x = 200 * (n / 15);

	
	std::cout << y - x << "\n";

	return 0;
}