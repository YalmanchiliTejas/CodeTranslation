#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int h[100];

	for (int i = 0; i < n;i++) {
		cin >> h[i];
	}

	int num = 1;
	for (int i = 1; i < n;i++) {

		int flag = 0;
		for (int j = 0; j < i;j++) {
			if (h[j] > h[i]) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			num++;
		}
	}

	cout << num;
	return 0;
}