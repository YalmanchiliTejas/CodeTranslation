#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define   sz(s)         s.size()
#define   ll            long long int
#define   ull           unsigned ll
#define   ld            long double
#define   print(v)      for(ll i=0;i<v.size();i++)cout<<v[i]<<" "
#define   printpair(v)  for(ll i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<"\n"
#define   bmd           1000000007
#define   bmd1          998244353
#define   umll          unordered_map<ll,ll>
#define   mll           map<ll,ll>
#define   mcl           map<char,ll>
#define   pll           pair<ll,ll>
#define   F             first
#define   S             second
#define   setp(x)       setprecision(x)
#define   pb            push_back
#define   all(v)        v.begin(),v.end()
#define   tr(a)         for(auto it=a.begin();it!=a.end();it++)
#define   trr(a)        for(auto it1=a.begin();it1!=a.end();it1++)
#define   vll           vector<long long int>
#define   sorty(v)      sort(v.begin(),v.end())
#define   rsort(v)      sort(v.rbegin(),v.rend())
#define   unik(v)       v.erase(unique(all(v)),v.end())
#define   PI            3.1415926535897932384626
#define   db()          cout<<"\n"<<"here"<<"\n"
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


//---------------------------------------------------------------------------
const int MOD = bmd;
const int N=2e5+100;
inline  ll sqr(ll x){return x*x;}
inline  void normal(ll &a) { a = (a+MOD)%MOD; }
inline  ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline  ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline  ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline  ll modPow(ll b, ll p) { ll r = 1;b=b%MOD; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline  ll modInv(ll a) { return modPow(a, MOD-2); }
inline  ll modDiv(ll a,ll b) { return modMul(a, modInv(b)); }
//---------------------------------------------------------------------------
void solve()
{
    ll x;
    cin>>x;
    if(x>=30){
        cout <<"Yes"<<"\n";
    }
    else cout <<"No"<<"\n";
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);//first give all input then gives output
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
