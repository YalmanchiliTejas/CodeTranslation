// Copyright lzt
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<queue>
#include<string>
#include<ctime>
using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<long long, long long> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, j, k)  for (register int i = (int)(j); i <= (int)(k); i++)
#define rrep(i, j, k) for (register int i = (int)(j); i >= (int)(k); i--)
#define Debug(...) fprintf(stderr, __VA_ARGS__)

inline ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  return x * f;
}

const int mod = 1e9 + 7;
string k;
int d;
int f[10010][110][2];

void work() {
  cin >> k >> d;
  f[0][0][0] = 1;
  rep(i, 0, k.size() - 1) {
    rep(j, 0, d - 1) {
      rep(a, 0, 1) {
        if (!f[i][j][a]) continue;
        // cout<<i<<' '<<j<<' '<<a<<' '<<f[i][j][a]<<endl;
        int mx = 9;
        if (!a) mx = k[i] - '0';
        rep(x, 0, mx) {
          (f[i+1][(j+x) % d][a | (x < mx)] += f[i][j][a]) %= mod;
        }
      }
    }
  }
  cout<<(f[k.size()][0][0] + f[k.size()][0][1] - 1 + mod) % mod<<endl;
}

int main() {
  #ifdef LZT
    freopen("in", "r", stdin);
  #endif

  work();

  #ifdef LZT
    Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
  #endif
}
