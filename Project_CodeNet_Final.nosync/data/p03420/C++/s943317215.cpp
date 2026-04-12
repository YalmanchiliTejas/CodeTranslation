#pragma GCC optimize("Ofast","unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std::chrono;
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
// typedef mp::number<mp::cpp_dec_float<0>> cdouble;
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
template<typename T>using Vec=vector<T>;
template<typename T>using Mat=vector<vector<T>>;
template<typename T>using Mat3=vector<vector<vector<T>>>;
template<typename T>using Mat4=vector<vector<vector<vector<T>>>>;
template<typename S,typename T>using pvec=vector<pair<S,T>>;
template<typename S,typename T>using pmat=vector<vector<pair<S,T>>>;
template<typename S,typename T>using pmat3=vector<vector<vector<pair<S,T>>>>;
template<typename S,typename T>using pmat4=vector<vector<vector<vector<pair<S,T>>>>>;
template<typename... T>using tvec=vector<tuple<T...>>;
template<typename... T>using tmat=vector<vector<tuple<T...>>>;
template<typename... T>using tmat3=vector<vector<vector<tuple<T...>>>>;
template<typename... T>using tmat4=vector<vector<vector<vector<tuple<T...>>>>>;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define irep(i) for(lint i = 0;; i++)
#define irepi(i,n) for(lint i = (n);; i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define rrepi(i,a,b) for(lint i = (lint)(b-1); i >a-1; i--)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rep2(i,a,b,c) for(lint i=lint(a);i>lint(b);i+=c)
#define all(x) (x).begin(),(x).end()
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
//#define input(a,n) lint n;cin>>n;vector<lint>a(n);rep(i,n)cin>>a[i];
#define SUM(v) accumulate(all(v),0LL)
#define INF (1LL<<60)
#define IINF (1<<30)
#define EPS (1e-10)
#define LINF 9223372036854775807LL
//#define MOD 998244353LL
#define MOD 1000000007LL
#define endl "\n"
template<typename T>inline void numout(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i<INF/2?i:"INF";f=1;}cout<<endl;}
template<typename T>inline void numout2(T t){for(auto i:t)numout(i);}
template<typename T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}
template<typename T>inline void output2(T t){for(auto i:t)output(i);}
template<typename T>inline void _output(T t){bool f=0;for(int i=0;i<t.size();i++){cout<<f?"":" "<<t[i];f=1;}cout<<endl;}
template<typename T>inline void _output2(T t){for(int i=0;i<t.size();i++)output(t[i]);}
auto call=[](auto f,auto... args){return f(f,args...);};
template<typename T=lint>T in(){return *istream_iterator<T>(cin);}
template<typename T=lint>inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T=lint>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<typename T>inline T minq(T a,T b){return min(a,b);}
template<typename T>inline T maxq(T a,T b){return max(a,b);}
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
inline bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
const vector<lint> dx={-1,1,0,0,1,1,-1,-1};
const vector<lint> dy={0,0,-1,1,1,-1,1,-1};

class bint{
    public:
    constexpr static int mx=36;
    constexpr static int base=10;
    int v[mx]={};
    bint(string s){
        for(int i=0;i<(int)s.size();i++)v[i]=s[s.size()-i-1]-'0';
    }
    bint(long long x=0){
        int idx=0;
        while(x){
            v[idx++]=x%10;
            x/=10;
        }
    }
    string to_string(){
        string t;
        const bint tmp=(v[mx-1]==9)?inv():bint(*this);
        if(v[mx-1]==9)t="-";
        bool f=0;
        for(int i=mx-2;i>=0;i--){
            if(tmp.v[i])f=1;
            if(f)t+=(tmp.v[i]+'0');
        }
        if(t==""||t=="-")return "0";
        else return t;
    }
    bint operator+(const bint& rhs) const noexcept {
        return bint(*this) += rhs;
    }
    bint operator-(const bint& rhs) const noexcept {
        return bint(*this) -= rhs;
    }
    bint operator-() const noexcept {
        return bint(*this).inv();
    }
    bint operator*(const bint& rhs) const noexcept {
        return bint(*this) *= rhs;
    }
    bint operator/(const bint& rhs) const noexcept {
        return bint(*this) /= rhs;
    }
    bint &operator+=(const bint& t) noexcept {
        plus(t);
        return *this;
    }
    bint &operator-=(const bint& t) noexcept {
        plus(t.inv());
        return *this;
    }
    bint &operator*=(const bint& t) noexcept {
        bint ret;
        for(int i=0;i<mx;i++)for(int j=0;j<mx-i;j++){
            ret.v[i+j]+=v[i]*t.v[j];
        }
        for(int i=0;i<mx-1;i++){
            v[i+1]+=v[i]%10;
            v[i]/=10;
        }
        return *this=ret;
    }
    bint &operator/=(bint rhs) noexcept {
        return *this;
    }
    bint &operator=(bint rhs) noexcept {
        memcpy(v,rhs.v,mx*sizeof(int));
        return *this;
    }
    void plus(const bint& t){
        for(int i=0;i<mx;i++){
            v[i]+=t.v[i];
            if(i!=mx-1)v[i+1]+=(v[i]>=10);
            if(v[i]>=10)v[i]-=10;
        }
    }
    bint inv()const{
        bint res;
        bool b=0;
        for(int i=0;i<mx;i++){
            if(b){
                res.v[i]=9-v[i];
            }else{
                if(v[i]){
                    b=1;
                    res.v[i]=10-v[i];
                }else{
                    res.v[i]=0;
                }
            }
        }
        return res;
    }
};
int main(){
    lint n,k;
    cin>>n>>k;
    lint ans=0;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    repi(i,k+1,n+1){
        ans+=n/i*(i-k);
        ans+=max(n%i-k+1,0LL);
    }
    cout<<ans<<endl;
}
