// ACM-ICPCアジア地区予選2013 C. Count the Regions

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int main(){
	int n;
	long long region[102][102];
	while(cin >> n && n){
		memset(region, 0, sizeof(region));
		vector<int> l(n), t(n), r(n), b(n), x, y;
		for(int i=0;i<n;i++){
			cin >> l[i] >> t[i] >> r[i] >> b[i];
			x.push_back(l[i]);
			x.push_back(r[i]);
			y.push_back(t[i]);
			y.push_back(b[i]);
		}
		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());
		sort(y.begin(), y.end());
		y.erase(unique(y.begin(), y.end()), y.end());
		map<int, int> xidx, yidx;
		for(int i=0;i<x.size();i++) xidx[x[i]] = i+1;
		for(int i=0;i<y.size();i++) yidx[y[i]] = i+1;
		for(int i=0;i<n;i++){
			l[i] = xidx[l[i]];
			r[i] = xidx[r[i]];
			t[i] = yidx[t[i]];
			b[i] = yidx[b[i]];
			for(int j=l[i];j<r[i];j++){
				for(int k=b[i];k<t[i];k++){
					region[j][k] |= (1LL << i);
				}
			}
		}
		int res = 0;
		for(int i=0;i<102;i++){
			for(int j=0;j<102;j++){
				int dx[] = {-1, 0, 1, 0};
				int dy[] = {0, -1, 0, 1};
				if(region[i][j] == -1) continue;
				res++;
				queue< pair<int, int> > qu; qu.push(make_pair(i,j));
				long long r = region[i][j];
				region[i][j] = -1;
				while(!qu.empty()){
					pair<int,int> pr=qu.front(); qu.pop();
					int xpos = pr.first, ypos = pr.second;
					for(int k=0;k<4;k++){
						int nx = xpos+dx[k], ny = ypos+dy[k];
						if(nx<0||102<=nx||ny<0||102<=ny||region[nx][ny]==-1||region[nx][ny]!=r) continue;
						qu.push(make_pair(nx,ny));
						region[nx][ny] = -1;
					}
				}
			}
		}
		cout << res << endl;
	}
}