/*input
3
10 100 10
*/

//sometimes it's the people who no one imagines anything of 
//who do the things that no one can imagine.

//code author: iamxlr8

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 300005
#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() 
{
    off;
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
        cin>>v[i];
    ll dp[n][n];
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++)
        dp[i][i]=v[i];
    for(ll i=n-1;i>=0;i--)
    {
        for(ll j=i+1;j<n;j++)
            dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
    }
    cout<<dp[0][n-1];
    return 0;
}