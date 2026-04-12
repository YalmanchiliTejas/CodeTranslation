#include"bits/stdc++.h"

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>H(N);

	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	int MAXHeight = -1;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (MAXHeight <= H[i]) {
			cnt++;
			MAXHeight = H[i];
		}
	}

	cout << cnt << endl;

	return 0;
}