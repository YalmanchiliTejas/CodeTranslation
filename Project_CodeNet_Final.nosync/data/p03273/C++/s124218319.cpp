#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> grid(H);
	rep(i, H) {
		cin >> grid[i];
	}
	vector<bool> row(H, false);
	vector<bool> column(W, false);
	rep(i, H) {
		rep(j, W) {
			if (grid[i][j] == '#') {
				row[i] = true;
				column[j] = true;
			}
		}
	}
	rep(i, H) {
		bool flag = false;
		rep(j, W) {
			if (row[i] && column[j]) {
				cout << grid[i][j];
				flag = true;
			}
		}
		if (flag) {
			cout << endl;
		}
	}
	return 0;
}