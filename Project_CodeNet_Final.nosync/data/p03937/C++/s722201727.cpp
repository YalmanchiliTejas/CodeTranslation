#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DEBUG 0
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define dump(o) if(DEBUG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DEBUG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
using ll = long long; using ull = unsigned long long; using pii = pair<int, int>;
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
static const int MOD = 1e9 + 7;

int H, W;
char a[10][10] = {};
int b[10][10] = {};
void dfs(int x, int y, int c) {
	if (a[x][y] == '.')return;
	b[x][y] = max(b[x][y], c);
	int dx[2] = { 1,0 };
	int dy[2] = { 0,1 };
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		dfs(nx, ny, c + 1);
	}
}

signed main() {
	cin >> H >> W;
	int sharp = 0;
	rep(i, 0, 10)rep(j, 0, 10)a[i][j] = '.';
	rep(i, 1, H + 1)rep(j, 1, W + 1) {
		cin >> a[i][j];
		if (a[i][j] == '#')sharp++;
	}
	dfs(1, 1, 1);
	if (b[H][W] == sharp)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}