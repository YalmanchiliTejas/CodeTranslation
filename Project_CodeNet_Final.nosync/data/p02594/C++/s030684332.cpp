#include<iostream>


int main() {
	int X = {};
	std::cin >> X;
	//異常値の検知
	if (X < -40	|| X > 40) {
		std::cout << "温度が異常値です" << std::endl;
		return 0;

	}

	//エアコンOn判定
	if (X >= 30) {
		std::cout << "Yes" << std::endl;
		return 0;
	}
	std::cout << "No" << std:: endl;

}