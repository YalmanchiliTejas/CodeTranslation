#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {
  return a + b - mod * (a + b >= mod);
}

int mul(int a, int b) {
  return int(1ll * a * b % mod);
}

int pwr(int a, int x) {
  if (x == 0) {
    return 1;
  }
  return mul(pwr(mul(a, a), x >> 1), (x & 1 ? a : 1));
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

const int N = 1e5 + 10, D = 110;
int dp[N][D][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s;
  int d;
  cin >> s >> d;
  for (char& c : s) {
    c -= '0';
  }
  int n = s.size();
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < d; ++j) {
      for (int k = 0; k < 2; ++k) {
        int r = (k ? 9 : s[i]);
        for (int t = 0; t <= r; ++t) {
          int nk = (t < s[i] ? 1 : k);
          inc(dp[i + 1][(j + t) % d][nk], dp[i][j][k]);
        }
      }
    }
  }
  cout << sub(add(dp[n][0][0], dp[n][0][1]), 1);

  return 0;
}