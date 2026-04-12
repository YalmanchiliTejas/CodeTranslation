#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define for_rev(i,a,b) for(int i=(a);i>=(b);--i)
#define allof(a) (a).begin(),(a).end()
#define size_of(a) (int)(a).size()
#define minit(a,b) memset(a,b,sizeof(a))

typedef pair< int, int > pii;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

int R, C, M, eunit[55][55], eon[55][55], eoff[55][55];
string grid[55];

int sx, sy, gx, gy;
bool vis[55][55];
vector< int > tv[55][55];

bool dfs(int x, int y, vector< pii >& path) {
	if (x == gx && y == gy) return true;
	
	path.push_back(pii(x, y));
	
	vis[y][x] = true;
	
	for_(d,0,4) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || C <= nx || ny < 0 || R <= ny) continue;
		if (grid[ny][nx] == '#') continue;
		if (vis[ny][nx]) continue;
		if (dfs(nx, ny, path)) return true;
	}
	
	path.pop_back();
	
	return false;
}

int main() {
	cin >> R >> C >> M;
	for_(i,0,R) cin >> grid[i];
	
	for_(i,0,R) for_(j,0,C) cin >> eunit[i][j];
	for_(i,0,R) for_(j,0,C) cin >> eon[i][j];
	for_(i,0,R) for_(j,0,C) cin >> eoff[i][j];
	
	vector< pii > euler;
	
	cin >> sy >> sx;
	
	for_(i,1,M) {
		cin >> gy >> gx;
		vector< pii > path;
		
		minit(vis, 0);
		
		dfs(sx, sy, path);
		
		int m = size_of(path);
		for_(j,0,m) euler.push_back(path[j]);
		sx = gx; sy = gy;
	}
	
	euler.push_back(pii(gx, gy));
	int m = size_of(euler), ans = 0;
	
	for_(i,0,m) {
		pii p = euler[i];
		int x = p.first, y = p.second;
		tv[y][x].push_back(i);
	}
	
	for_(y,0,R) for_(x,0,C) {
		int m = tv[y][x].size();
		
		if (m > 0) {
			for_(i,0,m-1) ans += min((tv[y][x][i + 1] - tv[y][x][i]) * eunit[y][x], eoff[y][x] + eon[y][x]);
			ans += eon[y][x] + eoff[y][x];
		}
	}
	
	cout << ans << endl;
}