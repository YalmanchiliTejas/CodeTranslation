#include<iostream>
#include<vector>
#include<queue>
using namespace std;
char r[51][51]; int H, W, Q, a[2601], b[2601], c[2601], d[2601], T; vector<int>x[2601], u[2601]; pair<int, int>dist[2601];
void Goto(int p1, int p2) {
	for (int i = 0; i < H*W; i++)dist[i] = make_pair(1 << 30, 1 << 30);
	queue<int>Q; Q.push(p1); dist[p1] = make_pair(0, 1 << 30); int p3 = p2;
	while (!Q.empty()) {
		int a1 = Q.front(); Q.pop();
		for (int i : x[a1]) {
			if (dist[i].first > dist[a1].first + 1) { dist[i] = make_pair(dist[a1].first + 1, a1); Q.push(i); }
		}
	}
	while (p2 != p1) { u[p2].push_back(T + dist[p2].first); p2 = dist[p2].second; }
	T += dist[p3].first;
}
int main() {
	cin >> H >> W >> Q;
	for (int i = 0; i < H; i++) { for (int j = 0; j < W; j++)cin >> r[i][j]; } for (int i = 0; i < H*W; i++)cin >> a[i]; for (int i = 0; i < H*W; i++)cin >> b[i]; for (int i = 0; i < H*W; i++)cin >> c[i];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
			for (int k = 0; k < 4; k++) {
				int ex = i + dx[k], ey = j + dy[k];
				if (ex < 0 || ey < 0 || ex >= H || ey >= W || r[ex][ey] == '#' || r[i][j] == '#')continue;
				x[i*W + j].push_back(ex*W + ey); x[ex*W + ey].push_back(i*W + j);
			}
		}
	}
	for (int i = 0; i < Q; i++) { int ax, bx; cin >> ax >> bx; d[i] = ax*W + bx; }
	u[d[0]].push_back(0); int ret = 0; for (int i = 0; i < Q - 1; i++) { Goto(d[i], d[i + 1]); }
	for (int i = 0; i < H*W; i++) {
		if (u[i].size() >= 1)ret += b[i] + c[i];
		for (int j = 0; j < (int)u[i].size() - 1; j++) {
			if ((u[i][j + 1] - u[i][j])*a[i] >= b[i] + c[i]) { ret += b[i] + c[i]; }
			else { ret += (u[i][j + 1] - u[i][j])*a[i]; }
		}
	}
	cout << ret << endl;
	return 0;
}