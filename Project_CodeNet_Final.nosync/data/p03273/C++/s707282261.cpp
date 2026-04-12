#include <bits/stdc++.h>
using namespace std;

int main() {
	int H;
	cin >> H;
	int W;
	cin >> W;
	vector<vector<char>> a(H, vector<char>(W));
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			cin >> a.at(h).at(w);
		}
	}

	bool bAllWhite = false;
	for (int h = 0; h < H; h++) {
		bAllWhite = true;
		for (int w = 0; w < W; w++) {
			if (a.at(h).at(w) == '#') {
				bAllWhite = false;
				break;
			}
		}
		if (bAllWhite) {
			for (int w = 0; w < W; w++) {
				a.at(h).at(w) = ' ';
			}
		}
	}
	for (int w = 0; w < W; w++) {
		bAllWhite = true;
		for (int h = 0; h < H; h++) {
			if (a.at(h).at(w) == '#') {
				bAllWhite = false;
				break;
			}
		}
		if (bAllWhite) {
			for (int h = 0; h < H; h++) {
				a.at(h).at(w) = ' ';
			}
		}
	}
	for (int h = 0; h < H; h++) {
		bAllWhite = true;
		for (int w = 0; w < W; w++) {
			if (a.at(h).at(w) != ' ') {
				cout << a.at(h).at(w);
				bAllWhite = false;
			}
		}
		if (! bAllWhite) {
			cout << endl;
		}
	}
}
