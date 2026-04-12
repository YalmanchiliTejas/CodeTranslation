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
const ll INF = 1e18+100;
const ll MOD = 1000000007;
const double EPS = 1e-10;
const bool debug = 0;
//------------------------------//

int main() {
	string s;
	cin >> s;
	
	bool ans = false;
	REP(i, s.size() - 1) if (s[i] == 'A' && s[i + 1] == 'C') ans = true;
	puts(ans ? "Yes" : "No");
	
	return 0;
}
