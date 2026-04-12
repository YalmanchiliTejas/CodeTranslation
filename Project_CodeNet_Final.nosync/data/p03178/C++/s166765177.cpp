#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

inline int mul(int a, int b) {
  return (a * (ll) b) % mod;
}

inline int pw(int x, int n) {
  int res = 1;
  while (n > 0) {
    if (n % 2) {
      res = mul(res, x);
      n--; 
    } else {
      x = mul(x, x);
      n /= 2;
    }
  }
  return res;
}

const int N = 1e4 + 7;
const int K = 107;

int dp[N][K][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int d;
  cin >> d;
  vector <int> pw = {1};
  for (int i = 0; i < N; i++) {
    pw.push_back(pw.back() * 10);
    pw.back() %= d;
  }
  int n = (int) s.size();
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int f = 0; f < 2; f++) {
      int lmt = (f ? 9 : (s[i] - '0'));
      for (int dg = 0; dg <= lmt; dg++) {
        for (int x = 0; x < d; x++) {
          int nf = (dg < s[i] - '0' || f ? 1 : 0); 
          add(dp[i + 1][(x + dg) % d][nf], dp[i][x][f]);
        }
      }
    }
  }
  int ans = dp[n][0][0];
  add(ans, dp[n][0][1]);
  add(ans, -1);
  cout << ans << '\n';
  return 0;
}