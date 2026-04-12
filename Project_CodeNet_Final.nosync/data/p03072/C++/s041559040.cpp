#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>H(N);
	for (int i = 0; i < N; i++)cin >> H[i];

	int ans = 0;

	for (int i = 0; i < N; i++) {

		bool is_candidate = true;

		for (int j = 0; j < i; j++) {
			if (H[j] > H[i]) {
				is_candidate = false;
				break;
			}
		}

		if (is_candidate) {
			ans++;
		}
	}

	cout << ans << endl;

}