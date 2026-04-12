#include <iostream>
using namespace std;

int main() {
	int N;
	int H[20];
	int ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> H[i];

		for (int j = 0; j <= i; j++) {
			if (j == i) ans++;

			else if (H[i] < H[j]) break;
		}
	}

	cout << ans;
	
	return 0;
}