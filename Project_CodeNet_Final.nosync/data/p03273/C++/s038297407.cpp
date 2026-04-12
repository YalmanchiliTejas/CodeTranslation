#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solver {
public:
	static void solve() {
		int h, w;
		cin >> h >> w;
		vector<string> grid;
		for (int i = 0; i < h; i++) {
			string s;
			cin >> s;
			grid.emplace_back(s);
		}

		vector<bool> removableV(w, false);
		for (int i = 0; i < w; i++) {
			int cnt = 0;
			for (int j = 0; j < h; j++) {
				if (grid[j][i] == '.')cnt++;
			}
			if (cnt == h)removableV[i] = true;
		}
		vector<bool> removableH(h, false);
		for (int i = 0; i < h; i++) {
			int cnt = 0;
			for (int j = 0; j < w; j++) {
				if (grid[i][j] == '.')cnt++;
			}
			if (cnt == w)removableH[i] = true;
		}

		for (int i = 0; i < h; i++) {
			if (removableH[i])continue;
			for (int j = 0; j < w; j++) {
				if (removableV[j])continue;
				cout << grid[i][j];
			}
			cout << endl;
		}
	}
};

int main() {
	Solver::solve();
}