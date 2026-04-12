#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define MOD 998244353 

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<ll> dp;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll power(ll a, ll n, ll m)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans=(ans*a)%m;
        n>>=1;
        a=(a*a)%m;
    }
    return ans;
}

ll invmod(ll a, ll m)
{
    return power(a,m-2,m);
}

void solve()
{
    ll n;
    cin>>n;
    ll a[n+1];
    repf(i,1,n+1) cin>>a[i];
    ll dp[n+1][2];
    repf(i,1,n+1) dp[i][0]=dp[i][1]=-1e18;
    dp[1][0]=dp[1][1]=0;
    dp[2][1]=a[2],dp[2][0]=a[1];
    repf(i,3,n+1)
    {
        if(i&1) 
        {
            dp[i][1]=a[i]+max(dp[i-2][1],dp[i-2][0]);
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
        }
        else
        {
            dp[i][1]=a[i]+dp[i-1][0];
            dp[i][0]=a[i-1]+dp[i-2][0];
        }
        // cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
}

int main()
{
    IOS;
    ll t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}     
