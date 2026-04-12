#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <functional>
#include <utility>
using ll = long long;
ll ha;
inline ll pow_mod(ll a, ll b, const ll &mod) {
  ll ans = 1, res = a;
  while(b) {
    if(1LL & b) ans = ans * res % mod;
    res = res * res % mod; b >>= 1;
  }
  return ans;
}

const int maxn = 3005;

ll f[maxn][maxn], C[maxn][maxn];
ll tp_1[maxn], tp_2[maxn];
int n;
inline void process() {
  C[0][0] = 1;
  for(int i = 1; i <= n; i ++) {
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; j ++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if(C[i][j] >= ha) C[i][j] -= ha;
    }
  }
  f[0][0] = 1;
  for(int i = 1; i <= n; i ++) {
    for(int j = 0; j <= i; j ++) {
      f[i][j] = f[i - 1][j] * (j + 1) % ha;
      if(j > 0) {
        f[i][j] += f[i - 1][j - 1];
        if(f[i][j] >= ha) f[i][j] -= ha;
      }
    }
  }
  tp_1[0] = 1;
  for(int i = 1; i <= n; i ++) {
    tp_1[i] = (tp_1[i - 1] << 1);
    if(tp_1[i] >= ha) tp_1[i] -= ha;
  }
  tp_2[0] = 1;
  for(int i = 1; i <= n; i ++) {
    tp_2[i] = (tp_2[i - 1] << 1);
    if(tp_2[i] >= ha - 1) tp_2[i] -= ha - 1;
  }
}

int main() {
  scanf("%d%lld", &n, &ha);
  process();
  ll ret = 0;
  for(int i = 0; i <= n; i ++) {
    ll ans = 0; ll tp = tp_1[n - i], val = 1;
    for(int j = 0; j <= i; j ++) {
      ans = (ans + val * f[i][j]) % ha;
      val = val * tp % ha;
    }
    ans = ans * C[n][i] % ha * pow_mod(2, pow_mod(2, n - i, ha - 1), ha) % ha;
#ifdef LOCAL
    printf("val %d : %lld\n", i, ans);
#endif
    if(i & 1) ret += (- ans + ha);
    else ret += ans;
    if(ret >= ha) ret -= ha;
  }
  printf("%lld\n", ret);
  return 0;
}