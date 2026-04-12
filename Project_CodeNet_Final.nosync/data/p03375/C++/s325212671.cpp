#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

#if !ONLINE_JUDGE
#define debug
#endif

using namespace std;
 
/*******  All Required define Pre-Processors and typedef Constants *******/
#define mem(a, b) memset(a, (b), sizeof(a))
#define repd(i,k) for(int i=k;i>=0;i--)
#define rep(i,k) for(int i=0;i<k;i++)
#define repn(i,k1,k2) for(ll i=k1;i<k2;i++)
#define sz(x) (ll)(x).size()
#define ff first
#define ss second

#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ee6 (ll)1000001
#define ee5 (ll)100001

#define trav(a, v) for(auto& a : v)

#define tt ll t;cin>>t; while(t--)
typedef long long int ll;
 
typedef pair<ll, ll> pr;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<pr> vpr;
typedef vector<vpr>vvpr;
typedef vector<vi> vvi;

//*X.find_by_order(2) element at index=2
//X.order_of_key(1) how many elements strictly less than 1

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

#ifdef debug
#define dbg(...) { cerr<<"[ "; dump(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.ff<<","<<x.ss<<")";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const unordered_map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
} 
 
template <typename Arg1>
void dump(const string name, Arg1&& arg1){
    cerr << name << " : " << arg1 << " ] " << endl;
}
 
template <typename Arg1, typename... Args>
void dump(const string names, Arg1&& arg1, Args&&... args){
    const string name = names.substr(0,names.find(','));
    cerr<<name<<" : "<<arg1<<" | ";
    dump(names.substr(1+(int)name.size()), args...);
}
#else
    #define dbg(args...)
#endif
 
ll powmod(ll x, ll y,ll m=MOD) 
{ 
    ll res = 1;  
    x = x % m;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % m; 
        y = y>>1; // y = y/2 
        x = (x*x) % m;   
    } 
    return res; 
} 
const int N=ee5;
ll m;
ll fact[N],inv[N],invfact[N];
void pre2()
{
    fact[0]=1;
    for(ll i=1;i<N;i++)
        fact[i]=(fact[i-1]*i)%m;
    //calculate inverses of [1,N] mod p
    inv[1]=1;
    for(ll i=2;i<N;i++)inv[i]=inv[m%i]*(m-m/i)%m;

    invfact[0]=1;
    for(ll i=1;i<N;i++)invfact[i]=(invfact[i-1]*inv[i])%m;
}
 
ll ncr(ll n,ll r)
{
    if(r>n)return 0;
    if(n==r)return 1;
    if(n<0 or r<0)return 0;
    return fact[n]*invfact[r]%m*invfact[n-r]%m;
}

ll stir2[3005][3005];
ll powe[3005*3005];
ll powm[3005*3005];
int main()
{
    #if !ONLINE_JUDGE
   // freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;cin>>n>>m;
    pre2();
    /*
    stir[0][0]=1;
    for(ll n=1;n<=2004;n++){
        for(ll k=1;k<=n;k++){
            stir[n][k]=stir[n-1][k-1]+k*stir[n-1][k];
        }
    }*/
    stir2[0][0]=1;
    for(ll n=0;n<=3004;n++){
        for(ll k=0;k<=n;k++){
            if(!(n|k)){stir2[n][k]=1;continue;}
            //dbg(n,k,((n and k)?stir2[n-1][k-1]:0),k*(n?stir2[n-1][k]:0),(n?stir2[n-1][k]:0));
            stir2[n][k]=(((n&&k)?stir2[n-1][k-1]:0)+k*(n?stir2[n-1][k]:0)+(n?stir2[n-1][k]:0))%m;               
        }
    }

    powe[0]=1;
    for(int i=1;i<=3000*3000;i++)
        powe[i]=(powe[i-1]<<1)%m;

    powm[0]=1;
    for(int i=1;i<=3000*3000;i++)
        powm[i]=(powm[i-1]<<1)%(m-1);

    ll ans=0;
    for(ll x=0;x<=n;x++){
        //x create problems;
        ll ways=0;        
        for(ll j=0;j<=x;j++){
            //j subsets cover the x
            ways=(ways+stir2[x][j]*powe[(n-x)*j]%m*powmod(2,powm[n-x],m)%m)%m;
            //ways=(ways+stir2[x][j]*powmod(2,(n-x)*j,m)%m*powmod(2,powmod(2,n-x,m-1),m)%m)%m;
        }
        
        if(x%2)
            ans=(ans-ncr(n,x)*ways)%m;
        else ans=(ans+ncr(n,x)*ways)%m;
        ans=(ans+m)%m;
    }

    cout<<ans;
}