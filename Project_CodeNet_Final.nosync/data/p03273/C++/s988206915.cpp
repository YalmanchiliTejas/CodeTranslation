#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int H,W;
	cin >> H >> W;
	vector<bool> row(H,true);
	vector<bool> col(W,true);
	vector< vector<char> > grid(H,vector<char>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == '#') {
				row[i] = false;
				col[j] = false;
			}
		}
	}

	for (int i = 0; i < H; ++i) {
		bool op = false;
		for (int j = 0; j < W; ++j) {
			if (!row[i] && !col[j]) {
				cout << grid[i][j];
				op = true;
			}
		}
		if (op) {
			cout << endl;
		}
	}

	return 0;
}

