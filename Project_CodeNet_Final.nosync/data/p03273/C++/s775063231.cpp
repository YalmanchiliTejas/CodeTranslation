#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	vector<string> board(H);
	for (int i = 0; i < H; ++i) {
		cin >> board[i];
	}
	vector<int> vl, hl;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == '#') {
				vl.push_back(i);
				break;
			}
		}
	}
	for (int i = 0; i < W; ++i) {
		for (int j = 0; j < H; ++j) {
			if (board[j][i] == '#') {
				hl.push_back(i);
				break;
			}
		}
	}
	for (int i : vl) {
		for (int j : hl) {
			cout << board[i][j];
		}
		cout << endl;
	}
	return 0;
}