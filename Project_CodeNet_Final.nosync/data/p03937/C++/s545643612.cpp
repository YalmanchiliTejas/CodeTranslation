#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int H, W;
vector<string>grid1,grid2;
bool dfs1(int h, int w) {
	grid1[h][w] = '.';
	if (h == H-1 && w == W-1)return false;
	rep(i, 2) {
		rep(j,2){
			if (i == j)continue;

			int dh = h + j, dw = w + i;
			if (dh < 0 || H <= dh || dw < 0 || W <= dw || grid1[dh][dw] == '.')continue;
			if (!dfs1(dh, dw))return false;
		}
	}
	return true;
}

bool dfs2(int h, int w) {
	grid2[h][w] = '.';
	if (h == H - 1 && w == W - 1)return false;
	for (int i = 1; i >= 0;i--) {
		for (int j = 1; j >= 0;j--) {
			if (i == j)continue;

			int dh = h + j, dw = w + i;
			if (dh < 0 || H <= dh || dw < 0 || W <= dw || grid2[dh][dw] == '.')continue;
			if (!dfs2(dh, dw))return false;
		}
	}
	return true;
}

int main() {
	cin >> H >> W;
	grid1.resize(H);
	rep(i, H)cin >> grid1[i];
	grid2 = grid1;
	dfs1(0, 0);
	dfs2(0, 0);
	bool ans = true;
	for (auto s : grid1) {
		for (auto ss : s)if (ss == '#')ans = false;
	}
	for (auto s : grid2) {
		for (auto ss : s)if (ss == '#')ans = false;
	}
	if (ans) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}

