#include <bits/stdc++.h>
using namespace std;
#define DEBUG 0
#define nl          '\n'
#if     DEBUG
#define trace(var)  {cerr << "Line " << __LINE__ << ": " << #var << "=" << var << nl;}
#else
#define trace(var)	{}
#endif
#define fori(n)			for(int i = 0; i < n; ++i) 
#define forj(n)			for(int j = 0; j < n; ++j)
#define fork(n)			for(int k = 0; k < n; ++k)
#define forl(n)			for(int l = 0; l < n; ++l)

typedef long long ll;typedef pair<int,int> pii;typedef vector<bool> vbool;typedef vector<int> vint;typedef vector<ll> vll;typedef long double ld;typedef vector<vector<int>> vvi;

const ll N = 3000;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

int n;
ll memo[N][N][2];

ll solve(vll &a, int i, int j, bool mxmz) {
	if (i > j) return 0;
	if (memo[i][j][mxmz] != -1) {
		return memo[i][j][mxmz];
	}
	ll ans;
	if (mxmz) {
		ans = memo[i][j][mxmz] = max(a[i] + solve(a, i+1, j, !mxmz), a[j] + solve(a, i, j-1, !mxmz));
	} else {
		ans = memo[i][j][mxmz] = min(-a[i] + solve(a, i+1, j, !mxmz), -a[j] + solve(a, i, j-1, !mxmz));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(memo, -1, sizeof memo);
	cin >> n; 
	vll a(n);
	fori(n) {cin >> a[i];}
	cout << solve(a, 0, n-1, true) << nl;

	#if DEBUG
	cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << " s" << nl;
	#endif
	return 0;
}
