#line 2 "cpplib/util/template.hpp"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#include<bits/stdc++.h>
using namespace std;
struct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;
typedef long long lint;
#define INF (1LL<<60)
#define IINF (1<<30)
#define EPS (1e-10)
#define endl ('\n')
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
template<typename T>inline void numout(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i<INF/2?i:"INF";f=1;}cout<<endl;}
template<typename T>inline void numout2(T t){for(auto i:t)numout(i);}
template<typename T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}
template<typename T>inline void output2(T t){for(auto i:t)output(i);}
template<typename T>inline void _output(T t){bool f=0;for(lint i=0;i<t.size();i++){cout<<f?"":" "<<t[i];f=1;}cout<<endl;}
template<typename T>inline void _output2(T t){for(lint i=0;i<t.size();i++)output(t[i]);}
#define rep(i,...) for(auto i:range(__VA_ARGS__)) 
#define rrep(i,...) for(auto i:reversed(range(__VA_ARGS__)))
#define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)
#define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)
#define irep(i) for(lint i=0;;++i)
inline vector<long long> range(long long n){if(n<=0)return vector<long long>();vector<long long>v(n);iota(v.begin(),v.end(),0LL);return v;}
inline vector<long long> range(long long a,long long b){if(b<=a)return vector<long long>();vector<long long>v(b-a);iota(v.begin(),v.end(),a);return v;}
inline vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return v;}
template<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return v;}
#define all(n) begin(n),end(n)
template<typename T,typename E>bool chmin(T& s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}
template<typename T,typename E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
#line 5 "cpplib/graph_tree/graph_template.hpp"
/**
 * @brief グラフテンプレート
 */

using graph=std::vector<std::vector<int>>;
template<typename T>
using graph_w=std::vector<std::vector<std::pair<int,T>>>;

graph load_graph(int n,int m){
    graph g(n);
    for(int i=0;i<m;++i){
        int s,t;
        std::cin>>s>>t;
        --s;--t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    return g;
}
graph load_digraph(int n,int m){
    graph g(n);
    for(int i=0;i<m;++i){
        int s,t;
        std::cin>>s>>t;
        --s;--t;
        g[s].push_back(t);
    }
    return g;
}
graph load_graph0(int n,int m){
    graph g(n);
    for(int i=0;i<m;++i){
        int s,t;
        std::cin>>s>>t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    return g;
}
graph load_digraph0(int n,int m){
    graph g(n);
    for(int i=0;i<m;++i){
        int s,t;
        std::cin>>s>>t;
        g[s].push_back(t);
    }
    return g;
}
graph load_tree(int n){
    graph g(n);
    for(int i=0;i<n-1;++i){
        int s,t;
        std::cin>>s>>t;
        --s;--t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    return g;
}
graph load_tree0(int n){
    graph g(n);
    for(int i=0;i<n-1;++i){
        int s,t;
        std::cin>>s>>t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    return g;
}
graph load_treep(int n){
    graph g(n);
    for(int i=0;i<n-1;++i){
        int t;
        std::cin>>t;
        g[i+1].push_back(t);
        g[t].push_back(i+1);
    }
    return g;
}

template<typename T>
graph_w<T> load_graph_weight(int n,int m){
    graph_w<T> g(n);
    for(int i=0;i<m;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        --s;--t;
        g[s].emplace_back(t,u);
        g[t].emplace_back(s,u);
    }
    return g;
}
template<typename T>
graph_w<T> load_digraph_weight(int n,int m){
    graph_w<T> g(n);
    for(int i=0;i<m;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        --s;--t;
        g[s].emplace_back(t,u);
    }
    return g;
}
template<typename T>
graph_w<T> load_graph0_weight(int n,int m){
    graph_w<T> g(n);
    for(int i=0;i<m;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        g[s].emplace_back(t,u);
        g[t].emplace_back(s,u);
    }
    return g;
}
template<typename T>
graph_w<T> load_digraph0_weight(int n,int m){
    graph_w<T> g(n);
    for(int i=0;i<m;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        g[s].emplace_back(t,u);
    }
    return g;
}
template<typename T>
graph_w<T> load_tree_weight(int n){
    graph_w<T> g(n);
    for(int i=0;i<n-1;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        --s;--t;
        g[s].emplace_back(t,u);
        g[t].emplace_back(s,u);
    }
    return g;
}
template<typename T>
graph_w<T> load_tree0_weight(int n){
    graph_w<T> g(n);
    for(int i=0;i<n-1;++i){
        int s,t;
        T u;
        std::cin>>s>>t>>u;
        g[s].emplace_back(t,u);
        g[t].emplace_back(s,u);
    }
    return g;
}
template<typename T>
graph_w<T> load_treep_weight(int n){
    graph_w<T> g(n);
    for(int i=0;i<n-1;++i){
        int t;
        T u;
        std::cin>>t>>u;
        g[i+1].emplace_back(t,u);
        g[t].emplace_back(i+1,u);
    }
    return g;
}
#line 3 "cpplib/functional/MAX.hpp"
/**
 * @brief 最大値
 */

template<typename T>
struct MAX{
    T operator()(const T& s,const T& t){
        return std::max(s,t);
    }
};
#line 3 "code.cpp"

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

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

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
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

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
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

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

using namespace atcoder;

lint f(lint s,lint t){return max(s,t);}
lint E(){return -1;}
int main(){
    lint n,q;
    cin>>n>>q;
    vec a(n);
    rep(i,n)cin>>a[i];
    segtree<lint,f,E> seg(a);
    while(q--){
        lint c,s,t;
        cin>>c>>s>>t;
        if(c==1){
            seg.set(s-1,t);
        }
        if(c==2){
            cout<<seg.prod(s-1,t)<<endl;
        }
        if(c==3){
            cout<<seg.max_right(s-1,[&](lint x){return x<t;})+1<<endl;
        }
    }
}
