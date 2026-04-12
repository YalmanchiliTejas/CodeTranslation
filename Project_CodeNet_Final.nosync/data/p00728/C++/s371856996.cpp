#include <iostream>

using namespace std;

int main(void) {
	int n[20], s[20][100], sum[20], shift;
	int j = 0;
	while (1) {
		sum[j] = 0;
		cin >> n[j];
		if (n[j] == 0)
			break;

		for (int i = 0; i < n[j]; i++) {
			cin >> s[j][i];
		}

		// 昇順ソート
		for (int i = 0; i < n[j]; i++) {
			for (int t = i + 1; t < n[j]; t++) {
				if (s[j][i] > s[j][t]) {
					shift = s[j][i];
					s[j][i] = s[j][t];
					s[j][t] = shift;
				}
			}
		}
		for (int i = 1; i < n[j] - 1; i++) {
			sum[j] += s[j][i];
		}
		sum[j] = sum[j] / (n[j] - 2);
		cout <<  sum[j] << endl;
		j++;

	}
	return 0;
}

