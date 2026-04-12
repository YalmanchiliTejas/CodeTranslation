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
int a[212345], ans[212345];

int main() {
	cin >> n;
	REP(i, n) scanf("%d", a + i);
	
	if (n % 2 == 0) {
		int p = 0;
		for (int i = n; i > 0; i -= 2) ans[p++] = a[i - 1];
		for (int i = 1; i < n; i += 2) ans[p++] = a[i - 1];
	}
	else {
		int p = 0;
		for (int i = n; i > 0; i -= 2) ans[p++] = a[i - 1];
		for (int i = 2; i < n; i += 2) ans[p++] = a[i - 1];
	}
	
	REP(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	
	return 0;
}
