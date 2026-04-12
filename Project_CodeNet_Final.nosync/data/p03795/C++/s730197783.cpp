#include<iostream>

int main() {
	int n = 0,ans = 0,voun = 0;
	std::cin >> n;
	ans = n * 800;
	voun = n / 15;
	ans = ans - voun * 200;
	std::cout << ans << std::endl;

}