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
typedef pair<int, pii> pip;
typedef pair<pll, pll> P;
const ll INF = 1ll<<29;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int main() {
	string str[100];
	bool isnr[100][100] = {};
	int H, W;
	cin >> H >> W;
	REP(i, H) cin >> str[i];
	
	REP(i, H) {
		bool ok = true;
		REP(j, W) if (str[i][j] == '#') ok = false;
		if (ok) REP(j, W) isnr[i][j] = true;
	}
	
	REP(j, W) {
		bool ok = true;
		REP(i, H) if (str[i][j] == '#') ok = false;
		if (ok) REP(i, H) isnr[i][j] = true;
	}
	
	REP(i, H) {
		bool isln = true;
		REP(j, W) if (!isnr[i][j]) isln = false;
		if (isln) continue;
		REP(j, W) if (!isnr[i][j]) putchar(str[i][j]);
		puts("");
	}
	
	return 0;
}