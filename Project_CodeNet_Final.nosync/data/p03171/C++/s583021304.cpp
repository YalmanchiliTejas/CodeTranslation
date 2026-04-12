#include<bits/stdc++.h>

#define ll long long int
#define hell 1000000007
#define vi vector <ll>
#define pb push_back
#define pii pair<ll,ll>
#define vii vector <pii>
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define sep(i,a,b)  for(ll i=a-1;i>=b;i--)
#define inf (ll)(1e16)

using namespace std;

ll mi;

ll helper(vi &a,ll s,ll e,vector < vi > &dp)
{
    if(s>e)
        return dp[s][e]=0;
    if(s==e)
        return dp[s][e]=a[s];
    if(dp[s][e]!=-1)
        return dp[s][e];
    return dp[s][e]=max(a[s]-helper(a,s+1,e,dp),a[e]-helper(a,s,e-1,dp));
}

void solve()
{
    ll n;
    cin>>n;
    vi a(n);
    rep(i,0,n)
        cin>>a[i];
    vector < vi > dp(n+1,vi (n+1,-1));
    cout<<helper(a,0,n-1,dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
