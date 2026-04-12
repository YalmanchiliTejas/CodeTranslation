#include <stdio.h>
#include <assert.h>
#include <vector>
using namespace std;

struct ModularInt {
  int val;
  const static int mod = 1e9 + 7;

  ModularInt() {
    val = 0;
  }

  ModularInt(int _val) {
    val = _val;
  }

  ModularInt(const ModularInt &other) {
    val = other.val;
  }

  void operator = (ModularInt other) {
    val = other.val;
  }

  void operator = (int other) {
    val = other;
  }

  ModularInt operator + (ModularInt other) const {
    int x = val + other.val;
    return (x >= mod ? ModularInt(x - mod) : ModularInt(x));
  }

  ModularInt operator + (int other) const {
    int x = val + other;
    return (x >= mod ? ModularInt(x - mod) : ModularInt(x));
  }

  void operator += (ModularInt other) {
    val += other.val;
    if (val >= mod) {
      val -= mod;
    }
  }

  void operator += (int other) {
    val += other;
    if (val >= mod) {
      val -= mod;
    }
  }

  ModularInt operator - (ModularInt other) const {
    int x = val - other.val;
    return (x < 0 ? ModularInt(x + mod) : ModularInt(x));
  }

  ModularInt operator - (int other) const {
    int x = val - other;
    return (x < 0 ? ModularInt(x + mod) : ModularInt(x));
  }

  void operator -= (ModularInt other) {
    val -= other.val;
    if (val < 0) {
      val += mod;
    }
  }

  void operator -= (int other) {
    val -= other;
    if (val < 0) {
      val += mod;
    }
  }

  ModularInt operator * (ModularInt other) const {
    return ModularInt((1LL * val * other.val) % mod);
  }

  ModularInt operator * (int other) const {
    return ModularInt((1LL * val * other) % mod);
  }

  void operator *= (ModularInt other) {
    val = (1LL * val * other.val) % mod;
  }

  void operator *= (int other) {
    val = (1LL * val * other) % mod;
  }

  ModularInt operator / (ModularInt other) const {
    return ModularInt((1LL * val * ModularInt::inverse(other.val)) % mod);
  }

  ModularInt operator / (int other) const {
    return ModularInt((1LL * val * ModularInt::inverse(other)) % mod);
  }

  void operator /= (ModularInt other) {
    val = (1LL * val * ModularInt::inverse(other.val)) % mod;
  }

  void operator /= (int other) {
    val = (1LL * val * ModularInt::inverse(other)) % mod;
  }

  static int power(int x, int y) {
    int ans = 1;
    assert(y >= 0);
    for ( ; y > 0; y >>= 1) {
      if (y & 1) {
        ans = (1LL * ans * x) % mod;
      }
      x = (1LL * x * x) % mod;
    }
    return ans;
  }

  static int inverse(int x) {
    return ModularInt::power(x, mod - 2);
  }
};

ModularInt choose(int n, int k) {
  vector<ModularInt> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
  }
  return fact[n] / (fact[k] * fact[n - k]);
}

ModularInt get_all_pair_dist(int n, int m) {
  vector<int> x, y;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      x.push_back(j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      y.push_back(i);
    }
  }
  ModularInt ans(0), sum(0);
  for (int i = 0; i < n * m; i++) {
    ans += ((1LL * x[i] * i) % ModularInt::mod);
    ans += ((1LL * y[i] * i) % ModularInt::mod);
    ans -= sum;
    sum += x[i] + y[i];
  }
  return ans;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  ModularInt ans(choose(n * m - 2, k - 2) * get_all_pair_dist(n, m));
  printf("%d\n", ans.val);
  return 0;
}