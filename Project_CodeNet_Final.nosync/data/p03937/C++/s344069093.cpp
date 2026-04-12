#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int h, w;
	cin >> h >> w;
	int r = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c;
			cin >> c;
			if (c == '#' && j < r) {
				cout << "Impossible" << endl;
				return 0;
			}
			if (c == '#') r = j;
		}
	}
	cout << "Possible" << endl;
	return 0;	
}
