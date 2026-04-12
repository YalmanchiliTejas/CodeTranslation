#include <iostream>
#include <vector>

using namespace std;

int main() {
	int h, w; cin >> h >> w;
	vector<vector<char> > grid(h, vector<char>(w));
	vector<bool> xflag(h), yflag(w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == '#') xflag[i] = yflag[j] = true;
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (xflag[i] && yflag[j]) cout << grid[i][j];
		}
		if (xflag[i]) cout << endl;
	}


	return 0;
}