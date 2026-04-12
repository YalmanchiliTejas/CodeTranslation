#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int h, w, row[100] = { 0 }, col[100] = { 0 };
	char a[100][100] = { 0 };
	cin >> h >> w;
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}
	rep(i, h) {
		int j;
		for (j = 0; j < w; j++) {
			if (a[i][j] != '.') break;
		}
		if (j == w) row[i]++;
	}
	rep(i, w) {
		int j;
		for (j = 0; j < h; j++) {
			if (a[j][i] != '.') break;
		}
		if (j == h) col[i]++;
	}
	rep(i, h) {
		rep(j, w) {
			if (row[i] == 0 && col[j] == 0) cout << a[i][j];
		}
		if (row[i] == 0) {
			cout << endl;
		}
	}
	return 0;
}