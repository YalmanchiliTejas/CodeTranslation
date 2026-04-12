#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3010;
int mod;

int mul(int x, int y) {
  return 1ll * x * y % mod;
}

void Mul(int &x, int y) {
  x = mul(x, y);
}

int add(int x, int y) {
  return (x += y) > mod ? x - mod : x;
}

void Add(int &x, int y) {
  x = add(x, y);
}

int sub(int x, int y) {
  return (x -= y) < 0 ? x + mod : x;
}

void Sub(int &x, int y) {
  x = sub(x, y);
}

int q_pow(int x, int y) {
  int ans = 1;
  for(; y; y >>= 1) {
    if(y & 1) Mul(ans, x);
    Mul(x, x);
  }
  return ans;
}

int f[N], g[N][N], ny[N], jc[N];

int C(int x, int y) {
  return mul(jc[x], mul(ny[y], ny[x - y]));
}

void init() {
  ny[0] = jc[0] = 1;
  for(int i = 1; i < N; ++i) jc[i] = mul(jc[i - 1], i);
  ny[N - 1] = q_pow(jc[N - 1], mod - 2);
  for(int i = N - 2; i >= 0; --i)
    ny[i] = mul(ny[i + 1], i + 1);
}

int pw[N * N], P[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  mod = m;
  init();
  pw[0] = 1;
  for(int i = 1; i <= n * n; ++i) pw[i] = mul(pw[i - 1], 2);
  P[0] = 1;
  for(int i = 1; i <= n; ++i) P[i] = 1ll * P[i - 1] * 2 % (mod - 1); //zhishu!!!!! 2^n = 2 ^{n % (mod - 1)};
  for(int i = 0; i <= n; ++i) g[i][0] = 1;
  for(int i = 1; i <= n; ++i)
   for(int j = 1; j <= n; ++j) {
    g[i][j] = add(g[i - 1][j - 1], mul(g[i - 1][j], j + 1));
   }
  for(int i = 0; i <= n; ++i) {
    for(int j = 0; j <= i; ++j) {
      Add(f[i], mul(g[i][j], pw[(n - i) * j]));
    }
    Mul(f[i], q_pow(2, P[n - i]));
  }
  int ans = 0;
  for(int i = 0; i <= n; ++i) {
    if(i & 1) Sub(ans, mul(f[i], C(n, i)));
    else Add(ans, mul(f[i], C(n, i)));
  }
  printf("%d\n", ans);
  return 0;
}
// 50 111111113
//1456748