#include<iostream>
#include<cstdio>

int main(void){
	std::int64_t r,g,b;
	std::cin >> r;
	std::cin >> g;
	std::cin >> b;

	if((100 * r + 10 * g + b) % 4 ==0){
		std::cout << "YES" << std::endl;
		return 0;
	}
	else{
		std::cout << "NO" << std::endl;
		return 0;
	}

}
