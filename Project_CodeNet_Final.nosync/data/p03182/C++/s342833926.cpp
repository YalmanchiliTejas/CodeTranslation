//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize(3)
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target("sse3","sse2","sse")
//#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
//#pragma GCC target("f16c")
//#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
//#pragma GCC diagnostic error "-fwhole-program"
//#pragma GCC diagnostic error "-fcse-skip-blocks"
//#pragma GCC diagnostic error "-funsafe-loop-optimizations"
//#pragma GCC diagnostic error "-std=c++14"
#include "bits/stdc++.h"
//#include "ext/pb_ds/tree_policy.hpp"
//#include "ext/pb_ds/assoc_container.hpp"
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mst(x,a) memset(x,a,sizeof(x))
#define all(a) a.begin(),a.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define se second
#define fi first
#define sz(x) ((int)x.size())
#define EX0 exit(0);

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
typedef vector<ll> VLL;
typedef vector<int> VI;
const int block_size = 320;
typedef complex<ll> point;
const ll mod = 1e9+7;
const ll inf = 1e9+7;
const ld eps = 1e-9;
const db PI = atan(1)*4;
template<typename T>
inline int sign(const T&a) {
    if(a<0)return -1;
    if(a>0)return 1;
    return 0;
}
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) {}
#endif

template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}

template<typename T> inline void in(T &x) {
    x = 0;
    T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch))  {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

ll twop(int x) {
    return 1LL<<x;
}

// m must be positive
template<typename T>
T MOD(T a, T m){
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

// a must be relatively prime to m
template<typename T>
T inverse(T a, T m){
    a = MOD(a, m);
    if (a <= 1)
        return a;
    return MOD((1 - inverse(m, a) * m) / a, m);
}

template<typename A,typename B > inline void in(A&x,B&y) {
    in(x);
    in(y);
}
template<typename A,typename B,typename C>inline void in(A&x,B&y,C&z) {
    in(x);
    in(y);
    in(z);
}
template<typename A,typename B,typename C,typename D> inline void in(A&x,B&y,C&z,D&d) {
    in(x);
    in(y);
    in(z);
    in(d);
}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
namespace SOLVE {
    const ll maxn = 200010;
    ll dp[maxn],sum[maxn],n,m;
    struct SegTree{
        static const int maxn = 200010;
        
        struct node{
            int l,r;
            ll max,lazy;
            ll get_max(){
                return max+lazy;
            }
        };
        
        node no[maxn*4];
        void push_up(int ind){
            no[ind].max = max(no[lson].get_max(),no[rson].get_max());
        }
        void push_down(int ind){
            no[lson].lazy += no[ind].lazy;
            no[rson].lazy += no[ind].lazy;
            no[ind].lazy = 0;
        }
        void build(int l,int r,int ind){
            no[ind].l = l;
            no[ind].r = r;
            if(l == r){
                
            }else{
                int mid = (l+r)/2;
                build(l,mid,lson);
                build(mid+1,r,rson);
                push_up(ind);
            }
        }
        void update(int l,int r,int ind,ll val){
            if(l>no[ind].r || r<no[ind].l)return;
            if(l<=no[ind].l && no[ind].r <= r){
                no[ind].lazy += val;
            }else{
                push_down(ind);
                update(l,r,lson,val);
                update(l,r,rson,val);
                push_up(ind);
            }
        }
        void query(int l,int r,int ind,ll& ans){
            if(l>no[ind].r || r<no[ind].l)return;
            if(l<=no[ind].l && no[ind].r <= r){
                upmax(ans, no[ind].get_max());
            }else{
                push_down(ind);
                query(l,r,lson,ans);
                query(l,r,rson,ans);
                push_up(ind);
                
            }
        }
    };
    
    SegTree  tree;
    vector<pair<PLL, ll>> add[maxn];
    ll ans = 0;
    
    
    void main(){
        in(n,m);
        tree.build(0, n,1);
        REP(i,0,m){
            ll l,r,v;in(l,r,v);
            
            sum[l]+=v;
            sum[r+1]-=v;
            add[l].PB(MP(MP(l,r),-v));
            add[r+1].PB(MP(MP(l,r),+v));
        }
        REP(i,1,n+1)sum[i]+=sum[i-1];
        ll mx = 0;
        REP(i,1,n+1){
            //            dbg(i);
            while (sz(add[i])) {
                tree.update(add[i].back().fi.fi, add[i].back().fi.se, 1, add[i].back().se);
                //                dbg(add[i].back());
                add[i].pop_back();
            }
            ll ans = 0;
            tree.query(0, i-1, 1,ans);
            ans += sum[i];
            tree.update(i, i, 1, ans);
            upmax(SOLVE::ans, ans);
            //            dbg(ans);
        }
        
        cout<<ans<<endl;
        
        
        
        
        
        
        
        
        
        
        
        
    }
}


signed main() {
#ifndef ONLINE_JUDGE
#endif
    
    
    
    
    
    int t = 1;
    //    in(t);
    while(t--){
        SOLVE::main();
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
