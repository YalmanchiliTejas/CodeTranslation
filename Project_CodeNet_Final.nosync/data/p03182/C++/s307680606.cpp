////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include <boost/rational.hpp>
*/
//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define _GLIBCXX_DEBUG
#define rep(i,t) for (ll i = (ll)(0); i < (ll)(t); i++)
#define rep2(i,s,t) for (ll i = (ll)(s); i < (ll)(t); i++)
#define rep3(i,t) for (ll i = (ll)(1); i <= (ll)(t); i++)
#define rep4(i,s,t) for (ll i = (ll)(s); i <= (ll)(t); i++)
#define repr(i,t) for (ll i = (t-1); i>=(0);i--)
#define repr2(i,s,t) for (ll i = (t-1); i>=(s);i--)
#define repr3(i,t) for (ll i = (t); i>=(1);i--)
#define repr4(i,s,t) for (ll i = (t); i>=(s);i--)
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pcc =pair<char,char>;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using tuplis = array<ll,3>;
template<class T> using pq = priority_queue<T,vector<T>,greater<T>>;
const ll LINF = 1e18;
const ll MINF = 1e15;
const int INF = 1e9+1e5;
const int mod=1000000007;
//const int mod=998244353;



const ld DINF = numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=acos(-1);
//const ll dx[] ={0,1,0,-1,1,-1,1,-1};
//const ll dy[] ={1,0,-1,0,1,1,-1,-1};
bool ingrid(const int i,const int j,const int H,const int W){return i>=0&&i<H&&j>=0&&j<W;}
const ll dx[] ={0,1,0,-1};
const ll dy[] ={1,0,-1,0};
bool is_low(char c){ return('a'<=c)&&(c<='z');}
bool is_upp (char c) {return('A'<=c)&&(c<='Z');}
#define each1(i,a) for(auto&& i:a)
#define each2(x,y,a) for(auto&& [x,y]:a)
#define each3(x,y,z,a) for(auto&& [x,y,z]:a)
#define rrep(n) for(ll i=(n);i--;)
#define stlen(s) ll s.size()-1
#define all(v) begin(v), end(v)
#define range(v,a) begin(v),begin(v)+a
#define range2(v,a,b) begin(v)+a,begin(v)+b
#define range3(v,a) begin(v)+1,begin(v)+a+1
#define range4(v,a,b) begin(v)+a+1,begin(v)+b+1
#define allr(v) rbegin(v), v.rend(v)
#define ranger(v,a) rbegin(v),rbegin(v)+a
#define ranger2(v,a,b) rbegin(v)+a,rbegin(v)+b
#define ranger3(v,a) rbegin(v)+1,rbegin(v)+a+1
#define ranger4(v,a,b) rbegin(v)+a+1,rbegin(v)+b+1
#define cout(n) cout<<std::fixed<<std::setprecision(n)
//#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a)); a.erase(unique(all(a)),end(a));
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size); in(name)
#define vv(type,name,h,...) vector<vector<type>> name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>> name(h,vector<type>(w)); in(name)
template<class T> inline const auto min(const T& a){ return *min_element(all(a));}
template<class T> inline const auto max(const T& a){ return *max_element(all(a));}
inline const ll popcnt(const ull a){return __builtin_popcountll(a);}
inline const ll gcd(ll a,ll b){while(b){ll c=b; b=a%b;a=c;}return a;}
inline const ll lcm(ll a,ll b){unless(a&&b) return 0;return a*b/gcd(a,b);}
inline const ll intpow(ll a,ll b){ll ans=1; while(b){if(b&1)ans*=a;a *=a; b/=2;}return ans;}
//inline const ll modpow(ll a,ll b, ll p=mod){ll ans=1; while(b){if(b&1)(ans*=a)%=p;(a*=a)%=p;b/=2;}return ans;}
template<class T,class U>inline const bool chmin(T& a,const U& b){if(a>b){a=b;return 1;}return 0;}
template<class T,class U>inline const bool chmax( T& a,const U& b){if(a<b){a=b;return 1;}return 0;}
inline const vector<ll> iota(const ll n){vector<ll> a(n); iota(all(a),0);return a;}
inline const vector<pll> factor(ull x){vector<pll> ans; for(ull i=2;i*i<=x;i++)if(x%i==0){ans.push_back({i,1});while((x/=i)%i==0)ans.back().second++;}if(x!=1)ans.push_back({x,1});return ans;}
inline const map<ll,ll> factor_map(ull x){map<ll,ll> ans; for(ull i=2; i*i<=x;i++)if(x%i==0){ans[i]=1;while((x/=i)%i==0)ans[i]++;}if(x!=1)ans[x]=1;return ans;}
inline const vector<ll> divisor(ull x){vector<ll> ans; for(ull i=2;i*i<=x;i++)if(x%i==0)ans.push_back(i);rrep(ans.size()-(ans.back()*ans.back()==x))ans.push_back(x/ans[i]);return ans;}
inline const int scan() {return getchar();}
inline const void scan(int &a){scanf("%d", &a);}
inline const void scan(unsigned& a){scanf("%u",&a);}
inline const void scan(long& a){scanf("%ld",&a);}
inline const void scan(long long& a){scanf("%lld", &a);}
inline const void scan(char& a){ do{a=getchar();}while(a==' '||a=='\n');}
inline const void scan(float& a){ scanf("%f",&a);}
inline const void scan(double& a){ scanf("%lf",&a);}
inline const void scan(long double& a){ scanf("%Lf",&a);}
inline const void scan( string& a){cin>> a;}
template<class T>inline const void scan( vector<T>& a){for(auto&& i:a)scan(i);}
template<class T,size_t size>inline const void scan(array<T, size>& a){for(auto&& i:a)scan(i);}
template<class T,class L>inline const void scan( pair<T,L>&p){scan(p.first);scan(p.second);}
template<class T,size_t size>inline const void scan( T (&a)[size]){ for(auto&& i:a)scan(i);}
inline const void in(){}
template <class Head,class... Tail>inline const void in( Head& head, Tail&... tail){scan(head);in(tail...);}
inline const int ctoi(const char c){if(c>='a'&&c<='z'){return c-'a';} if(c>='A'&&c<='Z'){return c-'A';}if(c>='0'&&c<='9'){return c-'0';}return -1;}
inline const void print(){putchar(' ');}
inline const void print(const bool a){printf("%d", a);}
inline const void print(const int a){printf("%d",a);}
inline const void print(const unsigned a){ printf("%u",a);}
inline const void print(const long a){printf("%ld",a);}
inline const void print(const unsigned long long a){printf("%llu",a);}
inline const void print(const char a){ printf("%c",a);}
inline const void print(const double a){printf("%.15f",a);}
inline const void print(const long double a){printf("%.15Lf",a);}
inline const void print(const string&a){for(auto&&i :a)print(i);}
template<class T> inline const void print(const vector<T> &a){if(a.empty())return ;print(a[0]);for(auto i=a.begin();++i!=a.end();){putchar(' ');print(*i);}}
template<class T> inline const void print(const deque<T>&a ){if(a.empty())return;print(a[0]);for(auto i=a.begin(); ++i!=a.end();){putchar(' ');print(*i);}}
template<class T, size_t size>inline const void print(const T (&a)[size]){print(a[0]);for(auto i=a;++i!=end(a);){putchar(' ');print(*i);}}
template<class T>inline const void print(const T& a){cout<<a;}
inline const int out(){putchar('\n');return 0;}
template<class T> inline const int out(const T& t){print(t);putchar('\n');return 0;}
template<class Head,class... Tail>inline const int out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);return 0;}
inline const int first(const bool i){return out(i?"first":"second");}
inline const int yes(const bool i){return out(i?"yes":"no");}
inline const int Yes(const bool i){return out(i?"Yes":"No");}
inline const int YES(const bool i){return out(i?"YES":"NO");}
inline const int possible(const bool i){return out(i?"possible":"impossible");}
inline const int Possible(const bool i){return out(i?"Possible":"Impossible");}
inline const int POSSIBLE(const bool i){return out(i?"POSSIBLE":"IMPOSSIBLE");}

 
using Graph = vector<vector<int>>;
using Graphw = vector<vector<pair<ll,int>>>;
using mat = vector<vector<ll>>;
using vec = vector<ll>;


