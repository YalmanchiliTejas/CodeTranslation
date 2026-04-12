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

ll N;
ll a[50];

int main() {
	cin >> N;
	REP(i, N) cin >> a[i];
	
	ll ans = 0;
	
	while (true) {
		ll cnt = 0;
		REP(i, N) cnt += a[i] / N;
		
		REP(i, N) {
			ll now = cnt - a[i] / N;
			
			ll c = a[i] / N;
			
			a[i] -= c * N;
			a[i] += now;
			
			ans += c;
		}
		
		if (cnt == 0) break;
	}
	
	cout << ans << endl;
	
	return 0;
}
