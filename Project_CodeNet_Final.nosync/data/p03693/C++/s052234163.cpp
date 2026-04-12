#include <iostream>

int main(){
	int r, g, b;

	std::cin >> r >> g >> b;

	int a = 100*r + 10*g + b;

	if(a % 4 == 0){
		std::cout << "YES" << std::endl;
	}
	else{
		std::cout << "NO" << std::endl;
	}

	return 0;
}
