#include <iostream>

int main()
{	
	int n; std::cin >> n;
	
	for (long long int i=0; i<(1<<n); i++) {
		std::cout << i << ":";
		long long int d = i;
		for (int j=0; j<n; j++) {
			if ( (d&1) == 1 ) std::cout << " " << j;
			d >>= 1;
		}
		std::cout << std::endl;
	}
	
	return 0;
}

