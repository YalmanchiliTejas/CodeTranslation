#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
//struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
__attribute__((constructor))
void init(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(15);
}
// random_device rd;
// mt19937 mt(rd());
// #include <boost/numeric/interval.hpp>
// #include <boost/numeric/interval/io.hpp>
// #include <boost/intrusive/rbtree.hpp>
// #include <boost/dynamic_bitset.hpp>
// #include <boost/geometry.hpp>
// #include <boost/geometry/geometries/linestring.hpp>
// #include <boost/geometry/geometries/polygon.hpp>
// #include <boost/geometry/geometries/point_xy.hpp>
// #include <boost/math/tools/minima.hpp>
// using boost::math::tools::brent_find_minima;
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// typedef mp::number<mp::cpp_dec_float<256>> cdouble;
// typedef mp::cpp_int cint;
// #include <boost/unordered_map.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
template<typename T=long long>using pbds=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T=long long>using pbds_map=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T=long long>using pqueue =__gnu_pbds::priority_queue<T, less<T>,__gnu_pbds::rc_binomial_heap_tag>;
typedef long long lint;
typedef long long ll;
typedef long double ldouble;
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<double> dvec;
typedef vector<vector<double>> dmat;
typedef vector<vector<vector<double>>> dmat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
typedef vector<vector<vector<string>>> smat3;
typedef vector<pair<lint,lint>> pvec;
typedef vector<vector<pair<lint,lint>>> pmat;
typedef vector<vector<vector<pair<lint,lint>>>> pmat3;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define irep(i) for(lint i = 0;; i++)
#define irep1(i) for(lint i = 1;; i++)
#define irep2(i) for(lint i = 2;; i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define rrepi(i,a,b) for(lint i = (lint)(b-1); i >a-1; i--)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rep2(i,a,b,c) for(lint i=lint(a);i>lint(b);i+=c)
#define all(x) (x).begin(),(x).end()
#define PI 3.141592653589793
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
//#define input(a,n) lint n;cin>>n;vector<lint>a(n);rep(i,n)cin>>a[i];
#define SUM(v) accumulate(all(v),0LL)
#define INF (1LL<<60)
#define IINF (1<<30)
#define EPS (1e-10)
#define LINF 9223372036854775807
//#define MOD 998244353LL
#define MOD 1000000007LL
#define endl "\n"
//struct in{template<class T>operator T(){T t;cin>>t;return t;}};
template<typename T>inline void numout(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i<INF/2?i:"INF";f=1;}cout<<endl;}
template<typename T>inline void numout2(T t){for(auto i:t)numout(i);}
template<typename T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}
template<typename T>inline void output2(T t){for(auto i:t)output(i);}
template<typename T>inline void _output(T t){bool f=0;for(int i=0;i<t.size();i++){cout<<f?"":" "<<t[i];f=1;}cout<<endl;}
template<typename T>inline void _output2(T t){for(int i=0;i<t.size();i++)output(t[i]);}
auto Y=[&](auto f){return[&](auto... args){return f(f, args...);};};
template<typename T=lint>T in(){return *istream_iterator<T>(cin);}
template<typename T=lint>inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T=lint>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<typename T>inline T minq(T a,T b){return min(a,b);}
template<typename T>inline T maxq(T a,T b){return max(a,b);}
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
inline bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};

class mint {
  using u64 = std::uint_fast64_t;
    public:
    u64 a;
    constexpr mint(const u64 x = 0) noexcept : a(x % MOD) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr mint operator+(const mint rhs) const noexcept {
        return mint(*this) += rhs;
    }
    constexpr mint operator-(const mint rhs) const noexcept {
        return mint(*this) -= rhs;
    }
    constexpr mint operator*(const mint rhs) const noexcept {
        return mint(*this) *= rhs;
    }
    constexpr mint operator/(const mint rhs) const noexcept {
        return mint(*this) /= rhs;
    }
    constexpr mint &operator+=(const mint rhs) noexcept {
        a += rhs.a;
        if (a >= MOD) {
            a -= MOD;
        }
        return *this;
    }
    constexpr mint &operator-=(const mint rhs) noexcept {
        if (a < rhs.a) {
            a += MOD;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr mint &operator*=(const mint rhs) noexcept {
        a = a * rhs.a % MOD;
        return *this;
    }
    constexpr mint operator++(int n) const noexcept {
        return mint(*this) +=1;
    }
    constexpr mint operator--(int n) const noexcept {
        return mint(*this) -=1;
    }
    constexpr mint &operator/=(mint rhs) noexcept {
        u64 exp = MOD - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};
ostream& operator<<(ostream& lhs, const mint& rhs) noexcept {
    lhs << rhs.a;
    return lhs;
}
istream& operator>>(istream& lhs, const mint& rhs) noexcept {
    lhs >> rhs.a;
    return lhs;
}
mint pow(mint m,lint n){
    if(n==0)return 1;
    else if(n%2==0){
        mint x=pow(m,n/2);
        return x*x;
    }else{
        return m*pow(m,n-1);
    }
}
inline mint rev(mint m){
    return pow(m,MOD-2);
}

inline mint fact(lint a){
    return a?fact(a-1)*a:1;
}

int main(){
    lint n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    vector<mint>ans(n+1);
    ans[0]=1;
    repi(i,a,b+1){
        vector<mint>mul(n+1);
        mul[0]=1;
        repi(j,c,d+1){
            if(i*j>n)break;
            mul[i*j]=rev(pow(fact(i),j)*fact(j));
        }
        vector<mint> ans2(n+1);
        rep(i,n+1)rep(j,n+1){
            if(i+j>n)continue;
            ans2[i+j]+=ans[i]*mul[j];
        }
        ans=ans2;
    }
    cout<<ans[n]*fact(n)<<endl;
}