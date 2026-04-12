#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll> 
#define pic pair<ll,char>
#define vi vector< ll > 
#define vvi vector< vi > 
#define vpi vector< pii > 
#define vvpi vector< vpi > 
#define st  set <ll, greater <ll> >
#define mst  multiset <ll, greater <ll> >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mapp  unordered_map <ll, ll>
#define ppii pair< pii, pii > 
#define test(t) ll t;cin>>t;while(t--)
#define inarr(n) ll arr[n];for(ll i=0;i<n;i++)cin>>arr[i];
#define ingra(m) vvi arr(100005);for(ll i=0;i<m;i++){ll u,v;cin>>u>>v;arr[u].pb(v);arr[v].pb(u);}
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}
ll dp[3001][3001];
ll arr[3001];
ll n;
ll func(ll i,ll j)
{
    if(i>j)
        return 0;
    ll &ret = dp[i][j];
    if(ret!=-1)
        return ret;
    if((n-(i+j))%2)
    {
        ret = max(arr[i]+func(i+1,j),arr[j]+func(i,j-1));
    }
    else
        ret = min(-arr[i]+func(i+1,j),-arr[j]+func(i,j-1));
    return ret;
}
signed main()
{
    fast;
    cin>>n;
    mem(dp,-1);
    ll i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<func(0,n-1);
}