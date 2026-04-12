# include <iostream>
# include <vector>
# include <string>
using namespace std;
int main() {
	int n, a;
	while (cin >> n&&n != 0) {
		int sum = 0, min = 10000, max = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a < min) {
				min = a;
			}
			if (max < a) {
				max = a;
			}
			sum += a;
		}
		sum = sum - max - min;
		cout << sum / (n - 2) << endl;
	}
}