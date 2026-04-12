#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <functional>

#define INPUT_FROM_FILE (0) 
#if INPUT_FROM_FILE
#include <fstream>
#endif


int main(){
	int n, q, k;
	std::vector<long> a;

#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
#endif

#if INPUT_FROM_FILE
	ifs >> n;
#else
	std::cin >> n;
#endif
	
	a.resize(n);
	for(int i = 0; i < n; i++){
#if INPUT_FROM_FILE
		ifs >> a[i];
#else
		std::cin >> a[i];
#endif
	}

#if INPUT_FROM_FILE
	ifs >> q;
#else
	std::cin >> q;
#endif

	for(int i = 0; i < q; i++){
#if INPUT_FROM_FILE
		ifs >> k;
#else
		std::cin >> k;
#endif
		std::vector<long>::iterator it = std::lower_bound(a.begin(), a.end(), k);
		std::cout << (it - a.begin()) << std::endl;
	}
	return 0;
}
