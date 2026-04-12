#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int main() {
	int H, W;
	cin >> H >> W;
	
	vector<string> maps;
	REP(i, H) {
		string s;
		cin >> s;
		maps.push_back(s);
	}
	
	vector<vector<int>> done(H, vector<int>(W, 0));
	int dx[]{1, 0}, dy[]{0, 1};
	
	bool ans = true;
	int cy = 0, cx = 0;
	while (true) {
		done[cy][cx] = true;
		if (cy == H - 1 && cx == W - 1) break;
		auto isinmap = [&](int y, int x) { return 0 <= y && y < H && 0 <= x && x < W; };
		bool update = false;
		REP(i, 2) {
			int ny = cy + dy[i], nx = cx + dx[i];
			if (isinmap(ny, nx) && maps[ny][nx] == '#') {
				cy = ny;
				cx = nx;
				update = true;
				break;
			}
		}
		if (!update) break;
	}
	
	ans &= cy == H - 1 && cx == W - 1;
	REP(i, H) REP(j, W) if (!done[i][j] && maps[i][j] == '#') ans = false;
	puts([&] {
		return ans;
	}() ? "Possible": "Impossible");
	
	return 0;
}
