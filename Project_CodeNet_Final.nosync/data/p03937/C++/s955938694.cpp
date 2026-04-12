#include<bits/stdc++.h>
#include <array>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using LL = long long;
using ULL = unsigned long long;


void solve() {
	int h, w; cin >> h >> w;
	bool a[8][8] = {};
	rep(i, h)rep(j, w) {
		char ch; cin >> ch;
		if (ch == '#') a[j][i] = true;
	}
	int x = 0, y = 0;
	a[0][0] = false;
	while (x < w - 1 || y < h - 1) {
		if (x < w - 1) {
			if (a[x + 1][y]) {
				x++; a[x][y] = false; continue;
			}
		}
		if (y < h - 1) {
			if (a[x][y + 1]) {
				y++; a[x][y] = false; continue;
			}
		}
		cout << "Impossible" << endl; return;
	}
	rep(i, h)rep(j, w) {
		if (a[j][i]) { cout << "Impossible" << endl; return; }
	}
	cout << "Possible" << endl;
}

int main() {

	solve();

	return 0;
}
