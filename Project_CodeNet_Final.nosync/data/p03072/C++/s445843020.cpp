#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	int H[100];
	int max = 0;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
		if (H[i] >= max) {
			ans++;
			max = H[i];
		}
	}
	cout << ans;
	return 0;
}