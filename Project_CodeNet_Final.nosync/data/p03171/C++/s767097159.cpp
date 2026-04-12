#include <bits/stdc++.h>
using namespace std;
/* * * *   * * *   	* * * */
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define ms(a,v) memset(a,v,sizeof a)
/* * * *   * * *   	* * * */
/* *
 *
 * Author: Hamkor a.k.a. OakenSh1eld
 *
 * */
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	ll dp[n+1][n+1][2], a[n];
	ms(dp, 0);
	for(int i=0; i<n; ++i) {
		cin>>a[i];
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	for(int l = n-1; l>=0; --l) for(int r=l+1; r<n; ++r){
		dp[l][r][0] = max(dp[l+1][r][1] + a[l], dp[l][r-1][1] + a[r]);
		dp[l][r][1] = min(dp[l+1][r][0] - a[l], dp[l][r-1][0] - a[r]);
	}
	cout<<dp[0][n-1][0];
	return 0;
}
