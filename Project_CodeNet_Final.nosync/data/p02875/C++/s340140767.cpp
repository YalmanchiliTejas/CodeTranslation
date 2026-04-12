#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

constexpr int64 P = 998244353;

struct FiniteField {
 private:
  int64 x;
 public:
  FiniteField(int64 x) : x(x) {
    if (x > P || x < 0) { cerr << "Invalied FiniteField!" << endl; exit(1); }
  }
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<FiniteField> factorials(n + 1);
  vector<FiniteField> inverse_factorials(n + 1);

  factorials[0] = inverse_factorials[0] = 1;
  for (int i = 1; i <= n; i++) {
    factorials[i] = factorials[i - 1] * i;
    inverse_factorials[i] = FiniteField(1) / factorials[i];
  }

  vector<FiniteField> two_powers(n + 1);
  two_powers[0] = 1;
  for (int i = 1; i <= n; i++) {
    two_powers[i] = two_powers[i - 1] * 2;
  }

  FiniteField z = 0;
  for (int k = n / 2 + 1; k <= n; k++) {
    z += factorials[n] * inverse_factorials[k] * inverse_factorials[n - k]
        * two_powers[n - k];
  }
  
  FiniteField ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= 3;
  }
  ans -= z * 2;
  cout << ans.Value() << endl;
}