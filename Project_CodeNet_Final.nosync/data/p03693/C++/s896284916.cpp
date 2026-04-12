
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 9999999

using namespace std;

typedef pair<int, int> P;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int H, W;
//迷路を表す配列
char meiro[501][501];

//位置(x,y)からゴールまでたどり着けるか判定する
bool dfs(int x, int y) {
	//現在位置がゴールならOK
	if (meiro[x][y] == 'g') {
		return true;
	}

	//4方向について探索
	REP(i, 4) {
		//隣のマスの座標を(nx,ny)とする
		int nx = x + dx[i];
		int ny = y + dy[i];

		//移動後のマスが迷路に収まっているか、あるいは通れないマスでないか判定
		if (nx < 0 || nx >= H || ny < 0 || ny >= W || meiro[nx][ny] == '#')continue;
		//さっきまでいたマスを'#'で塗りつぶす
		meiro[x][y] = '#';
		if (dfs(nx, ny))return true;
	}
	return false;
}

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	int c = 100 * r + 10 * g + b;
	if (c % 4 == 0)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
