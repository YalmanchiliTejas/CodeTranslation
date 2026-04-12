#include <iostream>
using namespace std;

int main() {
	int n, h[25], ans = 1, maxh;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	maxh = h[0];
	for (int i = 1; i < n; i++) {
		if (h[i] >= maxh) {
			ans++;
			maxh = h[i];
		}
	}
	cout << ans << endl;
	return 0;
}