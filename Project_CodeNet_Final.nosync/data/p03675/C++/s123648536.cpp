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
const ll INF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS  = 1e-9;

int n;
int a[212345];

int main() {
	cin >> n;
	REP(i, n) scanf("%d", a + i);
	
	deque<int> deq;
	REP(i, n) {
		if (i & 1) deq.push_back(a[i]);
		else deq.push_front(a[i]);
	}
	
	vector<int> ans;
	REP(i, n) ans.push_back(deq[i]);
	
	if (n % 2 == 0) reverse(ALL(ans));
	
	REP(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	
	return 0;
}