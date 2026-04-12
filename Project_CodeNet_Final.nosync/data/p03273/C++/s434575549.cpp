#include <bits/stdc++.h>

using namespace std;

void solve() {
	int H, W;
	cin >> H >> W;
	char a[100][100] = { { } };
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> a[i][j];
		}
	}

	/* calculate */
	bool isNotBlankRow[100] = { };
	bool isNotBlankCol[100] = { };
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (a[i][j] == '#') {
				isNotBlankRow[i] = true;
				isNotBlankCol[j] = true;
			}
		}
	}

	/* print */
	for (int i = 0; i < H; ++i) {
		if (isNotBlankRow[i]) {
			for (int j = 0; j < W; ++j) {
				if (isNotBlankCol[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}

int main() {
solve();
return 0;
}
