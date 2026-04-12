#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    // Your code here!
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll dp[n][n];
    for(ll i=0;i<n;i++)
    {
        dp[i][i]=a[i];
    }
    for(ll i=0;i<n-1;i++)
    {
        dp[i][i+1]=max(a[i],a[i+1]);
    }
    for(ll len=3;len<=n;len++)
    {
        for(ll i=0;i<=n-len;i++)
        {
            ll j=i+len-1;
            ll q1=a[i]+min(dp[i+2][j],dp[i+1][j-1]);
            ll q2=a[j]+min(dp[i][j-2],dp[i+1][j-1]);
            dp[i][j]=max(q1,q2);
        }
    }
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=a[i];
    }
    cout<<2*dp[0][n-1]-sum;
    return 0;
}
