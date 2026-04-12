#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define rep(i,m,n) for(int (i)=(m);(i)<(n);++(i))
#define rREP(i,m,n) for(int (i)=(n)-1;(i)>=(m);--(i))
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

int dx[] = { 1,0 };
int dy[] = { 0,1 };


int main() {
	init();

	int H, W; cin >> H >> W;
	vector<string>maze(H);
	rep(i, 0, H)cin >> maze[i];
	bool ans = true;
	rep(i, 0, H) {
		rep(j, 0, W) {
			int cnt = 0;
			rep(k, 0, 2) {
				int nx = j + dx[k], ny = i + dy[k];
				if (out(ny, nx, H, W))continue;
				if (maze[ny][nx] == '#')cnt++;
			}
			if (cnt == 2)ans = false;
		}
	}
	cout << (ans ? "Possible" : "Impossible") << "\n";

	return 0;
}