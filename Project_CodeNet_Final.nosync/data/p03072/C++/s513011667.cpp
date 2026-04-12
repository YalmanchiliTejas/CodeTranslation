#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}

	int ans = 1;

	int tmp = H[0];
	for (int i = 1; i < N; ++i) {
		if (tmp < H[i - 1]) {
			tmp = H[i - 1];
		}

		if (tmp <= H[i]) {
			ans++;
		}
	}

	cout << ans << endl;
}
