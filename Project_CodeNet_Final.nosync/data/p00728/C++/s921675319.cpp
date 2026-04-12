#include <iostream>
#include <cstdlib>
using namespace std;

int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		int points[n];
		for (int i = 0; i < n; i++) {
			cin >> points[i];
		}
		qsort(points, n, sizeof(int), comp);
		int sum = 0;
		for (int i = 1; i < n - 1; i++) {
			sum += points[i];
		}
		cout << sum / (n - 2) << endl;
	}
	return 0;
}