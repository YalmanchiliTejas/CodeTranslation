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
typedef pair<int, pii> P;

const ll INF = 1ll<<30;
const ll MOD = 1000000007;
const double EPS  = 1e-10;

int N;
ll x[212345], y[212345];

int main() {
	cin >> N;
	REP(i, N) {
		scanf("%lld %lld", x + i, y + i);
		if (x[i] > y[i]) swap(x[i], y[i]);
	}
	
	ll ans;
	
	if (N == 1) ans = 0;
	else {
		// Rmax=最大値, Bmin=最小値
		ans = (*max_element(x, x + N) - *min_element(x, x + N)) * (*max_element(y, y + N) - *min_element(y, y + N));
		
		// Rmax=最大値, Rmin=最小値
		ll diff = *max_element(y, y + N) - *min_element(x, x + N);
		
		set<pii> ss;
		REP(i, N) ss.insert(pii(x[i], i));
		ss.insert(pii(y[ss.begin()->se], -1));
		ss.erase(ss.begin());
		
		while (ss.begin()->se >= 0) {
			chmin(ans, diff * (ss.rbegin()->fi - ss.begin()->fi) );
			pii tmp = pii(y[ss.begin()->se], -1);
			ss.erase(ss.begin());
			ss.insert(tmp);
		}
		chmin(ans, diff * (ss.rbegin()->fi - ss.begin()->fi) );
	}
	cout << ans << endl;
	
	return 0;
}
