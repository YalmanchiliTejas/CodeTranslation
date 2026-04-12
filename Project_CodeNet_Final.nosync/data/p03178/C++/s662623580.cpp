#include <bits/stdc++.h>
#define read(n) scanf("%lld",&n)
#define write(x) printf("%lld\n",x)
#define F(i,n) for(int i = 0;i < n;i++)
#define ll long long
#define MX 10005
#define MOD 1000000007
#define INF 1000000009
#define set_dp(dp) memset(dp,-1,sizeof(dp))
using namespace std;
ll d, dp[MX][105][2];
string a;
ll solve(ll i, ll j, bool leq){
	if(j < 0) j += d;
	if(i == -1) return j == 0;
	if(dp[i][j][leq] == -1){
		ll ans = 0;
		if(leq){
			F(digit, a[i] - '0'){
				ans += (solve(i - 1, (j - digit) % d , 0));
				ans %= MOD;
			}
			ans += solve(i - 1, (j - (a[i] - '0')) % d, 1);
			ans %= MOD;
		}
		else{
			F(digit, 10){
				ans += (solve(i - 1, (j - digit) % d, 0));
				ans %= MOD;
			}
		}
		dp[i][j][leq] = ans;
	}
	return dp[i][j][leq];
}
int main(){

	cin>>a>>d;
	reverse(a.begin(), a.end());

	ll ans = 0, n = a.size();

	set_dp(dp);

	ans = solve(n - 1, 0, 1) - 1;
	ans = (ans + MOD) % MOD;

	write(ans);

	return 0;
}
