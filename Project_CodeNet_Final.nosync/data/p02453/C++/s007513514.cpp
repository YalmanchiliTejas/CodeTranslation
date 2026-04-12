#include <iostream>
#include <algorithm>

int main()
{
	int n; std::cin >> n;
	
	int* A = new int[n];
	for (int i=0; i<n; i++) std::cin >> A[i];
	
	int q; std::cin >> q;
	for (int i=0; i<q; i++) {
		int k;
		std::cin >> k;
		int* lb = std::lower_bound(A, A+n, k);
		std::cout << lb - A << std::endl;
	}
	
	delete[] A;
	
	return 0;
}

