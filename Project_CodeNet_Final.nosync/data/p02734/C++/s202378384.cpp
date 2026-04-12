#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int add() { return 0; }
template<typename... M> int add(int a, M... b) {
  int x = add(b...);
  return a + x - mod * (a + x >= mod);
}

int mul() { return 1; }
template<typename... M> int mul(int a, M... b) {
  return int(1ll * a * mul(b...) % mod);
}

int pwr(int a, long long x) {
  return (x ? mul(pwr(mul(a, a), x >> 1), (x & 1 ? a : 1)) : 1);
}

int dvd(int a, int b) {
  return mul(a, pwr(b, mod - 2));
}

int sub(int a, int b) {
  return a - b + mod * (a < b);
}

void inc(int& a, int b) {
  a = add(a, b);
}

void dec(int& a, int b) {
  a = sub(a, b);
}

const int N = 3030;
int dp[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, s;
  cin >> n >> s;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    dp[i][0] = i + 1;
    for (int j = 0; j <= s; ++j) {
      if (j > 0 and j < s) {
        inc(dp[i + 1][j], dp[i][j]);
      }
      if (j + x <= s) {
        inc(dp[i + 1][j + x], dp[i][j]);
      }
    }
    inc(ans, mul(dp[i + 1][s], n - i));
  }
  cout << ans;

  return 0;
}