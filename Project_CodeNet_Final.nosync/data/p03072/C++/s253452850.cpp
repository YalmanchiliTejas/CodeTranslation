#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, ans = 0, max = 0;;
	int H[150];
	H[0] = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> H[i];
	}

	for (int i = 1; i <= N; i++) {
		/*if (H[i - 1] <= H[i]) {
			ans++;
			cout << H[i - 1] << H[i] << endl;
		}*/
		max = 0;
		for (int j = 0; j <= i; j++) {
			if (max <= H[j]) {
				max = H[j];
			}
		}
		if (max <= H[i]) {
			ans++;
		}
	}

	cout << ans << endl;
}
