#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _cin      ios_base::sync_with_stdio(0);  cin.tie(0);
#define READ      freopen("input.txt", "r", stdin);
#define WRITE     freopen("output.txt", "w", stdout);
#define endl "\n"
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>=b;--i)
#define mp make_pair
#define hell 1000000007
#define vvll vector<vector<ll> >
#define vll vector<ll>
#define mll map<ll,ll>
#define sz(x) (ll)x.size()
#define sll set<ll>
#define pll pair<ll,ll>
#define F first
#define S second
const ll MAX = 3001;
const ll INF = 1e18L + 5;
ll x_t = 0, y_j = 0;
ll dp[MAX][MAX];

ll max_score(ll a[], ll l, ll r) {

	if (l > r) return 0;
	if (l == r) return a[l];
	if (dp[l][r] != -1) return dp[l][r];

	ll ans = a[l] - max_score(a, l + 1, r);
	ans = max(ans, a[r] - max_score(a, l, r - 1));
	dp[l][r] = ans;
	return dp[l][r];

}




int main() {

	_cin
	// READ
	// WRITE
	ll n;
	cin >> n;
	ll a[n];
	rep(i, 0, n) cin >> a[i];

	memset(dp, -1, sizeof(dp));

	cout << max_score(a, 0, n - 1);




}