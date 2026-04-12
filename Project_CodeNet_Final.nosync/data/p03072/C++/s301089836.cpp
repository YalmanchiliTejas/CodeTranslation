#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> h(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int h_max = -1;
	int ans = 0;
	for (auto x: h) {
		if (x >= h_max) {
			ans++;
			h_max = x;
		}
	}

	cout << ans << endl;
	return 0;
}
