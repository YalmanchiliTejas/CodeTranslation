#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int MAXN = 3050;

int mod = (int) 1e9 + 7;

long long binpow(long long x, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      res = (res * x) % mod;
      p--;
    } else {
      x = (x * x) % mod;
      p /= 2;
    }
  }
  return res % mod;
}

long long inv(long long x) {
  return binpow(x, mod - 2) % mod;
}

long long f[MAXN], invF[MAXN];
long long t[MAXN];

long long cnk(long long n, long long k) {
  long long res = 1ll * f[n] * invF[k] % mod;
  res = res * invF[n - k] % mod;
  return res;
}

int subMod(int a, int b) {
  int res = a - b;
  return res < 0 ? res + mod : res;
}

int n;
long long dp[MAXN];
long long dp2[MAXN][MAXN];

int main() { 

  scanf("%d %d", &n, &mod);

  f[0] = 1; invF[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = 1ll * i * f[i - 1] % mod;
    invF[i] = inv(f[i]);
  }

  t[0] = 2;
  for (int i = 1; i <= n; i++) {
    t[i] = 1ll * t[i - 1] * t[i - 1] % mod;
  }

  dp2[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        dp2[i][j] = 1;
        continue;
      }
      dp2[i][j] = (dp2[i - 1][j] + dp2[i - 1][j - 1]) % mod;
      dp2[i][j] = (dp2[i][j] + 1ll * dp2[i - 1][j] * j % mod) % mod;
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      long long cur = dp2[i][j];
      cur = cur * binpow(2, j * (n - i)) % mod;
      cur = cur * t[n - i] % mod;
      dp[i] = (dp[i] + cur) % mod;
    }
  }

  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    long long cur = cnk(n, i) * dp[i] % mod;
    if (i % 2 == 0) {
      ans = (ans + cur) % mod;
    } else {
      ans = subMod(ans, cur) % mod;
    }
  }

  cout << ans << endl;

  return 0;
}
