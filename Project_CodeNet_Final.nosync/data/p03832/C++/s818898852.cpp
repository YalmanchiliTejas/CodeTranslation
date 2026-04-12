#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

constexpr int64 P = 1000000007;

struct FiniteField {
 private:
  int64 x;
  static inline int64 Normalize(int64 x) {
    if (0 <= x && x < P) return x; x %= P; if (x < 0) x += P; return x;
  }
 public:
  FiniteField(int64 x) : x(Normalize(x)) {}
  FiniteField() : x(0) {}
  int64 Value() const { return x; }
  inline FiniteField operator+(FiniteField o) const {
    FiniteField r(*this); r += o; return r;
  }
  inline FiniteField operator-(FiniteField o) const {
    FiniteField r(*this); r -= o; return r;
  }
  inline FiniteField operator* (FiniteField o) const {
    FiniteField r(*this); r *= o; return r;
  }
  inline FiniteField operator/ (FiniteField o) const {
    FiniteField r(*this); r /= o; return r;
  }
  inline void operator+= (FiniteField o) { x = (x + o.x) % P; }
  inline void operator-= (FiniteField o) { x = (x + P - o.x) % P; }
  inline void operator*= (FiniteField o) { x = (x * o.x) % P; }
  void operator/=(FiniteField o) {
    int64 p = P - 2; while (p) { if (p % 2) { *this *= o; } o *= o; p /= 2; }
  }
};

ostream& operator<<(ostream& s, const FiniteField& v) { s << v.Value(); return s; }

template<typename T>
vector<vector<T>> Make2DVector(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

tuple<vector<FiniteField>, vector<FiniteField>> MakeFactorialTables(int n) {
  vector<FiniteField> factorials(n + 1);
  vector<FiniteField> inverse_factorials(n + 1);
  factorials[0] = 1;
  for (int i = 1; i <= n; i++) {
    factorials[i] = factorials[i - 1] * i;
  }
  inverse_factorials[n] = FiniteField(1) / factorials[n];
  for (int i = n; i >= 1; i--) {
    inverse_factorials[i - 1] = inverse_factorials[i] * i;
  }
  return make_tuple(factorials, inverse_factorials);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  vector<FiniteField> fs, i_fs;
  tie(fs, i_fs) = MakeFactorialTables(n);
  auto c_fn = [&](int x, int y) -> FiniteField {
    if (x < y) return 0;
    return fs[x] * i_fs[y] * i_fs[x - y];
  };

  auto dp = Make2DVector(b + 1, n + 1, FiniteField(0));
  dp[a - 1][0] = 1;
  for (int i = a; i <= b; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i - 1][j].Value() == 0) continue;

      dp[i][j] += dp[i - 1][j];

      FiniteField x = 1;
      for (int k = 1; k <= d; k++) {
        if (j + i * k > n) break;
        x *= c_fn(k * i - 1, i - 1);
        // cout << "k: " << k << " x: " << x << endl;
        if (c <= k) {
          dp[i][j + i * k] += dp[i - 1][j] * c_fn(n - j, i * k) * x;
        }
      }
    }
  }
  // cout << dp[2][6] << endl;

  cout << dp[b][n] << endl;
}