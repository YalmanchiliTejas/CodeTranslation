#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; i++) cin >> a[i];
	vector<int> row, column;
	for (int i = 0; i < H; i++) {
		bool white = true;
		for (int j = 0; j < W; j++) {
			if (a[i][j] == '#') white = false;
		}
		if (white) row.push_back(i);
	}
	for (int j = 0; j < W; j++) {
		bool white = true;
		for (int i = 0; i < H; i++) {
			if (a[i][j] == '#') white = false;
		}
		if (white) column.push_back(j);
	}
	
	vector<string> ans;
	for (int i = 0; i < H; i++) {
		string s;
		for (int j = 0; j < W; j++) {
			bool remove = false;
			for (int h : row) {
				if (i == h) remove = true;
			}
			for (int w : column) {
				if (j == w) remove = true;
			}
			if (remove) continue;
			s.push_back(a[i][j]);
		}
		if (!s.empty()) ans.push_back(s);
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;

	return 0;
}