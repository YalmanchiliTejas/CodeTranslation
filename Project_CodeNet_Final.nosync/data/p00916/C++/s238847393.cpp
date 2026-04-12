#include <bits/stdc++.h>
using namespace std;

int h, w;

int used[400][400];

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y) {
	used[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (0 <= tx && tx < h && 0 <= ty && ty < w && !used[tx][ty]) {
			dfs(tx, ty);
		}
	}
}

int main()
{
	int n;
	while (cin >> n, n) {
		vector<int> a(n), b(n), c(n), d(n), xs, ys;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i] >> d[i];
			if (a[i] > c[i]) swap(a[i], c[i]);
			if (b[i] > d[i]) swap(b[i], d[i]);
			a[i] *= 2;
			b[i] *= 2;
			c[i] *= 2;
			d[i] *= 2;
			for (int x = -1; x <= 1; x++) {
				xs.push_back(a[i] + x);
			}
			for (int x = -1; x <= 1; x++) {
				ys.push_back(b[i] + x);
			}
			for (int x = -1; x <= 1; x++) {
				xs.push_back(c[i] + x);
			}
			for (int x = -1; x <= 1; x++) {
				ys.push_back(d[i] + x);
			}
		}
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());
		h = xs.size();
		w = ys.size();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				used[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
			b[i] = lower_bound(ys.begin(), ys.end(), b[i]) - ys.begin();
			c[i] = lower_bound(xs.begin(), xs.end(), c[i]) - xs.begin();
			d[i] = lower_bound(ys.begin(), ys.end(), d[i]) - ys.begin();
			for (int y = b[i]; y <= d[i]; y++) {
				used[a[i]][y] = 1;
			}
			for (int x = a[i]; x <= c[i]; x++) {
				used[x][b[i]] = 1;
			}
			for (int y = b[i]; y <= d[i]; y++) {
				used[c[i]][y] = 1;
			}
			for (int x = a[i]; x <= c[i]; x++) {
				used[x][d[i]] = 1;
			}
		}
		int res = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!used[i][j]) {
					++res;
					dfs(i, j);
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}

