#include<bits/stdc++.h>
using namespace std;


// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
#define ll long long
 
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl
 
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
 
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
ll n;
ll dp[3005][3005];
ll ar[3005];
#define INF 1000000000000000000
ll fun(ll a,ll b,ll c)
{
    if(a==b)
    {
        if(c)
        return dp[a][b]=ar[a];
        else
        return dp[a][b]=-ar[a];
    }
    if(dp[a][b]!=-INF)
    {
        return dp[a][b];
    }
    if(c)
    {
        // debug("Ads");
        // debug(a);
        // debug(b);
        return dp[a][b]=max(ar[a]+fun(a+1,b,0),ar[b]+fun(a,b-1,0));
    }
    else
    {
        // debug(a);
        // debug(b);
        return dp[a][b]=min(-ar[a]+fun(a+1,b,1),-ar[b]+fun(a,b-1,1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(11);
    
    long double pi= 3.14159265358979323846;

    cin>>n;
    rep(i,3005)
    {
        rep(j,3005)
        dp[i][j]=-INF;
    }
    rep(i,n)
    {
        cin>>ar[i];
    }
    cout<<fun(0,n-1,1)<<endl;
    
    return 0;
}