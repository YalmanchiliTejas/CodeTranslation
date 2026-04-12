#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, ans=1;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}

	for (int i = 1; i < N; i++) {
		bool can = true;
		for (int j = 0; j < i; j++) {
			if (H[i] < H[j]) {
				can = false;
			}
		}
		if (can) {
			ans++;
		}
	}

	cout << ans << endl;


	return 0;
}