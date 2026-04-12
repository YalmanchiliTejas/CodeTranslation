#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long double ld;

const int mod = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mul(int a, int b) {
  return (a * (ll) b) % mod;
}

const int N = 3007;

int a[N];
int p[N][N];
int cnt[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cnt[0][0] = 1;
  cnt[0][a[0]] = 1;
  p[0][a[0]] = 1;
  ll ans = p[0][s];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= s; j++) {
      p[i][j] = p[i - 1][j];
      cnt[i][j] = cnt[i - 1][j];
    }
    for (int j = s; j >= a[i] + 1; j--) {
      add(p[i][j], p[i][j - a[i]]);
      add(cnt[i][j], cnt[i][j - a[i]]);
    }
    add(p[i][a[i]], i + 1);
    ans += p[i][s];
    ans %= mod;
  }
  cout << ans << '\n';
  return 0;
}