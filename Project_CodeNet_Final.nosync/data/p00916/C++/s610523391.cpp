#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> pi4;

ll f[103][103];
bool visit[103][103];
int w, h;

void dfs(int y, int x) { 
	visit[y][x] = true;
	const int dy[] = {-1,0,1,0};
	const int dx[] = {0,1,0,-1};
	rep(i,4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0<=nx && nx<w && 0<=ny && ny<h && !visit[ny][nx] && f[y][x]==f[ny][nx]) {
			dfs(ny,nx);
		}
	}
}

int main() {
	int n;
	while(cin >> n, n) {
		vector<pi4> v(n);
		set<int> sx, sy;
		rep(i, n) {
			cin >> v[i].X.X >> v[i].Y.Y >> v[i].X.Y >> v[i].Y.X;
			sx.insert(v[i].X.X);
			sx.insert(v[i].X.Y);
			sy.insert(v[i].Y.X);
			sy.insert(v[i].Y.Y);
		}
		map<int,int> mpx, mpy;
		w=1; h=1;
		for(set<int>::iterator it=sx.begin(); it!=sx.end(); it++) {
			mpx[*it] = w++;
		}
		for(set<int>::iterator it=sy.begin(); it!=sy.end(); it++) {
			mpy[*it] = h++;
		}
		w++; h++;
		memset(f, 0, sizeof(f));
		rep(i, n) {
			int l = mpx[v[i].X.X];
			int r = mpx[v[i].X.Y];
			int b = mpy[v[i].Y.X];
			int t = mpy[v[i].Y.Y];
			ll bit = 1LL << i;
			for(int y=b; y<t; y++) {
				for(int x=l; x<r; x++) {
					f[y][x] |= bit;
				}
			}
		}
		int res = 0;
		memset(visit, 0, sizeof(visit));
		for(int y=0; y<h; y++) {
			for(int x=0; x<w; x++) {
				if( !visit[y][x] ) {
					res++;
					dfs(y,x);
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}