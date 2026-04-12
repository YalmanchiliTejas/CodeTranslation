#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> matrix(H, vector<char>(W));
	rep(i, H) rep(j, W) cin >> matrix[i][j];

	vector<bool> row(H, false);
	vector<bool> col(W, false);

	rep(i, H) rep(j, W) {
		if (matrix[i][j]=='#') {
			row[i] = true;
			col[j] = true;
		}
	}
	
	rep(i, H) {
		if (row[i]) {
			rep(j, W) {
				if (col[j]) cout << matrix[i][j];
			}
			cout << endl;
		}
	}
}