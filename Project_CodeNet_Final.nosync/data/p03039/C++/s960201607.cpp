#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, MOD = 1e9 + 7;
int fac[N], inv[N];
int fpow(int a, int b) {
  int ans = 1;
  for(; b > 0; b >>= 1, a = 1ll * a * a % MOD) {
    if(b & 1) ans = 1ll * ans * a % MOD;
  }
  return ans;
}
// 快乐取模大法 会快一点点 全用long long取模也可以
void add(int &x, int y) {
  x += y;
  if(x >= MOD) x -= MOD;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  fac[0] = 1;
  for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
  inv[N - 1] = fpow(fac[N - 1], MOD - 2);
  for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
  assert(inv[0] == 1);
  const int INV2 = 1ll * inv[2] * fac[1] % MOD; // 2^{-1} = (2!)^{-1} * (1!)
  // 上面是O(n)预处理阶乘和阶乘的逆元，当然这题也可以只计算某几个阶乘的逆元
  int n, m, k, ans = 0; cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    add(ans, 1ll * i * (i + 1) % MOD * INV2 % MOD * m % MOD * m % MOD);
  }
  for(int i = 0; i < m; i++) {
    add(ans, 1ll * i * (i + 1) % MOD * INV2 % MOD * n % MOD * n % MOD);
  }
  cout << (1ll * ans * fac[n * m - 2] % MOD * inv[k - 2] % MOD * inv[n * m - k] % MOD) << "\n";
}