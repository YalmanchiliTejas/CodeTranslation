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
const ll INF = 1e9+100;
const ll MOD = 1e9+7;
const double EPS  = 1e-10;
const bool debug = 0;
//---------------------------//

int main(){
	int e[12];
	REP(i, 12) scanf("%d", e + i);
	sort(e, e + 12);
	
	bool ans = true;
	REP(i, 3) {
		bool ng = false;
		REP(j, 4) if (e[i*4+j] != e[i*4]) ng = true;
		if (ng) ans = false;
	}
	
	puts(ans ? "yes" : "no");
	
	return 0;
}