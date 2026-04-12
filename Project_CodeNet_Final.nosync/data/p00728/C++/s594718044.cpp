#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int judge[100];
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> judge[i];
		}
		for (int i = n; i > 1; i--) {
			for (int j = 0; j < i-1; j++) {
				if (judge[j] > judge[j+1]) {
					swap(judge[j], judge[j+1]);
				}
			}
		}
		for (int i = 1; i < n-1; i++) {
			sum += judge[i];
		}
		cout << sum/(n-2) << endl;
	}
	return 0;
}