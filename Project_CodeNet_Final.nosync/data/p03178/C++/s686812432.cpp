#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template<typename T>
vector<vector<vector<T>>>
Make3DVector(int d1, int d2, int d3, T default_value) {
  return vector<vector<vector<T>>>(
      d1,
      vector<vector<T>>(d2, vector<T>(d3, default_value)));
}

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

  string input;
  int mod;
  cin >> input >> mod;
  int n = input.size();

  auto dp = Make3DVector(n + 1, 2, mod, FiniteField(0));
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < mod; k++) {
        if (j == 0) {
          int cur_d = input[i] - '0';
          for (int d = 0; d < cur_d; d++) {
            dp[i + 1][1][(k + d) % mod] += dp[i][0][k];
          }
          dp[i + 1][0][(k + cur_d) % mod] += dp[i][0][k];
        } else {
          // j == 1
          for (int d = 0; d < 10; d++) {
            dp[i + 1][1][(k + d) % mod] += dp[i][1][k];
          }
        }
      }
    }
  }
  FiniteField ans = dp[n][0][0] + dp[n][1][0] - 1;
  cout << ans.Value() << endl;
}
