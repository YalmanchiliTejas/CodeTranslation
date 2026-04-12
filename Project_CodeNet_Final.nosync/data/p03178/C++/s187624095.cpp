#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = INT_MAX / 2; const ll INF = LLONG_MAX / 2;
//template end

int mod = 1e9+7;
struct Mint {
  int val;
  Mint inv() const {
    int tmp, a = val, b = mod, x = 1, y = 0;
    while(b) tmp = a / b, a -= tmp * b, swap(a, b), x -= tmp * y, swap(x, y);
    return Mint(x);
  }
public:
  Mint() :val(0) {}
  Mint(ll x) :val(x >= 0 ? x % mod : x % mod + mod) {}
  int mtoi() { return this->val; }
  Mint pow(ll t) { Mint res = 1,b = *this; while(t){if(t&1)res *= b;b *= b;t >>= 1;}return res; }
  Mint& operator+=(const Mint& x) { if ((val += x.val) >= mod) val -= mod; return *this; }
  Mint& operator-=(const Mint& x) { if ((val += mod - x.val) >= mod) val -= mod; return *this; }
  Mint& operator*=(const Mint& x) { val = (ll)val * x.val % mod; return *this; }
  Mint& operator/=(const Mint& x) { return *this *= x.inv(); }
  bool operator==(const Mint& x) const { return val == x.val; }
  bool operator!=(const Mint& x) const { return val != x.val; }
  bool operator<(const Mint& x) const { return val < x.val; }
  bool operator<=(const Mint& x) const { return val <= x.val; }
  bool operator>(const Mint& x) const { return val > x.val; }
  bool operator>=(const Mint& x) const { return val >= x.val; }
  Mint operator+(const Mint& x) const { return Mint(*this) += x; }
  Mint operator-(const Mint& x) const { return Mint(*this) -= x; }
  Mint operator*(const Mint& x) const { return Mint(*this) *= x; }
  Mint operator/(const Mint& x) const { return Mint(*this) /= x; }
};
struct factorial {
  vector<Mint> Fact, Finv;
public:
  factorial(int maxx) {
    Fact.resize(maxx+1,Mint(1)),Finv.resize(maxx+1); rep(i,0,maxx)Fact[i+1]=Fact[i]*Mint(i+1);
    Finv[maxx]=Mint(1)/Fact[maxx]; rrep(i,maxx,0)Finv[i-1]=Finv[i]*Mint(i);
  }
  Mint fact(int n,bool inv) { if(inv) return Finv[n]; else return Fact[n]; }
  Mint nPr(int n,int r) { if(n<0||n<r||r<0) return Mint(0); else return Fact[n]*Finv[n-r]; }
  Mint nCr(int n,int r) { if(n<0||n<r||r<0) return Mint(0); else return Fact[n]*Finv[r]*Finv[n-r]; }
};

int main(){
  char c[10010]; int d; scanf("%s%d",c,&d);
  string k=c; int n=k.size();
  Mint dp[n+1][2][d]={};
  dp[0][0][0]=1;
  rep(i,0,n)rep(j,0,d){
    rep(digit,0,10)dp[i+1][1][(j+digit)%d]+=dp[i][1][j];
    rep(digit,0,(k[i]-'0'))dp[i+1][1][(j+digit)%d]+=dp[i][0][j];
    dp[i+1][0][(j+(k[i]-'0'))%d]+=dp[i][0][j];
  }
  dp[n][0][0]+=dp[n][1][0]-1;
  printf("%d\n",dp[n][0][0].mtoi());
  return 0;
}
