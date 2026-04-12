#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)



int H, W;
string A[10];
//-----------------------------------------------------------------
string ans = "Possible";
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };
void dfs(int x, int y) {
	if (x == W - 1 && y == H - 1) return;

	int a = -1, b = -1;
	rep(i, 0, 2) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (W <= xx) continue;
		if (H <= yy) continue;

		if (A[yy][xx] == '#') {
			A[yy][xx] = '.';
			if (0 <= a) {
				ans = "Impossible";
				return;
			}
			a = xx;
			b = yy;
		}
	}

	if(a < 0) {
		ans = "Impossible";
		return;
	}

	dfs(a, b);
}
//-----------------------------------------------------------------
int main() {
	cin >> H >> W;
	rep(y, 0, H) cin >> A[y];

	A[0][0] = '.';
	dfs(0, 0);

	rep(y, 0, H) rep(x, 0, W) if (A[y][x] == '#') ans = "Impossible";
	cout << ans << endl;
}