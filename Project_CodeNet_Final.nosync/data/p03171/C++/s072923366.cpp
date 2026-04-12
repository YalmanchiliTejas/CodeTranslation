#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fi first
#define se second
#define endl '\n'
#define mx 1e18
#define mod 998244353
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define pb push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll bino()
{
        vector<ll>inv(200005);vector<ll>fact(200005); vector<ll>inversef(200005);
    inv[0] = 1;inv[1]=1;
for(int i = 2; i < 200005; ++i)
    inv[i] = (inv[mod%i]*(mod-mod/i)) % mod;
    
    fact[0]=1;
    for(int i=1;i<200005;i++)
    fact[i]=(i*fact[i-1])%mod;
   
    inversef[0]=1;inversef[1]=1;
    for(int i=2;i<200005;i++)
    inversef[i]=(inversef[i-1]*inv[i])%mod;
}
ll powe(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return powe(((x%mod)*(x%mod))%mod,n/2);
    else                             //n is odd
        return ((x%mod*(powe(((x%mod)*(x%mod))%mod,(n-1)/2))%mod)%mod);
}
vector<vector<ll>>dp(3001,vector<ll>(3001,-1));

ll fun(int i,int j,vector<int>&a,int n)
{
    if(i==j)dp[i][j]=a[i];
 //   if(i>n-1)return 0;
 //   if(j<0)return 0;
   // else if(j==i+1)dp[i][j]= max(a[i],a[j]);
    
    if(dp[i][j]!=-1)return dp[i][j];
    else return dp[i][j]=max(a[i]-fun(i+1,j,a,n),a[j]-(fun(i,j-1,a,n)));
   
  //  else  return dp[i][j]= max(a[i]+min(dp[i+1][j-1],dp[i+2][j]),a[j]+min(dp[i][j-2],dp[i+1][j-1]));
    
}
int main()
{
   io
  int n;cin>>n;vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  cout<<fun(0,n-1,a,n);
}