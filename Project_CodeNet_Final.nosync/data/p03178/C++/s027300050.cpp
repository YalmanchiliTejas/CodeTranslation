#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC push_options
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
#include <xmmintrin.h>
#include <immintrin.h>
using namespace::std;
__attribute__((constructor))void init(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// typedef mp::number<mp::cpp_dec_float<0>> cdouble;
// typedef mp::cpp_int cint;
template<typename T>using pbds=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T>using pbds_map=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T,typename E>using hash_map=__gnu_pbds::gp_hash_table<T,E>;
template<typename T>using pqueue =__gnu_pbds::priority_queue<T, greater<T>,__gnu_pbds::rc_binomial_heap_tag>;
typedef long long lint;
#define INF (1LL<<60)
#define IINF (1<<30)
#define LINF (9223372036854775807LL)
#define EPS (1e-10)
#define endl ('\n')
#define MOD 1000000007LL
//#define MOD 998244353LL
//#define MOD 18446744069414584321ULL
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
inline vector<int64_t> range(int64_t n){vector<int64_t>v(n);iota(v.begin(),v.end(),0LL);return v;}
inline vector<int64_t> range(int64_t a,int64_t b){vector<int64_t>v(b-a);iota(v.begin(),v.end(),a);return v;}
inline vector<int64_t> range(int64_t a,int64_t b,int64_t c){vector<int64_t>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return v;}
inline auto reversed(auto v){reverse(v.begin(),v.end());return v;}
#define all(n) begin(n),end(n)
#define dist(a,b,c,d) sqrt(pow(a-c,2)+pow(b-d,2))
//inline lint gcd(lint A,lint B){return B?gcd(B,A%B):A;}
//inline lint lcm(lint A,lint B){return A/gcd(A,B)*B;}
// inline cint cgcd(cint A,cint B){return B?cgcd(B,A%B):A;}
// inline cint clcm(cint A,cint B){return A/cgcd(A,B)*B;}
bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
auto call=[](auto f,auto... args){return f(f,args...);};
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}

class mint {
  using u64 = std::uint_fast64_t;
    public:
    u64 a;
    constexpr mint(const long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}
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
    constexpr mint operator++(int n) noexcept {
        a += 1;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
    constexpr mint operator--(int n) noexcept {
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
    static vector<mint> fac,ifac;
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
    mint comb(lint b){
        if(init)build();
        if(a==0&&b==0)return 1;
        if((lint)a<b||a<0)return 0;
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
    friend ostream& operator<<(ostream& lhs, const mint& rhs) noexcept {
        lhs << rhs.a;
        return lhs;
    }
    friend istream& operator>>(istream& lhs,mint& rhs) noexcept {
        lhs >> rhs.a;
        return lhs;
    }
    constexpr static u64 get_mod(){return MOD;}
};
vector<mint> mint::fac;
vector<mint> mint::ifac;
bool mint::init=1;

template<typename T>
class segment{
	T* node;
	int n=1;
	public:
	segment(int sz){
		while(n<=sz)n<<=1;
		node=new T[(n<<1)-1];
		for(int i=0;i<(n<<1)-1;i++)node[i]=e;
	}
	segment(const vector<T>& v){
		while(n<(int)v.size())n<<=1;
		node=new T[(n<<1)-1];
		for(int i=0;i<(int)v.size();i++)node[i+n-1]=v[i];
		for(int i=n-2;i>=0;i--)node[i]=f(node[(i<<1)+1],node[(i<<1)+2]);
	}
	T get(auto l,auto r){
		l+=n;r+=n;
		T s=e,t=e;
		while(l<r){
			if(l&1)s=f(s,node[l++-1]);
			if(r&1)t=f(node[--r-1],t);
			l>>=1;r>>=1;
		}
		return f(s,t);
	}
    void change(auto t,T val){
		t+=n-1;
        node[t]=val;
		while(t){
			t=(t-1)>>1;
            node[t]=f(node[t*2+1],node[t*2+2]);
		}
	}
	void update(auto t,T val){
		t+=n-1;
        node[t]=f(node[t],val);
		while(t){
			t=(t-1)>>1;
            node[t]=f(node[t*2+1],node[t*2+2]);
		}
	}
	T e=0;
	T f(const T& s,const T& t){
		return max(s,t);
	}
};


template<typename T=lint>
vector<vector<T>> mul(const vector<vector<T>>& s,const vector<vector<T>>& t){
    lint n=s.size();
    vector<vector<T>> res(n,vector<T>(n,0));
    rep(i,n)rep(j,n)rep(k,n){
        res[i][j]+=s[i][k]*t[k][j];
    }
    return res;
}
template<typename T=lint>
vector<vector<T>> mul(const vector<pair<T,T>>& s,const vector<vector<T>>& t){
    lint n=s.size();
    vector<vector<T>> res(n,vector<T>(n,0));
    rep(i,n)rep(j,n)rep(k,n){
        res[i][j]+=s[i][k]*t[k][j];
    }
    return res;
}
template<typename T=lint>
vector<vector<T>> pow(const vector<vector<T>>& s,const lint& n){
    if(n==0){
        lint sz=s.size();
        vector<vector<T>> res(sz,vector<T>(sz,0));
        rep(i,sz)res[i][i]=1;
        return res;
    }
    if(n==1)return s;
    if(n%2==0){
        vector<vector<T>> tmp=pow<T>(s,n/2);
        return mul<T>(tmp,tmp);
    }else{
        return mul<T>(s,pow(s,n-1));
    }
}
template<typename T=lint>
vector<T> conv(vector<T> a,vector<vector<T>> b){
    lint n=a.size();
    vector<T> res(n,0);
    rep(i,n)rep(j,n)res[i]+=a[j]*b[i][j];
    return res;
}

int main(){
    string n;
    lint t;
    cin>>n>>t;
    auto dp=make_vector<lint>(-1,n.size(),t,2);
    auto f=[&](auto f,lint d,lint c,bool b)->lint{
        if(d==n.size())return c==0;
        if(dp[d][c][b]!=-1)return dp[d][c][b];
        lint mx=b?9:n[d]-'0';
        mint ans=0;
        rep(i,mx+1){
            ans+=f(f,d+1,(c+i)%t,b||i<mx);
        }
        return dp[d][c][b]=ans.a;
    };
    cout<<mint(f(f,0,0,0))-1<<endl;
}