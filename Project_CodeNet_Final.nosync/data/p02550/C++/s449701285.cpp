#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define pb(x) push_back(x)
#define vll vector<long long>
#define pll pair<long long, long long>
#define mll map<long long, long long>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define gcd __gcd
#define clr(x) memset(x, 0, sizeof(x))
#define mod 1000000007LL
#define mod2 998244353LL
#define INF 1e18
 

typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> o_tree;

long long power(long long x, long long y, long long p)
{
long long res = 1;


x = x % p;


while (y > 0)
{
if (y & 1)
res = (res*x) % p;


y = y>>1;
x = (x*x) % p;
}
return res;
}

void solve()
{
    ll n,x,m;
    cin>>n>>x>>m;
    ll res=0;
    vll pat;
    pat.pb(x);
    ll vis[m];
    vis[x]=0;
    clr(vis);
    ll patlen=-1;
    ll pats=-1,paten=-1;
    ll i;
    for(i=0;i<2*m;i++)
    {
        ll no = pat.back();
        ll now = power(no,2,m);
        if(vis[now])
        {
            patlen = sz(pat)-vis[now];
            pats = vis[now];
            paten = sz(pat);
        }
        else{
            vis[now]=sz(pat);
            pat.pb(now);
        }
    }
    vll fpat;
    for(i=pats;i<paten;i++)
    {
        fpat.pb(pat[i]);
    }
    ll nn = 0;
    for(i=0;i<min(n,pats);i++)
    {
        res+=pat[i];
        nn++;
    }
    ll fulrem = n-nn;
    ll sip = sz(fpat);
    ll nor = fulrem/sip;
    ll rem2 = fulrem%sip;
    ll sum=0;
    for(auto it:fpat)
    {
        sum+=it;
    } 
    res+=(nor)*sum;
    for(i=0;i<rem2;i++)
    {
        res+=fpat[i];
    }
    cout<<res<<"\n";



}



int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);


if (fopen("input.txt","r" ))
  {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
  }
cout<<setprecision(20);


ll t=1;


// cin>>t;


while(t--)
{
solve();
} 


return 0;
}