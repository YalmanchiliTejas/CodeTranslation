#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	char temp;
	vector<string> a;

	for (int i = 0; i < H; i++) {
		string temp;
		cin >> temp;
		a.push_back(temp);
	}

	vector<vector<bool> > b(H, vector<bool>(W, true));
	

	for (int i = 0; i < H; i++) {
		bool all = true;
		for (int j = 0; j < W; j++) {
			if (a[i][j] == '#') {
				all = false;
			}
		}
		if (all) {
			for (int j = 0; j < W; j++) {
				b[i][j] = false;
			}
		}
	}

	for (int i = 0; i < W; i++) {
		bool all = true;
		for (int j = 0; j < H; j++) {
			if (a[j][i] == '#') {
				all = false;
			}
		}
		if (all) {
			for (int j = 0; j < H; j++) {
				b[j][i] = false;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		bool line = false;
		for (int j = 0; j < W; j++) {
			if (b[i][j]) {
				cout << a[i][j];
				line = true;
			}
		}
		if (line) {
			cout << "\n";
		}
	}


	return 0;
}