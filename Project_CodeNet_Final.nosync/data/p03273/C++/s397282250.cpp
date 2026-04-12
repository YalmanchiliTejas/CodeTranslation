#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}


struct distanceData {
	int distance, id;
};

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> board(H, vector<char>(W));
	vector<bool> compH(H, true), compW(W, true);
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			cin >> board[h][w];
			if (board[h][w] == '#') {
				compH[h] = false;
				compW[w] = false;
			}
		}
	}
	for (int h = 0; h < H; h++) {
		if (compH[h])continue;
		for (int w = 0; w < W; w++) {
			if (compW[w]) continue;
			cout << board[h][w];
		}
		cout << endl;
	}
}