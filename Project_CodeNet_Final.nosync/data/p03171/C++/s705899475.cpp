#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll dp[3010][3010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][i]=a[i];
    }
    for(ll len=2;len<=n;len++)
    {
        for(ll l=1;l<=n-len+1;l++)
        {
            ll r=l+len-1;
            dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }
    cout<<dp[1][n];
}