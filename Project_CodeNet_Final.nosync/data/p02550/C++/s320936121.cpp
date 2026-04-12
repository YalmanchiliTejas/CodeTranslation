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
#line 5 "cpplib/math/mod_int.hpp"

/**
 * @brief ModInt
 */

template<int MOD>
struct mod_int {
    using mint=mod_int<MOD>;
    using u64 = std::uint_fast64_t;
    u64 a;
    constexpr mod_int(const long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}
    constexpr u64 &value()noexcept{return a;}
    constexpr const u64 &value() const noexcept {return a;}
    constexpr mint operator+(const mint rhs)const noexcept{return mint(*this) += rhs;}
    constexpr mint operator-(const mint rhs)const noexcept{return mint(*this)-=rhs;}
    constexpr mint operator*(const mint rhs) const noexcept {return mint(*this) *= rhs;}
    constexpr mint operator/(const mint rhs) const noexcept {return mint(*this) /= rhs;}
    constexpr mint &operator+=(const mint rhs) noexcept {
        a += rhs.a;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
    constexpr mint &operator-=(const mint rhs) noexcept {
        if (a<rhs.a)a += get_mod();
        a -= rhs.a;
        return *this;
    }
    constexpr mint &operator*=(const mint rhs) noexcept {
        a = a * rhs.a % get_mod();
        return *this;
    }
    constexpr mint operator++(int) noexcept {
        a += 1;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
    constexpr mint operator--(int) noexcept {
        if (a<1)a += get_mod();
        a -= 1;
        return *this;
    }
    constexpr mint &operator/=(mint rhs) noexcept {
        u64 exp=get_mod()-2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr bool operator==(mint x) noexcept {
        return a==x.a;
    }
    constexpr bool operator!=(mint x) noexcept {
        return a!=x.a;
    }
    constexpr bool operator<(mint x) noexcept {
        return a<x.a;
    }
    constexpr bool operator>(mint x) noexcept {
        return a>x.a;
    }
    constexpr bool operator<=(mint x) noexcept {
        return a<=x.a;
    }
    constexpr bool operator>=(mint x) noexcept {
        return a>=x.a;
    }
    constexpr static int root(){
        mint root = 2;
        while(root.pow((get_mod()-1)>>1).a==1)root++;
        return root.a;
    }
    constexpr mint pow(long long n){
        long long x=a;
        mint ret = 1;
        while(n>0) {
            if(n&1)(ret*=x);
            (x*=x)%=get_mod();
            n>>=1;
        }
        return ret;
    }
    constexpr mint inv(){
        return pow(get_mod()-2);
    }
    static std::vector<mint> fac;
    static std::vector<mint> ifac;
    static bool init;
    constexpr static int mx=10000001;
    void build(){
        init=0;
        fac.resize(mx);
        ifac.resize(mx);
        fac[0]=1,ifac[0]=1;
        for(int i=1;i<mx;i++)fac[i]=fac[i-1]*i;
        ifac[mx-1]=fac[mx-1].inv();
        for(int i=mx-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1);
    }
    mint comb(long long b){
        if(init)build();
        if(a==0&&b==0)return 1;
        if((long long)a<b)return 0;
        return fac[a]*ifac[a-b]*ifac[b];
    }
    mint fact(){
        if(init)build();
        return fac[a];
    }
    mint fact_inv(){
        if(init)build();
        return ifac[a];
    }
    friend std::ostream& operator<<(std::ostream& lhs, const mint& rhs) noexcept {
        lhs << rhs.a;
        return lhs;
    }
    friend std::istream& operator>>(std::istream& lhs,mint& rhs) noexcept {
        lhs >> rhs.a;
        return lhs;
    }
    constexpr static u64 get_mod(){
        return MOD;
    }
};
template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::fac;
template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::ifac;
template<int MOD>bool mod_int<MOD>::init=1;
#line 3 "cpplib/math/mod_int998244353.hpp"
using mint=mod_int<998'244'353>;

/**
 * @brief ModInt(998'244'353)
 */
#line 3 "code.cpp"
int main(){
    lint n,x,m;
    cin>>n>>x>>m;
    lint ans=0;
    vec v;
    map<lint,lint>ma;
    bool b=0;
    for(lint i=0;i<n;++i){
        if(!b&&ma.count(x)){
            b=1;
            lint tmp=0;
            rep(j,ma[x],i){
                tmp+=v[j];
            }
            lint k=max(0LL,n-i-100)/(i-ma[x]);
            ans+=tmp*k;
            i+=k*(i-ma[x]);
        }
        ans+=x;
        v.push_back(x);
        ma[x]=i;
        x=x*x%m;
    }
    cout<<ans<<endl;
}
