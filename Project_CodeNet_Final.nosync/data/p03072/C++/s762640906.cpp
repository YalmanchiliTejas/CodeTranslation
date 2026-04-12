#include <iostream>

using namespace std;

int main() {
	int N,h;
	cin >> N;
	int ans = 1;
	int m;
	cin >> m;
	for (int i = 1; i < N; i++) {
		cin >> h;
		if (h >= m) {
			m = h;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}