/*
 *    author:  Gary Shih
 *    created: 2020-05-06 14:08:54
 */
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

// Mod Integer {{{
// {{{
template <int _MOD>
class ModInt {
 public:
  static const auto MOD = _MOD;
  template <class T>
  using integral_only = typename enable_if<is_integral<T>::value>::type;

  int x;
  constexpr ModInt() : x() {}
  template <class T, integral_only<T>* = nullptr>
  ModInt(T _x) {
    x = _x % MOD;
    if (x < 0) x += MOD;
  }
  ModInt operator-() const { return {x == 0 ? 0 : MOD - x}; }
  ModInt& operator+=(ModInt rhs) {
    x += rhs.x;
    if (x >= MOD) x -= MOD;
    return *this;
  }
  ModInt& operator-=(ModInt rhs) {
    x -= rhs.x;
    if (x < 0) x += MOD;
    return *this;
  }
  ModInt& operator*=(ModInt rhs) {
    x = (long long)x * rhs.x % MOD;
    return *this;
  }
  ModInt& operator/=(ModInt rhs) { return *this *= rhs.inv(); }
  ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
  ModInt inv() const {
    // should work for non-prime MOD if gcd(x, MOD) = 1
    int a = x, b = MOD, u = 1, v = 0;
    while (b != 0) {
      int t = a / b;
      a -= t * b, u -= t * v;
      swap(a, b), swap(u, v);
    }
    return u;
  }
  template <class T, integral_only<T>* = nullptr>
  ModInt pow(T e) {
    ModInt r = 1, p = *this;
    while (e) {
      if (e & 1) r *= p;
      p *= p, e >>= 1;
    }
    return r;
  }
  bool operator==(ModInt rhs) const { return x == rhs.x; }
  bool operator!=(ModInt rhs) const { return x != rhs.x; }
  bool operator<(ModInt rhs) const { return x < rhs.x; }
  bool operator<=(ModInt rhs) const { return x <= rhs.x; }
  bool operator>(ModInt rhs) const { return x > rhs.x; }
  bool operator>=(ModInt rhs) const { return x >= rhs.x; }
  friend string to_string(ModInt i) { return to_string(i.x); }
  friend ostream& operator<<(ostream& os, ModInt o) { return os << o.x; }
  friend istream& operator>>(istream& is, ModInt& i) {
    long long foo;
    is >> foo;
    foo %= MOD;
    if (foo < 0) foo += MOD;
    i.x = foo;
    return is;
  }
};
// }}}
const int MOD = 1e9 + 7;
using mint = ModInt<MOD>;
// }}}
// Debug {{{
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
// }}}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.setf(ios::fixed), cout.precision(9);
  string s;
  int d;
  cin >> s >> d;
  vector<vector<mint>> dp(10002, vector<mint>(d));
  int n = dp.size();
  for (int i = 0; i <= 9; ++i) dp[1][i % d] += 1;
  for (int i = 2; i < n; ++i)
    for (int j = 0; j < d; ++j) {
      for (int k = 0; k <= 9; ++k) {
        dp[i][j] += dp[i - 1][(j - k + 10 * d) % d];
      }
    }
  for (int i = 1; i <= 11; ++i) debug(dp[i]);
  mint ans = 0;
  int res = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    int numDigits = s.size() - i - 1;
    if (numDigits) {
      for (int j = 0; j < s[i] - '0'; ++j) {
        ans += dp[numDigits][res];
        debug(i, j);
        debug(numDigits, res, dp[numDigits][res]);
        res = (res - 1 + d) % d;
      }
    } else {
      for (int j = 0; j <= s.back() - '0'; ++j) {
        if ((-res + j + d) % d == 0) {
          ans += 1;
        }
      }
    }
  }
  cout << ans - 1 << '\n';
}
