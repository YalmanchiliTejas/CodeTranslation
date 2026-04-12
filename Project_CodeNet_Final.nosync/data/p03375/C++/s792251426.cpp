#include <bits/stdc++.h>

#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define vec vector<int>
#define dead not_bad
#define bad gooood

#define left not_right
#define y1 what

using namespace std;

const int N = (int) 3e3 + 10;
const int M = (int) 1e6 + 10;
const ll LINF = (ll) 1e18;
const int INF = (int) 1e9 + 7;
const int ALPHA = 26;
const int mod = INF + 2;
const double PI = 3.14159265359;
const ld EPS = (ld) 1e-12;

const int nx[4] = {0, 0, -1, 1};
const int ny[4] = {1, -1, 0, 0};

int n, m;

int mult(int x, int y, int mod) {
  return 1ll * x * y % mod;
}

int add(int x, int y, int mod) {
  x += y;
  if (x < 0)
    x += mod;
  if (x >= mod)
    x -= mod;
  return x;
}

int bp(int x, int y, int mod) {
  int ans = 1;
  while (y) {
    if (y % 2)
      ans = mult(ans, x, mod);
    x = mult(x, x, mod);
    y /= 2;
  }
  return ans;
}

int dp[N][N], c[N][N];

int f(int cnt, int k) {
  return dp[cnt][k];
}

int get(int i) {
  int ans = 0;
  for (int k = 0; k <= i; k++) {
    // k+1 -> mycopka
    ans = add(ans, mult(f(i, k), bp(2, mult(k, n - i, m - 1), m), m), m);
  }
  ans = mult(ans, bp(2, bp(2, n - i, m - 1), m), m);
  return ans;
}

int main() {
  #define fn "saddle"
  #ifdef witch
      freopen("input.txt", "r", stdin);
  //    freopen("output.txt", "w", stdout);
  #else
      //freopen(fn".in", "r", stdin);
      //freopen(fn".out", "w", stdout);
  #endif
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    dp[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1], m);
      dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j] * 1ll * (j + 1) % m, m);
    }
  }
  //cout << f(1, 1) << endl;
  //return 0;
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    //cout << i << ' ' << mult(c[n][i], get(i), m) << endl;
    if (i % 2 == 0)
      ans = add(ans, mult(c[n][i], get(i), m), m);
    else
      ans = add(ans, -mult(c[n][i], get(i), m), m);
  }
  cout << ans;
  return 0;
}
