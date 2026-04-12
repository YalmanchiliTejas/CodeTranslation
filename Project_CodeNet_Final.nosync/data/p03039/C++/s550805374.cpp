#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

constexpr int64 P = 1000000007;

// Verified: ABC133E, ABC132D, ABC130E
struct FiniteField {
 private:
  int64 x;
 public:
  FiniteField(int64 input_x) : x(input_x) {}
  FiniteField() : x(0) {}
  int64 Value() { return x; }
  inline FiniteField operator+(FiniteField o) {
    FiniteField r(*this); r += o; return r;
  }
  inline FiniteField operator-(FiniteField o) {
    FiniteField r(*this); r -= o; return r;
  }
  inline FiniteField operator* (FiniteField o) {
    FiniteField r(*this); r *= o; return r;
  }
  inline FiniteField operator/ (FiniteField o) {
    FiniteField r(*this); r /= o; return r;
  }
  inline void operator+= (FiniteField o) { x = (x + o.x) % P; }
  inline void operator-= (FiniteField o) { x = (x + P - o.x) % P; }
  inline void operator*= (FiniteField o) { x = (x * o.x) % P; }
  void operator/=(FiniteField o) {
    int64 p = P - 2; while (p) { if (p % 2) { *this *= o; } o *= o; p /= 2; }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<FiniteField> factorials(n * m + 1);
  factorials[0] = 1;
  for (int i = 1; i <= n * m; i++) {
    factorials[i] = factorials[i - 1] * i;
  }

  FiniteField ans = 0;
  FiniteField x_base = 0, y_base = 0;
  for (int dx = 1; dx <= m - 1; dx++) {
    x_base += FiniteField(n) * n * (m - dx) * dx;
  }
  for (int dy = 1; dy <= n - 1; dy++) {
    y_base += FiniteField(m) * m * (n - dy) * dy;
  }
  ans = x_base + y_base;
  // cout << ans.Value() << endl;

  ans *= factorials[n * m - 2];
  ans /= factorials[k - 2];
  ans /= factorials[n * m - k];
  cout << ans.Value() << endl;
}
