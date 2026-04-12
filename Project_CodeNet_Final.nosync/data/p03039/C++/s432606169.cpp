// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(a, b, c) make_tuple(a, b, c)
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define slice(l, r) substr(l, r-l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
    #include "lib/dump.hpp"
#else
    #define dump(...) 42
    #define dump_1d(...) 42
    #define dump_2d(...) 42
    #define cerrendl 42
#endif
//}}}

int mod = 1e9+7;
struct mint { //{{{
    int x;
    mint(int x=0):x((x%mod+mod)%mod){}

    // ?= operator
    mint& operator+=(const mint a) { (x += a.x) %= mod; return *this; }
    mint& operator-=(const mint a) { (x += mod-a.x) %= mod; return *this; }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint& operator/=(const mint&rhs){
        if (rhs.x==0) throw runtime_error("mint zero division");
        return *this*=rhs.inv(); 
    }

    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }

    mint pow(int n)const{
        mint res(1),x(*this);
        if (n<0){
            n = -n;
            x =(*this).inv();
        }
        while(n){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }

    mint inv() const{
        if (x==0) throw runtime_error("inv does not exist");
        return pow(mod-2);
    }
    // mint inv()const{
    //     int x,y;
    //     int g=extgcd(v,mod,x,y);
    //     assert(g==1);
    //     if(x<0)x+=mod;
    //     return mint(x);
    // }

    bool operator<(const mint&r)const{return x<r.x;}
    bool operator==(const mint&r)const{return x==r.x;}
};
istream& operator>>(istream& is, const mint& a) {return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) {return os << a.x;}
//}}}

struct combination {  // {{{
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
} // }}}
com(500001);

signed main() {
    int n,m,k;cin>>n>>m>>k;
    mint ans = 0;
    rep(d, 1, m){ ans += com(n*m-2, k-2) * d * (m-d) * n * n; }
    rep(d, 1, n){ ans += com(n*m-2, k-2) * d * (n-d) * m * m; }
    cout << ans << endl;

    return 0;
}
