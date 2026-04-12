#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll max(ll a,ll b)
{
    return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
ll n;
vector<ll> arr;
int main()
{
    cin>>n;
    arr.resize(n);
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    if(n==1)
    cout<<arr[0];
    else
    {
        //dp[i][j] means -> max that a player score if we consider values from index i to j (inclusive)
        vector<vector<ll> > dp(n,vector<ll> (n,0));
        for(ll i=0;i<n;i++)
        {
            dp[i][i]=arr[i];
            if(i==n-1)
            continue;
            dp[i][i+1]=max(arr[i],arr[i+1]);
        }
        for(ll i=n-3;i>=0;i--)
        {
            for(ll j=i+2;j<n;j++)
            {
            dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
            }
        }
        /*for(ll i=0;i<n;i++)
        {
        for(ll j=0;j<n;j++)
        cout<<dp[i][j]<<" ";
        cout<<"\n";
        }*/
        ll a = min(dp[1][n-1],dp[0][n-2]);
        cout<<(dp[0][n-1]-a);
    }
    return 0;
}