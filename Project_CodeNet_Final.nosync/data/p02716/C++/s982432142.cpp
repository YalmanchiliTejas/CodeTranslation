#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 2147483647;
const ll LINF = 9223372036854775807;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main() {
	int n; cin >> n;
	VI a(n); REP(i,n) cin >> a[i];
	if(n%2==0){
		ll dp[n][2];
		REP(i,n)REP(j,2)dp[i][j]=-(LINF/2);
		REP(i,n){
			if(i<2){
				if(i==0) dp[i][0]=a[i];
				else dp[i][1]=a[i];
			}
			if(i>=2)
				dp[i][0]=dp[i-2][0]+a[i];
			if(i>=3)
				dp[i][1]=max(dp[i-3][0]+a[i],dp[i-2][1]+a[i]);
		}
		ll ans=-LINF;
		REP(i,2)ans=max(ans,dp[n-1-i][1-i]);
		cout << ans << endl;
	}
	else{
		ll dp[n][3];
		REP(i,n)REP(j,3)dp[i][j]=-(LINF/2);
		REP(i,n){
			if(i<3){
				if(i==0) dp[i][0]=a[i];
				else if(i==1) dp[i][1]=a[i];
				else if(i==2) dp[i][2]=a[i];
			}
			if(i>=2)
				dp[i][0]=dp[i-2][0]+a[i];
			if(i>=3){
				dp[i][1]=max(dp[i-3][0]+a[i],dp[i-2][1]+a[i]);
				dp[i][2]=max(dp[i-3][1]+a[i],dp[i-2][2]+a[i]);
			}
			if(i>=4)
				dp[i][2]=max(dp[i-4][0]+a[i],dp[i][2]);
		}
		ll ans=-LINF;
		REP(i,3)ans=max(ans,dp[n-1-i][2-i]);
		cout << ans << endl;
	}
	return 0;
}