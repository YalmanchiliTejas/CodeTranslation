#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <valarray>

int main(void) {

	bool on = true;
	int year;
	std::cin >> year;
	switch (year){
	case 3:
		break;
	case 5:
		break;
	case 7:
		break;
	default:
		on = false;
		break;
	}


	std::cout << ((on)? "YES\n":"NO\n");
	
	return 0;
}