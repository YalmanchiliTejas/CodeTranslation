#include <iostream>

using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int max = -1, min = 1001;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int m;
			cin >> m;
			sum += m;
			if (max < m) {
				max = m;
			}
			if (m < min) {
				min = m;
			}
		}
		sum -= (max + min);
		sum /= n - 2;
		cout << sum << endl;
	}
	return 0;
}