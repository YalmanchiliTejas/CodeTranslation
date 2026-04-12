#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<ll> v(n+2);
	rep(i,0,n)cin >> v[i];
	const ll inf = 1e17;
	vector<vector<ll>> dp(n+3, vector<ll>(3,-inf));
	dp[0][0] = v[0];
	dp[1][1] = v[1];
	dp[2][2] = v[2];
	rep(i,0,n){
		rep(j,0,3){
			gmax(dp[i+2][j], dp[i][j] + v[i+2]);
			if(j < 2 && i+3 < n){
				gmax(dp[i+3][j+1], dp[i][j] + v[i+3]);
			}
			if(j == 0 && i + 4 < n){
				gmax(dp[i+4][j+2], dp[i][j] + v[i+4]);
			}
		}
	}
	ll ans = -inf;
	if(n&1)gmax(ans, max(dp[n-1][2],max(dp[n-2][1], dp[n-3][0])));
	else gmax(ans, max(dp[n-1][1], dp[n-2][0]));
	cout << ans << '\n';
}
