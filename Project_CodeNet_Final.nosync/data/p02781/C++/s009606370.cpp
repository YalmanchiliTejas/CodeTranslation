#include <bits/stdc++.h>
#define read(n) scanf("%lld",&n)
#define write(x) printf("%lld\n",x)
#define F(i,n) for(int i = 0;i < n;i++)
#define ll long long
#define MX 105
#define MOD 1000000007
#define INF 1000000009
#define set_dp(dp) memset(dp,-1,sizeof(dp))
using namespace std;
ll n, k, a[MX], dp[MX][4], dp_ncr[MX][4];
char s[MX];
ll ncr(ll i, ll j){
	if(j > i) return 0;
	if(j == 0) return 1;
	if(dp_ncr[i][j] == -1)
		dp_ncr[i][j] = ncr(i - 1, j) + ncr(i - 1, j - 1);
	return dp_ncr[i][j];
}
ll solve(ll i, ll j){
	if(j < 0) return 0;
	if(i == -1) return j == 0;
	if(dp[i][j] == -1){
		ll ans = 0;

		if(a[i]){
			// place a zero
			ans += pow(9, j) * ncr(i, j);
			// place a non zero digit less than a[i]
			ans += (a[i] - 1) * (ll)pow(9, j - 1) * ncr(i, j - 1);
			// place a[i]
			ans += solve(i - 1, j - 1);
		}
		else{
			// place a zero
			ans += solve(i - 1, j);
		} 
			

		dp[i][j] = ans;

	}
	return dp[i][j];
}
int main(){

	set_dp(dp), set_dp(dp_ncr);

	scanf("%s", s);
	n = strlen(s);

	F(i, n) a[n - i - 1] = s[i] - '0';

	read(k);

	write(solve(n - 1, k));


	return 0;
}
