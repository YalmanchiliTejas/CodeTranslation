#include <iostream>
#include <string>


int main(void){

	std::string inputs;
	std::cin >> inputs;

	bool flag = false;
	for(auto itr = inputs.begin(); itr != (inputs.end() - 1); itr++){

		if((*itr) == 'A' && *(itr + 1) == 'C'){
			flag = true;
		}
	}

	std::cout << ((flag) ? "Yes" : "No") << std::endl;

	return 0;
}