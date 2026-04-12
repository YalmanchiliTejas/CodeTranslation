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
ll n,dp[3005][3005];
ll a[3005];
ll fun(ll i,ll j,ll k){
	if(i==j&&k==1)return a[i];
	if(i==j&&k==0)return -a[i];
	if(dp[i][j]!=-1)return dp[i][j];
	if(k){
		dp[i][j]=max(fun(i+1,j,1-k)+a[i],fun(i,j-1,1-k)+a[j]);
		return dp[i][j];
	}
	else{
		dp[i][j]=min(fun(i+1,j,1-k)-a[i],fun(i,j-1,1-k)-a[j]);
		return dp[i][j];		
	}
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<fun(1,n,1)<<endl;
}