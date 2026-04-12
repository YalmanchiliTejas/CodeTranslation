#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int h, w;
	int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a.at(i);
	vector<vector<bool>> c(h, vector<bool>(w, false));
	int x, y;
	x = y = 0;
	while(1){
		int n_ = 10;
		rep(i, 4){
			int nx, ny;
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
			if(a.at(ny)[nx] == '#' && c.at(ny).at(nx) == false){
				if(i == 2 || i == 3 || n_ != 10){
					// cerr << "1tst" << endl;
					cout << "Impossible" << endl;
					return 0;
				}
				n_ = i;
			}
		}
		c.at(y).at(x) = true;
		// cerr << x << " " << y << endl;
		if(x == w-1 && y == h-1) break;
		x = x + dx[n_];
		y = y + dy[n_];
	}
	cout << "Possible" << endl;
	return 0;
}
