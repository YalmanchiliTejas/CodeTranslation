#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/numeric/interval.hpp>
#include <boost/numeric/interval/io.hpp>
using namespace::std;
namespace mp = boost::multiprecision;
typedef mp::number<mp::cpp_dec_float<32,int64_t>> cfloat;
typedef mp::cpp_int cint;
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
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define irep(i) for(lint i = 0;; i++)
#define irep1(i) for(lint i = 1;; i++)
#define irep2(i) for(lint i = 2;; i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define rrepi(i,a,b) for(lint i = (lint)(b-1); i >a-1; i--)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rep2(i,a,b,c) for(lint i=lint(a);i>lint(b);i+=c)
#define all(x) (x).begin(),(x).end()
#define sl(c) (('a')<=(c)&&(c)<=('z'))
#define ll(c) (('A')<=(c)&&(c)<=('Z'))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define PI 3.141592653589793
#define cout (cout<<fixed<<setprecision(15))
#define makeupper(t) (transform(all(t),t.begin(),::toupper))
#define makelower(t) (transform(all(t),t.begin(),::tolower))
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
#define NEXT_LINE string junk; getline(cin, junk);
#define output(v) do{rep(i,v.size())cout<<(i?" ":"")<<v[i];cout<<"\n";}while(0)
#define output2(v) rep(i,v.size()){rep(j,v[i].size()){cout<<(j?" ":"")<<v[i][j];}cout<<"\n";}
#define INF (1LL<<60)
#define IINF (1<<30)
#define LINF 9223372036854775807
#define MOD 1000000007
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};
vector<lint> operator+(const vector<lint>& v1,const vector<lint>& v2){
    vector<lint> v(v1.size()+v2.size(),0);
    rep(i,v1.size())v[i]=v1[i];
    rep(i,v2.size())v[i+v1.size()]=v2[i];
    return v;
}
inline lint sum(vector<lint> v){
    lint sum=0;
    rep(i,v.size())sum+=v[i];
    return sum;
}
inline string replace(string str, string before, std::string after) {
	string::size_type  Pos(str.find(before));
	while (Pos != std::string::npos) {
		str.replace(Pos, before.length(), after);
		Pos = str.find(before, Pos + after.length());
	}
	return str;
}
inline vector<string> split(string s, string delim) {
	vector<string> elems;
	s=replace(s, "#", "HASH");
	s=replace(s, delim,"#");
	stringstream ss(s);
	string item;
	while (getline(ss, item, '#')) {
		elems.push_back(replace(item, "HASH", "#"));
	}
	return elems;
}
inline vector<int> cross(vector<int> a, vector<int> b) {
    return { a[1] * b[2] - a[2] * b[1],a[2] * b[0] - a[0] * b[2],a[0] * b[1] - a[1] * b[0] };
}
inline lint GCD(lint a,lint b){return b?GCD(b,a%b):a;}
inline vector<lint> primeList(lint n) {
    vector<bool> p(n+1);
    vector<lint> list;
    repi(i,1, n+1)p[i] = true;
    repi(i,2,sqrt(n)+1) {
        if (p[i]) {
            repi(j,2,n/i+1) {
                p[i*j] = false;
            }
        }
    }
    repi(i, 2, n+1)if (p[i])list.push_back(i);
    return list;
}
inline set<lint> primeSet(lint n) {
    vector<bool> p(n+1);
    set<lint> set;
    repi(i,1, n+1)p[i] = true;
    repi(i,2,sqrt(n)+1) {
        if (p[i]) {
            repi(j,2,n/i+1) {
                p[i*j] = false;
            }
        }
    }
    repi(i, 2, n+1)if (p[i])set.insert(i);
    return set;
}
inline bool isPrime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0)return false;
    }
    return true;
}
inline lint max(vector<lint> num){
    lint M=num[0];
    rep(i,num.size())M=max(M,num[i]);
    return M;
}
inline lint min(vector<lint> num){
    lint M=num[0];
    rep(i,num.size())M=min(M,num[i]);
    return M;
}
inline cint cmax(vector<cint> num){
    cint M=num[0];
    rep(i,num.size())if(M<num[i])M=num[i];
    return M;
}
inline cint cmin(vector<cint> num){
    cint M=num[0];
    rep(i,num.size())if(M>num[i])M=num[i];
    return M;
}
inline lint signal(lint val){
    if(val==0)return 0;
    else return val/abs(val);
}
struct IVector2{
    lint x,y;
};
bool operator< (const IVector2 &s, const IVector2 &t){
        return s.x==t.x?s.y<t.y:s.x<t.x;
};
bool operator> (const IVector2 &s, const IVector2 &t){
        return s.x==t.x?s.y>t.y:s.x>t.x;
};
struct IVector3{
    lint x,y,z;
};
struct IVector4{
    lint x,y,z,w;
};
template<typename... args>struct dfs{
    public:
    queue<function<void(void)>> que;
    function<void(args...,dfs<args...>&)> func;
    void run(){
        while(!que.empty()){
            que.front()();
            que.pop();
        }
    }
    void push(args... arg){
        que.push(bind(func,arg...,ref(*this)));
    }
    dfs(args... init,function<void(args...,dfs<args...>&)> func):func(func){
        push(init...);
        run();
    }
};
lint mod_pow(lint x,lint y,lint mod){
    if(y==0)return 1;
    else if(y==1)return x;
    else if(y%2==1)return x*mod_pow(x,y-1,mod)%mod;
    else return mod_pow(x,y/2,mod)*mod_pow(x,y/2,mod)%mod;
}
lint binary_search(function<bool(lint)> func) {
    lint left = -1;
    lint right =IINF;
    while (right - left > 1) {
        lint mid = left + (right - left) / 2;
        if (func(mid)) right = mid;
        else left = mid;
    }
    return right;
}
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
inline mint pow(mint m,lint n){
    if(n==0)return 1;
    else if(n%2==0){
        mint x=pow(m,n/2);
        return x*x;
    }else{
        return m*pow(m,n-1);
    }
}
class Comb{
    public:
    vector<lint> fac,ifac;
    Comb(){
        fac.resize(300001);
        ifac.resize(300001);
        fac[0] = 1;
        ifac[0] = 1;
        rep(i,300000){
            fac[i+1] = fac[i]*(i+1) % MOD;
            ifac[i+1] = ifac[i]*mpow(i+1, MOD-2) % MOD;
        }
    }
    lint mpow(lint x, lint n){
        lint ans = 1;
        while(n != 0){
            if(n&1) ans = ans*x % MOD;
            x = x*x % MOD;
            n = n >> 1;
        }
        return ans;
    }
    lint comb(lint a, lint b){
        if(a == 0 && b == 0)return 1;
        if(a < b || a < 0)return 0;
        lint tmp = ifac[a-b]* ifac[b] % MOD;
        return tmp * fac[a] % MOD;
    }
};
int main(){
    lint n,m,k;
    cin>>n>>m>>k;
    mint cnt=0;
    rep(i,n){
        cnt+=(i+1)*i*m*m/2;
        cnt+=(n-i)*(n-i-1)*m*m/2;
    }
    rep(j,m){
        cnt+=(j+1)*j*n*n/2;
        cnt+=(m-j)*(m-j-1)*n*n/2;        
    }
    cout<<cnt*k*(k-1)*Comb().comb(n*m,k)/((n*m)*(n*m-1))/2;
}