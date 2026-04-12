#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> A(H, vector<char>(W));
	set<int> Cols, Rows;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
			if (A[i][j] == '#') {
				Cols.insert(i);
				Rows.insert(j);
			}
		}
	}
	for (int c : Cols) {
		for (int r : Rows) cout << A[c][r];
		cout << endl;
	}
}