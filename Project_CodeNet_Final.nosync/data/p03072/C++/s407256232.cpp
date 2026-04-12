#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	const int MAX_N = 20;
	int n;
	int h[MAX_N];
	int ans = 0;
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		if (h[i] >= max) {
			max = h[i];
			ans++;
		}
	}

	cout << ans;
}