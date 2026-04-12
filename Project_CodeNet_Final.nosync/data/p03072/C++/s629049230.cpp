#include<iostream>

int main() {
	int N = 0;
	int H[20];
	int count = 1;
	int j = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> H[i];
	}

	for (int i = 0; i < N; i++) {
		if (H[0] <= H[i]) {
			for (j = i - 1; j > 0; j--) {
				if (H[j] <= H[i]) {
					continue;
				}
				else {
					break;
				}
			}
			if (j == 0) {
				count++;
			}
		}
	}

	std::cout << count << std::endl;

}