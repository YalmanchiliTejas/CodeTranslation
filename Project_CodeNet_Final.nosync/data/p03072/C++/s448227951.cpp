#include <iostream>

using namespace std;

int main(void) {

	int N;

	int H[25];

	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> H[i]; }

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		int sign = 1;
		for (int j = 1; j <= i - 1; j++) {
			if (H[j] > H[i]) { sign = 0; }
		}
		if (sign == 1) { ans++; }
	}

	cout << ans << endl;

	//system("pause");
	return 0;
}