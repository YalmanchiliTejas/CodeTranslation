#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<bool> yck(H, false);
	vector<bool> xck(W, false);
	vector<vector<char>> a(H, vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a.at(i).at(j);
			if (a.at(i).at(j) == '#') {
				yck.at(i) = true;
				xck.at(j) = true;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		if (yck.at(i) == false) {
			continue;
		}
		for (int j = 0; j < W; j++) {
			if (xck.at(j) == false) {
				continue;
			}
			cout << a.at(i).at(j);
		}
		cout << endl;
	}
}