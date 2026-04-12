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
typedef pair<int, pll> pip;
const ll INF = 1ll<<29;
const ll MOD = 1000000007;
const double EPS  = 1e-9;

int main() {
	int s[5];
	int a, b;
	while (cin >> a >> b, a || b) {
		s[0] = a + b;
		FOR(i, 1, 5) {
			cin >> a >> b;
			s[i] = a + b;
		}
		
		pii ma(-1, 0);
		REP(i, 5) chmax(ma, pii(s[i], i));
		
		printf("%c %d\n", ma.se + 'A', ma.fi);
	}
	return 0;
}