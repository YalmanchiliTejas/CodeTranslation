#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007
constexpr int mod = 1000000007;
class mint {
 public:
  long long x;
  constexpr mint(long long x = 0) : x((x % mod + mod) % mod) {}
  constexpr mint operator-() const { return mint(-x); }
  constexpr mint& operator+=(const mint& a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  constexpr mint& operator-=(const mint& a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  constexpr mint& operator*=(const mint& a) {
    (x *= a.x) %= mod;
    return *this;
  }
  constexpr mint operator+(const mint& a) const {
    mint res(*this);
    return res += a;
  }
  constexpr mint operator-(const mint& a) const {
    mint res(*this);
    return res -= a;
  }
  constexpr mint operator*(const mint& a) const {
    mint res(*this);
    return res *= a;
  }
  constexpr mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  constexpr mint inv() const { return pow(mod - 2); }
  constexpr mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
  constexpr mint operator/(const mint& a) const {
    mint res(*this);
    return res /= a;
  }
};

istream& operator>>(istream& is, const mint& m) {
  is >> m.x;
  return is;
}

ostream& operator<<(ostream& os, const mint& m) {
  os << m.x;
  return os;
}

mint choose(long long n, long long a) {
  mint x, y;
  x.x = 1;
  y.x = 1;
  for (long long i = (0); i < (a); ++i) {
    x *= n - i;
    y *= i + 1;
  }
  return x / y;
}

int main(){
    int n;
    vector<ll> data;
    cin >> n;
    mint sum;
    sum.x = 0;
    REP(i,n){
        ll x;
        cin >> x;
        data.push_back(x);
        sum += x;
    }
    mint ans;
    ans.x = 0;
    REP(i,n-1){
        sum -= data[i];
        mint tmp;
        tmp.x = data[i];
        tmp *= sum;
        ans += tmp;
        
    }
    cout << ans << endl;
}