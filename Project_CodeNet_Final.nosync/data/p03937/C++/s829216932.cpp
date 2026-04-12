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
	cin >> h >> w;
	vector<string> a(h);
	vector<vector<bool>> c(h, vector<bool>(w, false));
	rep(snip_i, h) cin >> a.at(snip_i);
	int x, y;
	x = y = 0;
	int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
	while(1){
		int nx_i = -1;
		rep(i, 4){
			int nx, ny;
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
			if(a.at(ny)[nx] == '#' && c.at(ny).at(nx) == false){
				if(i == 2 || i == 3){
					cout << "Impossible" << endl;
					return 0;
				}else{
					if(nx_i == -1) nx_i = i;
					else{
						cout << "Impossible" << endl;
						return 0;
					}
				}
			}
		}
		int nx = x + dx[nx_i], ny = y + dy[nx_i];
		c.at(y).at(x) = true;
		if(x == w-1 && y == h-1) break;
		x = nx; y = ny;
	}
	cout << "Possible" << endl;
	return 0;
}