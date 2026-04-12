#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	int ans = 0;
	int rec = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (H[j] > H[i]) {
				rec++;
				break;
			}
		}
		if (rec == 0) {
			ans++;
		}
		rec = 0;
	}
	cout << ans << endl;
	return 0;
}