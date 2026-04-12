#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 998244353;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

template<int64 mod>
struct ModInt{
  int64 x;
  constexpr ModInt(int64 y = 0):x((y%mod+mod)%mod){}
  constexpr ModInt& operator+=(const ModInt& a){
    if((x += a.x) >= mod) x -= mod;
    return *this;
  }
  constexpr ModInt& operator-=(const ModInt& a){
    if((x -= a.x) < 0)x += mod;
    return *this;
  }
  constexpr ModInt& operator*=(const ModInt& a){
    x = x * a.x % mod;
    return *this;
  }
  constexpr ModInt& operator/=(const ModInt& a){
    *this *= a.inv();
    return *this;
  }
  constexpr ModInt operator-() const {
    return ModInt(-x);
  }
  constexpr ModInt operator+(const ModInt& a) const {
    return ModInt(*this) += a;
  }
  constexpr ModInt operator-(const ModInt& a) const {
    return ModInt(*this) -= a;
  }
  constexpr ModInt operator*(const ModInt& a) const {
    return ModInt(*this) *= a;
  }
  constexpr ModInt operator/(const ModInt& a) const {
    return ModInt(*this) /= a;
  }
  constexpr ModInt operator++(){
    *this += ModInt(1);
    return *this;
  }
  constexpr ModInt operator++(int){
    ModInt old = *this;
    ++*this;
    return old;
  }
  constexpr ModInt operator--(){
    *this -= ModInt(1);
    return *this;
  }
  constexpr ModInt operator--(int){
    ModInt old = *this;
    --*this;
    return old;
  }
  constexpr bool operator==(const ModInt& a) const {
    return x == a.x;
  }
  constexpr bool operator!=(const ModInt& a) const {
    return x != a.x;
  }
  constexpr ModInt pow(int64 r) const {
    if(!r)return 1;
    ModInt res = pow(r>>1);
    res *= res;
    if(r & 1) res *= *this;
    return res;
  }
  constexpr ModInt inv() const {
    return pow(mod-2);
  }
  friend istream& operator>>(istream& is, ModInt& a){
    int64 t;
    is >> t;
    a = ModInt(t);
    return is;
  }
  friend ostream& operator<<(ostream& os, const ModInt& a){
    return os << a.x;
  }
};
using mint = ModInt<MOD>;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n,s;
  cin >> n >> s;
  vector<int32> a(n);
  REP(i,n)cin >> a[i];
  mint ans = 0;
  vector<vector<vector<mint>>> dp(n+1,vector<vector<mint>>(s+1,vector<mint>(2,0)));
  REP(l,n){
    if(a[l] > s)continue;
    dp[l+1][a[l]][0] = l+1;
  }
  REP(i,n){
    FORR(j,s,0){
      if(j - a[i] >= 0)
        dp[i+1][j][1] += dp[i][j-a[i]][0] + dp[i][j-a[i]][1];
      if(j != s)
        dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1];
    }
  }
  REP(r,n){
    // cout << r << " " << dp[r+1][s][1] * (mint)(n - r) << endl;
    ans += (dp[r+1][s][1] + dp[r+1][s][0]) * (mint)(n - r);
  }
  ANS(ans);
  return 0;
}