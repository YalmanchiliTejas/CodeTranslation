#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod = 1e9+7;
const ll nax = 3e3+7;
const ll INF = 1e18;

ll n,a[nax];
ll dp[nax][nax][2];

int main(){
//	freopen("input.inp","r",stdin);
//	freopen("output.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	
	for (ll i=0;i<n;++i) cin>>a[i];
	
	for (ll l=n-1;l>=0;--l){
		for (ll r=l;r<n;++r){
			if (l==r){
				dp[l][r][0]=a[l];
				dp[l][r][1]=-a[l];
			}
			
			else {
				dp[l][r][0]=max(dp[l+1][r][1]+a[l],dp[l][r-1][1]+a[r]);
				dp[l][r][1]=min(dp[l+1][r][0]-a[l],dp[l][r-1][0]-a[r]);
			}
		}
	}
	
	cout<<dp[0][n-1][0]<<"\n";
}