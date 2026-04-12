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

const int MAXN = 1050;
const int mod = (int) 1e9 + 7;

int n;
int a, b, c, d;
int f[MAXN];
int dp[MAXN][MAXN];
int g[MAXN][MAXN];

int addMod(int a, int b) {
  int sum = a + b;
  return sum >= mod ? sum - mod : sum;
}

int subMod(int a, int b) {
  int res = a - b;
  return res < 0 ? res + mod : res;
}

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

long long getC(int n, int k) {
  long long res = 1ll * f[n] * inv(f[n - k]) % mod;
  res = 1ll * res * inv(f[k]) % mod;
  return res;
}

int main() { 

  cin >> n >> a >> b >> c >> d;

  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = 1ll * f[i - 1] * i % mod;
  }
  
  dp[a - 1][0] = 1;
  for (int i = a; i <= b; i++) {
    dp[i][0] = 1;

     g[i][0] = 1;
    for (int j = 1; j <= n; j++) {
      if (j < i) {
        g[i][j] = 1;
      } else {
        g[i][j] = 1ll * g[i][j - i] * getC(j - 1, i - 1) % mod;
      }
    }

    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];

       for (int k = j - c * i; k >= 0 && k >= j - d * i; k -= i) {
        long long x = 1ll * dp[i - 1][k] * g[i][j - k] % mod;
        x = x * getC(j, j - k) % mod;
        dp[i][j] = (dp[i][j] + x) % mod;
      }

      // cerr << i << " " << j << " " << dp[i][j] << endl;
    } 
  }

  cout << dp[b][n] << endl;

  return 0;
}
