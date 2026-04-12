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
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const bool debug = 0;
//---------------------------------//

int N;
int S[112345];

int main() {
	cin >> N;
	REP(i, N) scanf("%d", S + i);
	
	ll ans = 0;
	
	FOR(d, 1, N - 1) {
		// d = B - A
		
		ll cur = 0;
		int l = 0, r = N - 1;
		
		while (true) {
			l += d;
			r -= d;
			
			if (l >= N - 1 || r <= 0) break;
			if (l >= r && ((N - 1 - l) % d == 0 || r % d == 0)) break;
			int A = N - 1 - l;
			if (A <= d) break;
			
			cur += S[r];
			cur += S[l];
			chmax(ans, cur);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
