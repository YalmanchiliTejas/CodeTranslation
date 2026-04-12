#include <bits/stdc++.h>
using namespace std;
#define _MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) _MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define pb push_back
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cerr<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cerr<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.first<<","<<p.second<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}
#else
#define dbg(...) {}
#endif

template<int mod=1000000007>
class ModInt {
  int x;
public:
  ModInt() : x(0) {}
  ModInt(const ModInt &y): x(y.x) {}
  ModInt(int64_t y){ x = y % mod; if(x < 0) x += mod; }
  ModInt &operator += (const ModInt &p){ x += p.x; if(x >= mod) x -= mod; return *this; }
  ModInt &operator -= (const ModInt &p){ x -= p.x; if(x < 0) x += mod; return *this; }
  ModInt &operator *= (const ModInt &p){ x = (int) (1LL * x * p.x % mod); return *this; }
  ModInt &operator /= (const ModInt &p){ *this *= p.inverse(); return *this; }
  ModInt operator -() const { return ModInt(-x); }
  ModInt operator + (const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator - (const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator * (const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator / (const ModInt &p) const { return ModInt(*this) /= p; }
  ModInt operator ^ (const int64_t y) const { return pow(y); }
  bool operator == (const ModInt &p) const { return x == p.x; }
  bool operator != (const ModInt &p) const { return x != p.x; }
  ModInt operator = (const int64_t y) { return *this = ModInt(y); }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0){
      t = a/b; a -= t*b; swap(a, b);
      u -= t*v; swap(u, v);
    }
    return ModInt(u);
  }
  ModInt pow(int64_t y) const {
    if(x==0) return ModInt(0);
    int64_t r = 1, t = x;
    while(y > 0){
      if(y&1) r = r*t%mod;
      t = t*t%mod; y >>= 1;
    }
    return ModInt(r);
  }
  friend ostream &operator << (ostream &os, const ModInt<mod> &p) { return os<<p.x; }
  friend istream &operator >> (istream &is, ModInt<mod> &a) { int64_t x; is>>x; a = ModInt<mod>(x); return is; }
};
using Int = ModInt<>;

Int dp[10005][105][2];

int main(){
  string sk;
  int d;
  cin>>sk>>d;

  int n = sk.size();
  vector<int> k(n);
  rep(i,n) k[i] = sk[i] - '0';

  dp[0][0][1] = 1;
  rep(i,n) rep(j,d){
    rep(x,10){
      dp[i+1][(j+x)%d][0] += dp[i][j][0];
      if(x < k[i]) dp[i+1][(j+x)%d][0] += dp[i][j][1];
      if(x == k[i]) dp[i+1][(j+x)%d][1] += dp[i][j][1];
    }
  }

  cout << (dp[n][0][0] +  dp[n][0][1] - 1) << endl;


  return 0;
}
