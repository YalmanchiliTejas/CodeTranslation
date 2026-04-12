#include <bits/stdc++.h>
using namespace std;

typedef int_fast32_t int32;
typedef int_fast64_t int64;

const int32 inf = 1e9+7;
const int32 MOD = 1000000007;
const int64 llinf = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define all(obj) (obj).begin(),(obj).end()
#define rall(obj) (obj).rbegin(),(obj).rend()
#define fi first
#define se second
#define pb(a) push_back(a)
typedef pair<int32,int32> pii;
typedef pair<int64,int64> pll;

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return true; } return false;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return true; } return false;
}

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
  int32 n;
  cin >> n;
  vector<mint> a(n);
  REP(i,n)cin >> a[i];
  mint ans = 0;
  REP(i,n)ans += a[i];
  ans *= ans;
  REP(i,n)ans -= a[i] * a[i];
  ANS(ans/2);
  return 0;
}