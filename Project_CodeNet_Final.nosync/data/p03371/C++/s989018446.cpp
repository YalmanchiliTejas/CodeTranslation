#include <iostream>

int main() {
	int A, B, C, X, Y;
	std::cin >> A >> B >> C >> X >> Y;

	int price = 0;
	int ABNum = 0;

	if(C * 2 < A) {
		A = C * 2;
	}
	if(C * 2 < B) {
		B = C * 2;
	}

	price = A * X + B * Y;

	while(ABNum < X && ABNum < Y && C * 2 < (A + B)) {
		price -= (A + B);
		price += C * 2;
		ABNum++;
	}

	std::cout << price << std::endl;

	return 0;
}