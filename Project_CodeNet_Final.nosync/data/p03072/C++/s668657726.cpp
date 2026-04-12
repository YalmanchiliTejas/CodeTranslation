#include <iostream>

using namespace std;

int main(void) {

	int n;

	cin >> n;

	int *h = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int count = 1;

	for (int i = 1; i < n; i++) {
		int max_h = 0;
		for (int j = 0; j < i; j++) {
			max_h = max_h <= h[j] ? h[j] : max_h;
		}
		if (max_h <= h[i]) {
			count++;
		}
	}

	cout << count << endl;

	free(h);

	return 0;
}