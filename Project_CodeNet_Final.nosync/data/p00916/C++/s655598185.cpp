#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;


inline int index(const vector<int> &v, int x){
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
vector<vector<LL> > fl;

void dfs(int x, int y, LL c){
	fl[x][y] = -1;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < fl.size() && ny < fl[0].size() && fl[nx][ny] == c){
			dfs(nx, ny, c);
		}
	}
}


int main(){

	int n;
	while(scanf("%d", &n), n){
		vector<int> ls(n), ts(n), rs(n), bs(n), xs, ys;
		for(int i = 0; i < n; ++i){
			scanf("%d%d%d%d", &ls[i], &ts[i], &rs[i], &bs[i]);
			
			for(int j = 0; j < 2; ++j){
				xs.push_back(ls[i] - j);
				xs.push_back(rs[i] - j);
				ys.push_back(bs[i] - j);
				ys.push_back(ts[i] - j);
			}
		}

		sort(xs.begin(), xs.end());
		sort(ys.begin(), ys.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());

		fl.assign(xs.size(), vector<LL>(ys.size()));
		for(int i = 0; i < n; ++i)
		for(int j = index(xs, ls[i]); xs[j] < rs[i]; ++j)
		for(int k = index(ys, bs[i]); ys[k] < ts[i]; ++k){
			fl[j][k] |= 1LL << i;
		}

		int ans = 0;
		for(int i = 0; i < xs.size(); ++i)
		for(int j = 0; j < ys.size(); ++j){
			if(fl[i][j] != -1){
				++ans;
				dfs(i, j, fl[i][j]);
			}
		}
		
		printf("%d\n", ans);
	}
}