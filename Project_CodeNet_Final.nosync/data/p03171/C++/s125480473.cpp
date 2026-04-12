#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define f(i, a, b) for(ll i=a;i<b;i++)
#define fi(i, a, b) for(ll i=b-1;i>=a;i--)
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define ml map<ll,ll> 

void solve()
{
   ll n;
   cin>>n;
   ll a[n];
   f(i,0,n)cin>>a[i];
   ll dp[n+1][n+1];
   f(i,0,n+1)
   dp[i][0]=0,dp[0][i]=0;

   f(i,1,n+1)
   {
      dp[i][i] = a[i-1];
   }
   f(i,1,n)
   dp[i][i+1] = abs(a[i-1]-a[i]);
   fi(i,1,n-1)
   {
         f(j,i+2,n+1)
      {
         dp[i][j] = max(min(dp[i+2][j]+a[i-1]-a[i],dp[i+1][j-1]+a[i-1]-a[j-1]),min(dp[i+1][j-1]+a[j-1]-a[i-1],dp[i][j-2]+a[j-1]-a[j-2]));
      }
   }
   cout<<dp[1][n];
}

int main()
{
   ll t;
   t=1;
//    cin>>t;
   while (t--)
   {
       solve();
   }  
}