#include <iostream>
using namespace std;

int main() {
	int r, g, b;
	std::cin>> r >> g >> b;
	int a = g*10+b;
	if(a % 4) {
		std::cout << "NO" << std::endl;
	}else{
		std::cout << "YES" << std::endl;
	}

	return 0;
}