/*
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部長が32の浮動小数点数型
using Real32 = mp::number<mp::cpp_dec_float<32>>;
// 仮数部長が1024の浮動小数点数型
using Real1024 = mp::number<mp::cpp_dec_float<1024>>;
// 有理数型
using Rat = boost::rational<Bint>;
*/

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

//lazySegtree
}  // namespace internal

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

struct S{
    ll v;
    int size;

};
struct F{
    ll a;
};
S op(S a,S b){
    return {max(a.v,b.v),a.size+b.size};
}
S e(){return {-LINF,0};}
S mapping(F f,S x){
    return {x.v+f.a,x.size};
}
F composition(F f,F g){
    return F{f.a+g.a};
}
F id(){return F{0};}


signed main(){

INT(N,M);
vector<vector<pair<int,ll>>> list(N);
rep(i,M){
    INT(l,r,a);
    l--;r--;
    list[r].push_back(mp(l,a));
}
vector<S> a(N,S{0,1});
lazy_segtree<S,op,e,F,mapping,composition,id> dp(a);
rep(r,N){
    if(r){
        ll max_=max(dp.prod(0,r).v,0LL);
        
        dp.set(r,S{max_,1});
        for(auto p:list[r]){
            int l=p.first;
            ll val=p.second;
            dp.apply(l,r+1,F{val});
        }

    }
    else{
        for(auto p:list[r]){
            int l=p.first;
            ll val=p.second;
            dp.apply(l,r+1,F{val});

        }
    }
}
ll ans=max(dp.prod(0,N).v,0LL);
out(ans);
//rep(i,N)out(dp.get(i).v);

}
