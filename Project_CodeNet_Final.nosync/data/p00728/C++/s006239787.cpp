#include <iostream>
using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}

		int sum = 0;
		int max = 0;
		int min = 1000;
		for (int i = 0; i < n; i++) {
			int s;
			cin >> s;

			sum += s;
			if (s > max) {
				max = s;
			}
			if (s < min) {
				min = s;
			}
		}

		cout << (sum - max - min) / (n - 2) << endl;
	}

	return 0;
}