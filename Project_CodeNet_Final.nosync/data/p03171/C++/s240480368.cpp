#include <bits/stdc++.h>
using namespace std;
#define ll          long long int
#define pb          push_back
#define pll         pair<ll,ll>
#define pq          priority_queue
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mod         1000000007
#define inf         INT_MAX
#define vl          vector<ll>
#define vvl         vector<vector<ll>>
#define F           first
#define S           second
#define db          double
#define sz(x)       (ll)x.size()
#define fix(n)      cout<<fixed<<setprecision(n)
#define rep(i,a,b)  for(ll i=a;i<b;i++)

const int N=3005;

ll n,a[N];
ll dp[N][N][2];

ll f(ll i,ll j,ll t)
{
    if(i>j) return 0;
    if(i==j) return (t==0)?a[i]:(-1*a[i]);
    if(dp[i][j][t]) return dp[i][j][t];
    if(t==0) dp[i][j][t]=max(a[i]+f(i+1,j,1),a[j]+f(i,j-1,1));
    else dp[i][j][t]=min(f(i+1,j,0)-a[i],f(i,j-1,0)-a[j]);
    return dp[i][j][t];
}


void solve()
{
    cin>>n;
    rep(i,1,n+1)cin>>a[i];
    ll ans=f(1,n,0);
    cout<<ans;
}

int main()
{
    ll T=1;
    //cin>>T;
    while(T--)
        solve();
    return 0;
}
