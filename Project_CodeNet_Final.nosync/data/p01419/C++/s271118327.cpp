#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <string>
using namespace std;

using ll = long long int;
vector<int> dp[55][55];
string board[55];
int t;
int d[55][55];
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
int h, w, m;
int gx, gy;

void dfs(int x, int y) {
	if (x == gx && y == gy) return;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 > nx || w <= nx || 0 > ny || h <= ny || board[ny][nx] == '#') continue;
		if (d[ny][nx] > d[y][x] + 1) {
			d[ny][nx] = d[y][x] + 1;
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> h >> w >> m;
	for (int i = 0; i < h; ++i) cin >> board[i];
	vector<int> a(h*w), b(h*w), c(h*w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) cin >> a[i*w + j];
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) cin >> b[i*w + j];
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) cin >> c[i*w + j];
	}
	vector<int> x(m), y(m);
	for (int i = 0; i < m; ++i) {
		cin >> y[i] >> x[i];
	}

	t = 0;
	for (int i = 1; i < m; ++i) {
		//cout << "i:" << i << endl;
		// i-1 -> i
		gx = x[i], gy = y[i];
		for (int j = 0; j < h; ++j) {
			for (int k = 0; k < w; ++k) {
				d[j][k] = 1 << 30;
			}
		}
		d[y[i - 1]][x[i - 1]] = 0;
		dfs(x[i - 1], y[i - 1]);

		vector<pair<int, int>> path;
		int ax = x[i], ay = y[i];
		if (i == m - 1) path.push_back({ ax, ay });
		// cout << "ax" << x[i-1] << " " << y[i-1] << endl;
		while (ax != x[i - 1] || ay != y[i - 1]) {
			//cout << ax << "," << ay << endl;
			for (int j = 0; j < 4; ++j) {
				int nx = ax + dx[j], ny = ay + dy[j];
				// cout << nx << " " << ny << " " << dx[j] << " " << dy[j] << endl;
				if (0 > nx || w <= nx || 0 > ny || h <= ny) continue;
				// cout << d[ny][nx] << endl;
				if (d[ny][nx] == d[ay][ax] - 1) {
					ax = nx, ay = ny;
					break;
				}
			}
			path.push_back({ ax, ay });
		}
		// path.push_back({ x[i - 1], y[i - 1] });
		reverse(path.begin(), path.end());
		//cout << "-----" << endl;

		for (auto j : path) {
			//cout << j.first << "," << j.second << endl;
			dp[j.second][j.first].push_back(t);
			t++;
		}
		//cout << endl;
	}

	int ret = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			//for (auto k : dp[i][j]) cout << k << " ";
			//cout << endl;
			for (int k = 0; k < (int)dp[i][j].size() - 1; ++k) {
				int vl = b[i*w + j] + c[i*w + j];
				int vr = a[i*w + j] * (dp[i][j][k + 1] - dp[i][j][k]);
				ret += min(vl, vr);
			}
			if (dp[i][j].size()) {
				ret += b[i*w + j] + c[i*w + j];
			}
			//cout << ret << endl;
		}
	}

	cout << ret << endl;
}
