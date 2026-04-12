#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

int main(){
	
	int A, B, C;
	std::cin >> A >> B >> C;


	bool b =
		(A * 100 + B * 10 + C) % 4 == 0;

	if (b) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}

	return 0;
}

