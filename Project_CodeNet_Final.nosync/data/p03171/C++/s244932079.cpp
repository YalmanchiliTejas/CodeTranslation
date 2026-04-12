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
ll n,a[3005],dp[3005][3005][2]={0},vis[3005][3005][2]={0};
ll fun(ll i,ll j,ll k){
	if(vis[i][j][k])return dp[i][j][k];
	vis[i][j][k]=1;
	if(k==1&&i==j){
		dp[i][j][k]=a[i];
		return a[i];
	}
	else if(k==0&&i==j){
		dp[i][j][k]=-a[i];
		return -a[i];
	}
	if(k){
		dp[i][j][k]=max(fun(i+1,j,0)+a[i],fun(i,j-1,0)+a[j]);
	}
	else{
		dp[i][j][k]=min(fun(i+1,j,1)-a[i],fun(i,j-1,1)-a[j]);
	}
	return dp[i][j][k];
}
int main(){
	cin>>n;
	for(ll i=0;i<n;i++)cin>>a[i];
	cout<<fun(0,n-1,1);
}