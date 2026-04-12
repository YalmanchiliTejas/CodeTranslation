#include<bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll INF=(1LL<<62);
const ld pi=acosl((ld)-1);
const ll mod = 1000000007;
// const ll mod = 1234567;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};
#define endn "\n"
#define TO_STRING(VariableName) # VariableName

template <typename T>ostream &operator<<(ostream &out,const vector<T> &v) {rep(i,(int)v.size()-1)cout<<v[i]<<" ";cout<<v[(int)v.size()-1];return out;}
template <typename T1, typename T2>ostream &operator<<(ostream &out, const map<T1, T2> &p) {out << "(" << p.first << ", " << p.second << ")";return out;}
template <typename T1, typename T2>ostream &operator<<(ostream &out, const pair<T1, T2> &p){out << "(" << p.first << ", " << p.second << ")";return out;}
template<class T>void debag(const T &obj){cout<<obj<<endl;}

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< mod >;

bool solve(){
  string s;cin>>s;
  ll d;cin>>d;
  ll n=s.size();
  modint dp[n+1][d][2];
  rep(i,n+1)rep(j,d)rep(k,2)dp[i][j][k]=0;
  dp[0][0][1]=1;
  rep(i,n)rep(j,d)rep(k,2){
    if(k==1){
      //一致している
      int next=s[i]-'0';
      dp[i+1][(j+next)%d][1]+=dp[i][j][k];
      rep(x,next)dp[i+1][(j+x)%d][0]+=dp[i][j][k];
    }

    if(k==0){
      rep(x,10)dp[i+1][(j+x)%d][0]+=dp[i][j][k];
    }
  }

  modint ans=dp[n][0][0]+dp[n][0][1]-1;
  cout<<ans<<endl;
  return false;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout<<fixed<<setprecision(30);
  solve();
}
