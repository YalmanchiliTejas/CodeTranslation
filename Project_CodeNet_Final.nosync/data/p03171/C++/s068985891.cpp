//** aman**/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define dl          double
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define lb lower_bound
#define ub upper_bound
#define bs          binary_search
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int main(){
	ll n;cin>>n;
	ll a[n+1];
	for(ll i=1;i<=n;i++)cin>>a[i];
	ll dp[n+1][n+1]={0};
	for(ll i=1;i<=n;i++){
		if(n%2==1)
		dp[i][i]=a[i];
		else 
		dp[i][i]=-a[i];
	}
	for(ll i=n;i>=1;i--){
		for(ll j=i+1;j<=n;j++){
			if(n%2==(j-i+1)%2)
			dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
			else
			dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);			
		}
	}
	cout<<dp[1][n]<<endl;
}