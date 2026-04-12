#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define INPUT_FROM_FILE (0) 
#if INPUT_FROM_FILE
#include <fstream>
#endif

int main(){
	int n;
	std::bitset<18> flag;
	int num_all_subsets = 0;

#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
	//FILE *fp = fopen("test.txt", "r");
#endif

#if INPUT_FROM_FILE
	ifs >> n;
#else
	std::cin >> n;
#endif

	num_all_subsets = pow(2, n);

	std::cout << "0:" << std::endl;

	for(int i = 1; i < num_all_subsets; i++){
		flag = std::bitset<18>(i);
		int num_subsets = flag.count();

		std::cout << i << ":";
		for(int j = 0; j < 18; j++){
			std::bitset<18> mask;

			mask.set(j);

			if(flag.test(j) && mask.test(j)){
				std::cout << " " << j;
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
