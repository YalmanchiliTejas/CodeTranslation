#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

const ll N = 3010;
ll a[N], dp[N][N];

ll rec(ll i, ll j) {
	if (i == j) return a[i];
	if (dp[i][j] != oo) return dp[i][j];
	return dp[i][j] = max(a[i] - rec(i+1,j), a[j] - rec(i,j-1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dp,0x3f,sizeof dp);

	ll n; cin >> n;
	FOR(i,0,n) cin >> a[i];
	cout << rec(0,n-1) << endl;
}

