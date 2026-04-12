#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		vector<int> data(n);
		int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (i % 2 == 0) {
				data[i] = a;
			} else {
				if (data[i-1] == a) {
					data[i] = a;
				} else {
					for (int j = i-1; j >= 0; j--) {
						if (data[j] != a) {
							data[j] = a;
						} else {
							break;
						}
					}
					data[i] = a;
				}
			}
		}
		int counter = 0;
		for (int i = 0; i < n; i++) {
			if (data[i] == 0) {
				counter++;
			}
		}
		cout << counter << endl;
	}
	return 0;
}