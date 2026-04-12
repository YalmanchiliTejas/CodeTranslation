#include<iostream>
using namespace std;

int main(void) {
	int n, h[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int ret = 1;

	for (int i = 1; i < n; i++) {
		int h_i = h[i];
		bool false_flag = false;
		for (int j = 0; j < i + 1; j++) {
			if (h_i < h[j]) {
				false_flag = true;
				break;
			}
		}
		if (!false_flag) {
			ret++;
		}
	}
	cout << ret << endl;
	return 0;
}