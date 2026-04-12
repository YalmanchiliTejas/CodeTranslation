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
 
ll powmod(ll x, ll y) 
{ 
    ll res = 1;  
    x = x % MOD;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % MOD; 
        y = y>>1; // y = y/2 
        x = (x*x) % MOD;   
    } 
    return res; 
} 

int main()
{
    #if !ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,k;cin>>n>>k;
    ll cnt=0;
    
    for(int b=k+1;b<=n;b++){    
        cnt+=max(0ll,b-k);
        if(!k)cnt--;
        cnt+=(b-k)*((n-(b-1))/b);
        if((n-(b-1))%b)
            cnt+=max(((n-(b-1))%b)-k,0ll);
        
    }   
    cout<<cnt;  
}