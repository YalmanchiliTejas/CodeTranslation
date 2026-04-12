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
const ll INF = 1ll<<29;
const ll MOD = 1000000007;
const double EPS = 1e-10;
const bool debug = 0;
//------------------------------//

int N;
int d[312345];

bool solve() {
	for (int i = 0, ma = 0; i <= ma; i++) {
		chmax(ma, d[i] + i);
		if (ma >= N - 1) return true;
	}
	return false;
}

int main() {
	cin >> N;
	REP(i, N) scanf("%d", d + i), d[i] /= 10;
	
	bool ans = solve();
	reverse(d, d + N);
	ans &= solve();
	
	puts(ans ? "yes" : "no");
	
	return 0;
}