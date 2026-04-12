#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define rep(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define rREP(i,m,n) for(int (i)=(n)-1; (i)>=(m);--(i))
#define all(x) (x).begin(),(x).end()
#define out(y,x,h,w) (y)<0||(x)<0||(y)>=(h)||(x)>=(w)
constexpr int INF = 1000000001;
constexpr ll mod = 1000000007;
constexpr double PI = 3.1415926535897932;

template<class T>inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T>inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
inline void init() {
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

vector<string>maze;
int H, W;
int x = 0, y = 0;
void dfs(Graph& vec) {
	if (y == H)return;
	vec[y][x]++;
	if (y + 1 < H && maze[y + 1][x] == '#') {
		++y;
		dfs(vec);
	}
	else if (x + 1 < W && maze[y][x + 1] == '#') {
		++x;
		dfs(vec);
	}
	return ;
}
int main() {
	init();

	cin >> H >> W;
	maze.resize(H);
	rep(i, 0, H)cin >> maze[i];
	Graph G(H, vector<int>(W, 0));
	dfs(G);
	bool is = true;
	rep(i, 0, H) {
		rep(j, 0, W) {
			if (maze[i][j] == '#' && G[i][j] == 0)is = false;
		}
	}
	cout << (is ? "Possible" : "Impossible") << "\n";


	return 0;
}
