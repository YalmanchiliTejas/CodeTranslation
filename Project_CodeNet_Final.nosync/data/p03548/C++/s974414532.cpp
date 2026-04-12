#include <iostream>


int main(void){

	int space, y, z;
	std::cin >> space >> y >> z;

	int cnt = 0;
	space -= (2 * z);
	while(space >= y){
		cnt++;
		space -= y + z;
	}

	std::cout << cnt << std::endl;

	return 0;
}