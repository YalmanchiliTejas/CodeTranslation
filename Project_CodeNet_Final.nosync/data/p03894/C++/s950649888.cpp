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
const double EPS  = 1e-10;
const bool debug = 0;
//----------------------//

int n, q;
bool dp[112345];
bool ok[112345];

int main() {
	cin >> n >> q;
	
	int p = 0;
	
	REP(i, q) {
		vector<pii> update;
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		
		if (p > 0) dp[p - 1] = true;
		if (p < n - 1) dp[p + 1] = true;
		
		if (p == a) p = b;
		else if (p == b) p = a;
		
		swap(dp[a], dp[b]);
		
		if (p > 0) dp[p - 1] = true;
		if (p < n - 1) dp[p + 1] = true;
	}
	
	ok[p] = true;
	REP(i, n) if (dp[i]) ok[i] = true;
	
	int ans = 0;
	REP(i, n) ans += ok[i];
	cout << ans << endl;
	
	return 0;
}
