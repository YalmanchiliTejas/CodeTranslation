#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int maxh = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (maxh <= h[i]) {
			ans++;
			maxh = h[i];
		}
	}
	cout << ans << endl;

	return 0;
}