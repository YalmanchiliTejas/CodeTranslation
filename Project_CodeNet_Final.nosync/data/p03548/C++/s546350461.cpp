#include<iostream>


int main() {


	int x,y,z;

	int man = 0;

	std::cin >> x >> y >> z;

	x -= z;
	
	
	
	while (x >= (y + z)) {
		x -= (y + z);
		man++;
	}
	
	std::cout << man;




	return 0;

}