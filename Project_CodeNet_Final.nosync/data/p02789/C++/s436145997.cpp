#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace std;
using namespace __gnu_pbds;
 
 
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize
#define ini ll_MAX
#define inl LLONG_MAX
#define MOD 1000000007
#define sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define F0R(i, a) for (ll i = 0; i < (a); i++)
#define FORR(i, a, b) for (ll i = a; i >= (b); i--)
#define F0RR(i, a) for (ll i = a; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define pbds tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
 
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
 
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
 
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;
 
ll mod(ll a,ll b)
{
    return (b+a%b)%b;
}
 
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
ll po(ll a,ll b)
{
    ll ans = 1;
    while(b--)
        ans*=a;
    return ans;
}
ll pom(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    ll k = pom(a,b/2,mod);
    if(b%2==0)return (k*k)%mod;
    else return ((k*k)*mod*a)%mod;
}
 
ll sqdist(ll a,ll b,ll c,ll d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}
ll fact(ll n)
{
    if(n==0)return 1;
    ll ans = 1;
    FOR(i,1,n+1)ans*=i;
    return ans;
}

 
void solve()
{
 int n,m;cin>>n>>m;
 if(n==m)cout<<"Yes";
 else cout<<"No";
}
 
 
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    // ll t;
    //cout<<"Y"<<endl;
    //cin>>t;
    //while(t--)
        solve();
}