#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<char>> g(H, vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> g[i][j];
		}
	}

	for (int i = 0; i < H; i++) {
		bool b = true;
		for (int j = 0; j < W; j++) {
			if (g[i][j] == '#') {
				b = false;
				break;
			}
		}
		if (b) {
			for (int j = 0; j < W; j++) {
				g[i][j] = 'd';
			}
		}
	}

	for (int i = 0; i < W; i++) {
		bool b = true;
		for (int j = 0; j < H; j++) {
			if (g[j][i] == '#') {
				b = false;
				break;
			}
		}
		if (b) {
			for (int j = 0; j < H; j++) {
				g[j][i] = 'd';
			}
		}
	}

	//for (int i = 0; i < H; i++) {
	//	for (int j = 0; j < W; j++) {
	//		cout << g[i][j];
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < H; i++) {
		bool f = false;
		for (int j = 0; j < W; j++) {
			if (g[i][j] != 'd') {
				cout << g[i][j];
				f = true;
			}
		}
		if (f) cout << endl;
	}
}