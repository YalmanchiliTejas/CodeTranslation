#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m = 0, r = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		if (m <= h) r++;
		m = max(m, h);
	}
	cout << r << endl;
	return 0;
}
