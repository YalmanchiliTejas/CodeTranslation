#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,j,n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(), i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 1e9 + 7;
 
typedef long long i64;
typedef pair<int, int> pi;
 
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
 
i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcm(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

template <std::int_fast64_t MOD> class ModInt {
  private:
    std::int_fast64_t value;

  public:
    ModInt() : value(0) {}

    ModInt(std::int_fast64_t x) : value(x % MOD) {
      if(value < 0) value += MOD;
    }

    ModInt &operator+=(const ModInt &x) {
      value += x.value;
      if(value >= MOD) value -= MOD;
      return *this;
    }

    ModInt &operator-=(const ModInt &x) {
      if(value < x.value) value += MOD;
      value -= x.value;
      return *this;
    }

    ModInt &operator*=(const ModInt &x) {
      value = value * x.value % MOD;
      return *this;
    }

    ModInt &operator/=(const ModInt &x) {
      *this *= x.inverse();
      return *this;
    }

    ModInt operator-() const { return ModInt(-value); }

    ModInt operator+(const ModInt &x) const { return ModInt(*this) += x; }

    ModInt operator-(const ModInt &x) const { return ModInt(*this) -= x; }

    ModInt operator*(const ModInt &x) const { return ModInt(*this) *= x; }

    ModInt operator/(const ModInt &x) const { return ModInt(*this) /= x; }

    bool operator==(const ModInt *x) const { return value == x.value; }

    bool operator!=(const ModInt *x) const { return value != x.value; }

    ModInt inverse() const {
      std::int_fast64_t a = value, b = MOD, u = 1, v = 0, t;
      while(b > 0) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(u -= t * v, v);
      }
      return ModInt(u);
    }

    ModInt pow(int64_t n) const {
      ModInt ret(1), mul(value);
      while(n > 0) {
        if(n & 1) ret *= mul;
        mul *= mul;
        n >>= 1;
      }
      return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModInt &x) {
      return os << x.value;
    }

    friend std::istream &operator>>(std::istream &is, ModInt &x) {
      std::int_fast64_t t;
      is >> t;
      x = ModInt<MOD>(t);
      return is;
    }

    static std::int_fast64_t get_mod() { return MOD; }
};

using modint = ModInt<mod>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string k;
  int d;
  cin >> k >> d;

  int l = k.size();
  vvt<vt<modint>> dp(l + 1, vvt<modint>(2, vt<modint>(d + 1, 0)));
  dp[0][0][0] = 1;
  rep(i, 0, l) {
    int num = k[i] - '0';
    rep(smaller, 0, 2) {
      rep(j, 0, (smaller ? 9 : num) + 1) {
        rep(s, 0, d) {
          dp[i + 1][smaller || j < num][(s + j) % d] += dp[i][smaller][s];
        }
      }
    }
  }
  cout << dp[l][0][0] + dp[l][1][0] - modint(1) << endl;
}