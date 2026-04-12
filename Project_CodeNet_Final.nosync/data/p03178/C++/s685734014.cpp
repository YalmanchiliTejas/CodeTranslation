#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/numeric/interval.hpp>
#include <boost/numeric/interval/io.hpp>
#include <boost/any.hpp>
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
#define cout (cout<<fixed<<setprecision(15))
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define output2(v) for(auto i:v)output(i);
#define input(a,n) lint n;cin>>n;vector<lint>a(n);rep(i,n)cin>>a[i];
#define sum(v) accumulate(all(v),0LL)
#define INF (1LL<<60)
#define IINF (1<<30)
#define LINF 9223372036854775807
#define MOD 1000000007
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};
inline lint gcd(lint a,lint b){return b?gcd(b,a%b):a;}
inline lint lcm(lint a,lint b){return a*b/gcd(a,b);}
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
inline mint fact(lint a){
    return a?fact(a-1)*a:1;
}
string n;
lint D;
lint dp[10001][2][101];
lint f(lint i,lint j,lint k){
    if(i==10001)return k%D==0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    mint ans=0;
    lint r=j?9:n[i]-'0';
    rep(d,r+1){
        ans+=f(i+1,j||r>d,(k+d)%D);
    }
    return dp[i][j][k]=ans.a;
}
int main(){
    cin>>n>>D;
    while(n.size()<10001)n.insert(n.begin(),'0');
    memset(dp,-1,sizeof(dp));
    cout<<mint(f(0,0,0))-1<<endl;
}