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

typedef long double ld;

const int N = 3e3 + 7;

int n;
vector <int> a;
ll dp[N][N];

ll solve(int l, int r) {
  if (l > r) {
    return 0;
  }
  auto &res = dp[l][r];
  if (res != -1) {
    return res;
  }
  int step = n - 1 - r + l;
  step %= 2;
  if (l == r) {
    if (step ^ 1) {
      return res = a[l];
    }
    return res = 0;
  }
  res = 0;
  if (step ^ 1) {
    res = max(res, solve(l + 1, r) + a[l]);
    res = max(res, solve(l, r - 1) + a[r]);
  } else {
    res = min(solve(l + 1, r), solve(l, r - 1));
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n;
  a.resize(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  solve(0, n - 1);
  cout << 2 * dp[0][n - 1] - sum << '\n';
  return 0;
}