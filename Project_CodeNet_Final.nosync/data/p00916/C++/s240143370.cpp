#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <map>
using namespace std;

int l[50];
int t[50];
int r[50];
int b[50];

// right, down, left, up
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

bool can[200][200][4];
bool visit[200][200];

int H, W;

bool in(int x, int y) {
	return 0 <= x && x < W && 0 <= y && y < H;
}

void dfs(int x, int y) {
	visit[y][x] = true;
	for(int k = 0; k < 4; k++) {
		if(can[y][x][k]) {
			int nx = x + dx[k], ny = y + dy[k];
			if(!visit[ny][nx]) dfs(nx, ny);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	while(cin >> n, n) {
		map<int, int> X, Y;
		for(int i = 0; i < n; i++) {
			cin >> l[i] >> t[i] >> r[i] >> b[i];
			for(int j = 0; j <= 1; j++) {
				X[l[i] + j] = -1;
				X[r[i] + j] = -1;
				Y[t[i] + j] = -1;
				Y[b[i] + j] = -1;
			}
		}

		H = Y.size(), W = X.size();

		int cnt = 0;
		for(auto& p : X) {
			X[p.first] = cnt++;
		}
		cnt = H - 1;
		for(auto& p : Y) {
			Y[p.first] = cnt--;
		}

		for(int y = 0; y < H; y++) {
			for(int x = 0; x < W; x++) {
				for(int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					can[y][x][k] = in(nx, ny);
				}
			}
		}

		for(int i = 0; i < n; i++) {
			for(int x = X[l[i] + 1]; x <= X[r[i]]; x++) {
				can[Y[t[i]]][x][3] = false; // up
				can[Y[t[i] + 1]][x][1] = false; // down
				can[Y[b[i]]][x][3] = false; // up
				can[Y[b[i] + 1]][x][1] = false; // down
			}
			for(int y = Y[t[i]]; y <= Y[b[i] + 1]; y++) {
				can[y][X[l[i]]][0] = false; // right
				can[y][X[l[i] + 1]][2] = false; // left
				can[y][X[r[i]]][0] = false; // right
				can[y][X[r[i] + 1]][2] = false; // left
			}
		}

		memset(visit, 0, sizeof visit);
		int ans = 0;
		for(int y = 0; y < H; y++) {
			for(int x = 0; x < W; x++) {
				if(!visit[y][x]) {
					ans++;
					dfs(x, y);
				}
			}
		}
		cout << ans << endl;
	}
}