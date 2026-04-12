#include <iostream>			
#include <vector>			
			
int main(){			
	int n;		
    std::cin >>n;

	int max;
    std::cin >> max;

    int val;
	int count = 1;			
	for(int i = 1; i < n; ++i){		
		std::cin >> val;	

		if(max <= val){	
			++count;
			max = val;
		}	
	}		

	std::cout << count << std::endl;		
			
	return 0;		
}			
