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

ll acnt[51], pcnt[51];

ll solve(int n, ll x) {
	if (n == 0) return 1;
	
	ll res = 0;
	
	if (x == 1) return res;
	x--;
	
	if (x <= acnt[n - 1]) return res + solve(n - 1, x);
	x -= acnt[n - 1];
	res += pcnt[n - 1];
	
	if (x == 1) return res + 1;
	x--; res++;
	
	if (x <= acnt[n - 1]) return res + solve(n - 1, x);
	x -= acnt[n - 1];
	res += pcnt[n - 1];
	
	return res;
}

int main() {
	ll N, X;
	cin >> N >> X;
	
	acnt[0] = 1;
	pcnt[0] = 1;
	FOR(i, 1, N + 1) {
		acnt[i] = acnt[i - 1] * 2 + 3;
		pcnt[i] = pcnt[i - 1] * 2 + 1;
	}
	
	cout << solve(N, X) << endl;
	return 0;
}
