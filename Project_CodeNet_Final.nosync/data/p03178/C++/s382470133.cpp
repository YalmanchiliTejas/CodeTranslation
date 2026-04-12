#include <bits/stdc++.h>
using namespace std;
const int md = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
inline int mul(int a, int b) {
  return (int)((long long)a * b % md);
}
inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
      b--;
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
inline int inv(int a) {
  a %= md;
  if(a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= a * t; swap(a, b);
    u -= v * t; swap(u, v);
  }
  assert(b == 1);
  if(u < 0) u += md;
  return u;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string n;
  cin >> n;
  int l = n.length();
  int d;
  cin >> d;
  vector<vector<int>> dp(l, vector<int>(d, 0));
  dp[0][0] = 1;
  for (int i = 1; i < l; i++)
  {
    for (int c = 0; c < 10; c++)
    {
      for (int crr = 0; crr < d; crr++)
      {
        int nxt = (crr + c) % d;
        add(dp[i][nxt], dp[i - 1][crr]);
      }
    }
  }

  int ans = 0;
  int res = 0;
  for (int i = 0; i < l; i++)
    {
    int c = n[i] - '0';
    while(c--){
      add(ans, dp[l - 1 - i][res]);
      res--;
      if (res < 0) {
        res += d;
      }
    }
  }
  if (res == 0) {
    add(ans, 1);
  }
  sub(ans, 1);
  cout << ans << '\n';
  return 0;
}
