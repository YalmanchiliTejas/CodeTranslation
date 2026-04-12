#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> A(H);
	for (int n = 0; n < H; ++n) {
		cin >> A[n];
	}
	set<int>X;
	set<int>Y;
	for (int i = 0;i<W;++i) {
		bool b = true;
		for (int j =0 ;j<H;++j) {
			if ('#' == A[j][i]) {
				b = false;
			}
		}
		if (b) {
			X.insert(i);
		}
	}
	for (int i = 0; i < H; ++i) {
		bool b = true;
		for (int j = 0; j < W; ++j) {
			if ('#' == A[i][j]) {
				b = false;
			}
		}
		if (b) {
			Y.insert(i);
		}
	}

	for (int i = 0; i < H; ++i) {
		if (Y.count(i)) {
			continue;
		}
		for (int j = 0; j < W; ++j) {
			if (!X.count(j)) {
				cout << A[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}