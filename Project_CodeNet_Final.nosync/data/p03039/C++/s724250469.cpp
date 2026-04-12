#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
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

vector<mint> fact,ifact;

mint comb(int64 n, int64 r){
  return fact[n] * ifact[r] * ifact[n-r];
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n,m,k;
  cin >> n >> m >> k;
  fact.resize(n*m+1,1);
  ifact.resize(n*m+1,1);
  REP(i,n*m)fact[i+1] = fact[i] * (i+1);
  ifact[n*m] = fact[n*m].inv();
  FORR(i,n*m,1)ifact[i-1] = ifact[i] * i;
  mint ans = 0;
  REP(d,n){
    ans += (mint)d * (n - d) * m * m;
  }
  REP(d,m){
    ans += (mint)d * (m - d) * n * n;
  }
  ans *= comb(n*m-2,k-2);
  ANS(ans);
  return 0;
}