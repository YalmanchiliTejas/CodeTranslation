#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
const ll MAX=1e5+5;
const ll INF=1e15+2;

#define pb push_back
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pi pair<ll,ll>

ll dp[3001][3001];
ll a[3001];

ll calc(ll l,ll r)
{
    if(dp[l][r]!=-1)
        return dp[l][r];
        
    if(l==r)
    {
        dp[l][r]=a[l];
        return dp[l][r];
    }
    
    ll a1=a[l]-calc(l+1,r);
    ll a2=a[r]-calc(l,r-1);
    
    dp[l][r]=max(a1,a2);
    return dp[l][r];
}

int main()
{
    ll n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    
    for(int i=1;i<=n;i++)
        cin>>a[i];
        
    ll val=calc(1,n);
    
    cout<<dp[1][n];    
}