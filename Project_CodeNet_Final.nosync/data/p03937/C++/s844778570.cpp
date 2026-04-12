#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<string> g(h);
	for (int i = 0; i < h; i++) {
		cin >> g[i];
	}
	vector<vector<int>> vis(h, vector<int>(w));
	queue<pair<int, int>> que;
	que.push(make_pair(0, 0));
	vis[0][0] = 1;
	int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
	while (que.size()) {
		pair<int, int> cur = que.front();
		que.pop();
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || x >= h || y < 0 || y >= w || g[x][y] == '.' || vis[x][y]) continue;
			if (cur.first - x == 1 || cur.second - y == 1) {
				cout << "Impossible" << endl;
				return 0;
			} else {
				if (flag) {
					cout << "Impossible" << endl;
					return 0;
				} else {
					vis[x][y] = true;
					que.push(make_pair(x, y));
					flag = true;
				}
			}
		}
	}
	cout << "Possible" << endl;
	return 0;	
}
