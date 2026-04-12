#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

int h, w;
vector<vector<char>> grid;
vector<vector<int>> dist;

void dfs(int y, int x, int d){
	if(dist[y][x] <= d) return;
	dist[y][x] = d;
	if(y == h-1 && x == w-1) return;
	if(x+1 < w && grid[y][x+1] == '#') dfs(y, x+1, d+1);
	if(y+1 < h && grid[y+1][x] == '#') dfs(y+1, x, d+1);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> h >> w;
	grid.resize(h, vector<char>(w));
	dist.resize(h, vector<int>(w, INF));
	int cnt = 0;
	rep(i,h)rep(j,w){
		cin >> grid[i][j];
		if(grid[i][j] == '#') cnt++;
	}
	if(grid[0][0] != '#'){
		cout << "Impossible" << endl;
		return 0;
	}
	dfs(0, 0, 1);
	if(cnt == dist[h-1][w-1]) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}