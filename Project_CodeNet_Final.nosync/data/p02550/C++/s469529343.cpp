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
 
ordered_set<ll> ors;
 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
ld PI=3.14159265359;
 
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
 
ll lp[1000001];
vector<ll> pr;
 
void prime()
{
    repf(i,1,1000001) lp[i]=i;
    repf(i,2,1000001)
    {
        if(lp[i]==i)
        {
            for(ll j=2*i;j<1000001;j+=i)
            {
                if(lp[j]==j) lp[j]=i;
            }
        }
    }
    // repf(i,2,1000001) if(lp[i]==i) pr.pb(i);
}

const ll MX=200001;

vector<ll> v[MX];
ll depth[MX];
ll D[MX][22];
 
void dfs(ll x, ll p, ll h=0) {
    D[x][0]=p;
    depth[x]=h;
    repf(i,1,22)
    {
        if(D[x][i-1]!=-1 && D[D[x][i-1]][i-1]!=-1)
        {
            D[x][i]=D[D[x][i-1]][i-1];
        }
    }
    for(auto i:v[x]) {
        if(i==p) continue;
        dfs(i,x,h+1);
    }
}

ll walk(ll x, ll k)
{
    repf(i,0,22)
    {
        if((1<<i)&k)
        {
            x=D[x][i];
        }
    }
    return x;
}

ll lca(ll x, ll y)
{
    if(depth[x]>depth[y]) x=walk(x,depth[x]-depth[y]);
    if(depth[y]>depth[x]) y=walk(y,depth[y]-depth[x]);
    if(x==y) return x;
    repb(i,21,0)
    {
        if(D[x][i]!=D[y][i])
        {
            x=D[x][i];
            y=D[y][i];   
        }
    }
    return D[x][0];
}

void init() {
    prime();
}

void solve(ll tt) {
   ll n,x,m;
   cin>>n>>x>>m;
   bool vis[m]={false};
   vector<ll> v;
   ll sum=0;
   while(v.size()<n && !vis[x]) {
       v.pb(x);
       vis[x]=true;
       sum+=x;
       x=(x*x)%m;
   }
   ll ans=sum;
   ll sz=v.size();
   if(sz==n) {
       cout<<ans<<endl;
       return;
   }
   vector<ll> vtmp;
   sum=0;
   repf(i,0,sz) {
       if(v[i]==x) {
           repf(j,i,sz) sum+=v[j],vtmp.pb(v[j]);
           break;
       }
   }
//    cout<<sz<<endl;
   ll rem=n-sz;
   ll times=rem/vtmp.size();
   ll rr=rem%vtmp.size();
   ans+=sum*times;
   repf(i,0,rr) ans+=vtmp[i];
   cout<<ans<<endl;

} 
 
 
int main()
{
    // IOS;
    init();
    ll t=1;
    // cin>>t;
    repf(tt,1,t+1) {
        solve(tt);
    }
}     