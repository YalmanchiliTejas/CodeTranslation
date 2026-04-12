#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 3e3 + 5;
const ll LINF = 1e18 + 5;
int n, a[N];
ll dp[N][N];
ll solve(int x, int y)
{
	if(~dp[x][y]) return dp[x][y];
	ll &cur = dp[x][y];
	if(x==y) cur = a[x];
	else cur = max(-solve(x+1, y)+a[x], -solve(x, y-1)+a[y]);
	return cur;
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n;
 	for(int i=1; i<=n; i++) cin >> a[i];
 	memset(dp, -1, sizeof(dp));
 	cout << solve(1, n);
	return 0;
}
