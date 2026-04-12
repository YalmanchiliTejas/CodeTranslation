#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;

const ll mod = 1e9 + 7;
const int N = 2e5 + 10;
ll fac[N], inv[N], finv[N];
int n, m, k;
ll ans = 0;

ll brute(int n, int m, int k) {
  ll mult = fac[n * m - 2] * finv[k - 2] % mod * finv[n * m - k] % mod;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < m; l++) {
          if (i * m + j >= k * m + l) {
            ans += (abs(i - k) + abs(j - l)) * mult;
            ans %= mod;
          }
        }
      }
    }
  }
  return ans;
}

ll fix(ll x) {
  x %= mod;
  x += mod;
  x %= mod;
  return x;
}
int main() {

  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i=2; i < N; i++){
    fac[i] = (i * fac[i-1]) % mod;
    inv[i] = (mod - (mod/i) * inv[(mod%i)] % mod) % mod;
    finv[i] = (inv[i] * finv[i-1]) % mod;
  }


  cin >> n >> m >> k;
  
  ll mult = fac[n * m - 2] * finv[k - 2] % mod * finv[n * m - k] % mod;

  vector<vector<ll>> nw(n, vector<ll>(m, 0ll));
  vector<vector<ll>> ne(n, vector<ll>(m, 0ll));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      nw[i][j] += i + j;
      if (i > 0) nw[i][j] += nw[i - 1][j];
      if (j > 0) nw[i][j] += nw[i][j - 1];
      if (i > 0 && j > 0) nw[i][j] -= nw[i - 1][j - 1];
      ans += mult * fix((i + 1) * (j + 1) * 1ll * (i + j) - nw[i][j]) % mod;
      ans %= mod;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      ne[i][j] += i + (m - 1 - j);
      if (i > 0) ne[i][j] += ne[i - 1][j];
      if (j < m - 1) ne[i][j] += ne[i][j + 1];
      if (i > 0 && j < m - 1) ne[i][j] -= ne[i - 1][j + 1];
      
      if (i > 0 && j + 1 < m) {
        ans += mult * (fix(i * (m - 1 - j) * 1ll * (i + (m - 1 - j)) - ne[i - 1][j + 1])) % mod;
        ans %= mod;
      }
    }
  }
  cout << ans << endl;
  return 0;
}