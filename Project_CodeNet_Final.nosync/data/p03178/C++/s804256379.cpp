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
ll dp[10005][2][100];
ll d;
string k;
ll func(ll n,ll tight,ll rem)
{
    if(n==k.length())
    {
        if(rem==0)
            return 1;
        return 0;
    }
    ll &ret = dp[n][tight][rem];
    if(ret!=-1)
        return ret;
    ll mi = 9;
    if(tight)
        mi = k[n]-'0';
    ll i;
    ret = 0;
    for(i=0;i<=mi;i++)
    {
        ll ntight = tight&(i==(k[n]-'0'));
        ret = (ret + func(n+1,ntight,(rem+i)%d))%mod;
    }
    return ret;
}
signed main()
{
    fast;
    cin>>k>>d;
    mem(dp,-1);
    cout<<(func(0,1,0)+mod-1)%mod;
}