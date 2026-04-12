#include <iostream>
#include <cstdlib>

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main(void) {
	int n;
	int score[1024];

	while (true) {
		std::cin >> n;
		if (!n) break;

		for (int i = 0; i < n; i++) std::cin >> score[i];

		qsort(score, n, sizeof(int), compare);
		double sum = 0;
		for (int i = 1; i < n - 1; i++) sum += score[i];
		int ave = int(sum / (n-2));
		std::cout << ave << '\n';
	}
	return 0;
}