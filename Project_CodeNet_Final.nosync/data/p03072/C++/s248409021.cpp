#include <iostream>

int main()
{
	int N = 0;
	std::cin >> N;
	int H[25];
	for (int i = 0; i < N; i++) { std::cin >> H[i]; }
	int max = H[0];
	int counter = 1;
	for (int i = 1; i < N; i++) {
		if (H[i] >= max) {
			max = H[i];
			counter++;
		}
	}

	std::cout<<counter;
   return 0;
}