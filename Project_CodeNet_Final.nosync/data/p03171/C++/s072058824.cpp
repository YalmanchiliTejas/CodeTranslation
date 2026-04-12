#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[3000+1];
ll dp[3000+1][3000+1];

ll ans(ll f,ll l,ll n)
{
   if(dp[f][l]!=-1)
   return dp[f][l];
   
   if(f==l)
   {
       if(n%2==0)
       dp[f][l]=-a[f];
       
       else
       dp[f][l]=a[f];
       
       return dp[f][l];
   }
   
   ll x=f-l+1;
   
   if((n%2==0)&&(x%2==0))
   dp[f][l]=max(ans(f+1,l,n)+a[f],ans(f,l-1,n)+a[l]);
   
   else if((n%2==0)&&(x%2!=0))
   dp[f][l]=min(ans(f+1,l,n)-a[f],ans(f,l-1,n)-a[l]);
   
   else if((n%2!=0)&&(x%2==0))
   dp[f][l]=min(ans(f+1,l,n)-a[f],ans(f,l-1,n)-a[l]);
   
   else if((n%2!=0)&&(x%2!=0))
   dp[f][l]=max(ans(f+1,l,n)+a[f],ans(f,l-1,n)+a[l]);
   
   return dp[f][l];
}
int main()
{
    ll n;
    cin>>n;
    
    for(ll i=0;i<=3000;i++)
    {
        for(ll j=0;j<=3000;j++)
        dp[i][j]=-1;
    }

    
    for(ll i=0;i<n;i++)
    cin>>a[i];
    
    cout<<ans(0,n-1,n)<<endl;
    
    
}