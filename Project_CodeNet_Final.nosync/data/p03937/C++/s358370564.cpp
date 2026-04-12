#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second

template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pll> P;

const ll INF = 1ll<<30;
const ll MOD = 1000000007;
const double EPS  = 1e-10;

int main() {
	int h, w;
	cin >> h >> w;
	string maps[8];
	REP(i, h) cin >> maps[i];
	
	bool done[8][8] = {};
	
	bool ans = true;
	
	int x = 0, y = 0;
	done[0][0] = true;
	while (x + 1 != w || y + 1 != h) {
		if (x + 1 < w && maps[y][x + 1] == '#') x++;
		else if (y + 1 < h && maps[y + 1][x] == '#') y++;
		else {
			ans = false;
			break;
		}
		
		done[y][x] = true;
	}
	
	REP(i, h) REP(j, w) if (maps[i][j] == '#' && !done[i][j]) ans = false;
	puts(ans ? "Possible" : "Impossible");
	
	return 0;
}
