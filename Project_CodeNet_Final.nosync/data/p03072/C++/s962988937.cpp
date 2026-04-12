#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, h[20];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int ans = 0;
	int maxH = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] >= maxH) {
			maxH = h[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}