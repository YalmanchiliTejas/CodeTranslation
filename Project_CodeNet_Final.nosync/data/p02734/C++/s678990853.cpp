#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
#define ll long long
#define pb push_back
#define fi first
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fit(x) for(auto it=x.begin();it!=x.end();++it)
#define se second
#define mp make_pair
#define ALL(x) x.begin(),x.end()
#define ALP "abcdefghijklmnopqrstuvwxyz"
#define nline cout<<"\n"
#define rep(i,x) for(i=0;i<x;++i)
#define repr(i,a,b) for(i=a;i<=b;++i)
#define PLL pair<ll,ll>
#define VLL vector<ll>
#define W(t) while(t--)
#define modmul(a,b,M) (a%M * b%M)%M
#define moddiv(a,b,M) (a%M * modinv(b,M)%M)%M
#define seperate cout<<"*****************\n";
const long long mi2= 500000004;
const long long mi3= 333333336;
const long double pi= 3.141592653589793238462643383279502;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_pset tree<PLL, null_type,less<PLL>, rb_tree_tag,tree_order_statistics_node_update>
int xcod[4]={-1,0,1,0};
int ycod[4]={0,1,0,-1};
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
struct HASH{
  size_t operator()(const pair<ll,ll>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
// unordered_map<pair<int,int>,int,HASH>mp;
// unordered_map<ll, ll, custom_hash> safe_map;
ll powermod(ll x,ll n,ll M)
{
    ll result=1;
    while(n>0)
    {
      if(n % 2 ==1)
        result=(result * x)%M;
      x=(x*x)%M;
      n=n/2;
    }
    return result;
}
vector<ll> readll() {
    cin>>ws;
    vector<ll> v;
    string input;
    getline(cin, input);
    cout<<input;
    istringstream is(input);
    ll num;
    while(is>>num) v.pb(num);
    return v;
}
/*
int BLOCK_SIZE;
inline bool mo_cmp(const pair< pair<int, int>, int> &x,const pair< pair<int, int>, int> &y)
{
    if ( (x.fi.fi/BLOCK_SIZE) != (y.fi.fi/BLOCK_SIZE) )
        return x < y ;
    return ((x.fi.fi/BLOCK_SIZE)&1)^(x.fi.se<y.fi.se) ;
}
*/
ll modinv(ll n,ll p) {
    return powermod(n,p-2,p);
}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll modsum(ll a,ll b,ll M) {
    ll x=a+b;
    if(x>=M)x-=M;
    return x;
}
ll modsub(ll a,ll b,ll M) {
    ll x=a-b;
    if(x<0)x+=M;
    return x;
}
/*ll fact[1000005],invf[1000005];
void facmod(ll n,ll M) {
    ll i;
    fact[0]=fact[1]=1;
    for(i=2;i<=n;++i) {
        fact[i]=((fact[i-1])%M * (i%M))%M;
    }
    invf[n]=modinv(fact[n],M);
    for (i=n-1;i>=0;--i){
        invf[i]=invf[i+1]*(i+1);
        invf[i]%=M;
    }
}
ll nCr(ll n,ll r,ll M) {
    ll x =modmul(fact[n],invf[n-r],M);
    return modmul(x,invf[r],M);
}*/
/*
ll T=0;
ll p[200005], d[200005];
ll tin[200005], tout[200005];
vector<ll> g[200005];
bool vis[200005];
void dfs(ll v,ll par=1,ll dep=0) {
    //dbg(v);
    tin[v] = T++;
    vis[v]=true;
    p[v] = par;
    d[v] = dep;
    for (auto to : g[v]) {
        if (vis[to]) continue;
        dfs(to,v,dep+1);
    }
    tout[v] = T++;
}
*/
// ll treeSet() {
//     ordered_set o_set;
//     o_set.insert(1); //for duplicate elements use pair and use second element unique
//     // find by order returns iterator of ith largest element;
//     cout<<*(o_set.find_by_order(1)) //second smallest element;
//     // Finding the number of elements 
//     // strictly less than k=4 
//     cout << o_set.order_of_key(4) ;
//     // Deleting 2 from the set if it exists 
//     if (o_set.find(2) != o_set.end()) 
//         o_set.erase(o_set.find(2));
// }
const long long MOD= 998244353; 
void solve() {
    ll n,m,i,j;
    cin>>n>>m;
    vector<ll> a(n+4);
    ll dp[n+4][m+4];
    memset(dp,0,sizeof dp);
    repr(i,1,n) {
        cin>>a[i];
    }
    ll ans=0;
    repr(i,1,n) {
        repr(j,1,m) {
            dp[i][j]=dp[i-1][j];
            if(a[i]<=j) {
                if(a[i]==j) {
                    dp[i][j]=modsum(dp[i][j],i,MOD);
                }
                dp[i][j]=modsum(dp[i][j],dp[i-1][j-a[i]],MOD);
            }
        }
        ans=modsum(ans,dp[i][m],MOD);
    }
    // repr(i,1,n) {
    //     repr(j,1,m) {
    //         printf("%2lld ",dp[i][j]);
    //         // cout<<dp[i][j]<<" ";
    //     }
    //     nline;
    // }
    cout<<ans;
}
int main() {
    // fastio;
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    ////freopen("output.txt","w",stdout);
    //#endif
    ll t=1;
    // cin>>t;
    W(t) {
        solve();
    }
    return 0;
}