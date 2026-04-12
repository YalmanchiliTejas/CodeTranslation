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
    char s[10010];
    ll d;
    ll dp[10010][110];
    void main(){
        cin>>s>>d;
        int len = strlen(s);
        reverse(s,s+len);
        REP(i,0,len)s[i]-='0';
        s[len] = 0;
        ll sum = 0;
        ll ans = 0;
        REP(i,0,10){
            dp[0][i%d]++;
        }
        REP(i,0,len+5){
            REP(cur,0,d){
                REP(nxt_digit,0,10){
                    (dp[i+1][(cur+nxt_digit)%d]+=dp[i][cur])%=mod;
                }
            }
        }
        
        
        
        RREP(i,len-1,0){
            sum = sum  + s[i+1];
            sum %= d;
            if(i == 0){
                REP(j,0,s[i]+1){
                    if((sum+j)%d == 0)ans++;
                }
            }else{
                REP(j,0,s[i]){
                    ans += dp[i-1][MOD(-sum-j,d)];
                }
            }
        }
        cout<<MOD(ans-1,mod)<<endl;
        
        
        
        
        
        
        
        
        
        
        
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
