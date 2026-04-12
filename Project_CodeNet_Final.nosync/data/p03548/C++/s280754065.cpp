#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y, z;
	cin >> x >> y >> z;
	
	int max = 0;
	for (int i = 0; ; i++) {
		int t = i * y + (i + 1) * z;
		if (t <= x) {
			max = i;
		} else {
			break;
		}
	}
	cout << max << endl;
}