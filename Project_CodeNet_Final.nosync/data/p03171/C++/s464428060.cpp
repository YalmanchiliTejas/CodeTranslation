#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
ll solve(ll a[],ll i,ll j,ll dp[][3005])
{
   if(i>j)
   return 0;
   if(dp[i][j]!=-1)
   return dp[i][j];
   ll op1=a[i]+min(solve(a,i+2,j,dp),solve(a,i+1,j-1,dp));
   ll op2=a[j]+min(solve(a,i+1,j-1,dp),solve(a,i,j-2,dp));
   dp[i][j]=max(op1,op2);
   return dp[i][j];
}
int main() {
    ll n;
    cin>>n;
    ll a[3005],i,s=0;
    for(i=0;i<n;i++){
    cin>>a[i];
    s+=a[i];}
    ll dp[n+5][3005];
    memset(dp,-1,sizeof(dp));
    ll y=solve(a,0,n-1,dp);
    ll w=s-y;
    cout<<(y-w)<<"\n";
	return 0;
}