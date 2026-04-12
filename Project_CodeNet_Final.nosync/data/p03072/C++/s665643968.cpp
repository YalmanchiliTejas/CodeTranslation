#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int h[30];

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int count = 0;
	int max = h[0];

	for (int i = 1; i < n; i++) {
		if (h[i] >= max) {
			count++;
			max = h[i];
		}
	}

	cout << 1 + count << endl;

	return 0;

}