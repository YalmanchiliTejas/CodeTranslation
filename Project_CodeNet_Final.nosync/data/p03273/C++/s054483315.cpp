#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <unordered_map>
#define INF 9999999
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char> > grid(H, vector<char>(W, 0));
	for (int i = 0; i < H; i++)for (int j = 0; j < W; j++) {
		cin >> grid[i][j];
	}
	vector<int> gyo, retu;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (grid[j][i] != '.') break;
			if (j == H - 1) retu.push_back(i);
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (grid[i][j] != '.') break;
			if (j == W - 1) gyo.push_back(i);
		}
	}
	for (int i = 0; i < H; i++){
		if (find(gyo.begin(), gyo.end(), i) != gyo.end()) continue;
		for (int j = 0; j < W; j++) {
			if (find(retu.begin(), retu.end(), j) == retu.end()) {
				cout << grid[i][j];
			}
			if (j == W - 1) cout << endl;
		}
	}
	return 0;
}