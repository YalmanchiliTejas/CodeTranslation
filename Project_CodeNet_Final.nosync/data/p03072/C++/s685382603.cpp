#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int cnt = 1, max = h[0];
	for (int i = 1; i < n; i++) {
		if (max <= h[i]) {
			cnt++;
		}
		if (h[i] > max) {
			max = h[i];
		}
	}
	cout << cnt << '\n';
	
	return 0;
}
