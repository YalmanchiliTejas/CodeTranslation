#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 111;
const int mod = 1e9 + 7;

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
}

int Pow(int x, int y) {
  int res = 1;
  for(; y; y >>= 1, x = x * x % mod) {
    if(y & 1) {
      res = res * x % mod;
    }
  }
  return res;
}

int n, H[N], dp[N][N][2][2][2];
int Min[N][N];

int ans = 1;

bool vis[N][N];

int get(int l, int r) {
  int h = 2e9;
  for(int i = l; i <= r; ++ i) h = min(h, H[i]);
  return h;
}

void solve(int l, int r) {
  //cerr << l <<' ' << r << endl;
  if(vis[l][r]) return;
  vis[l][r] = 1;
  if(l == r) {
    dp[l][r][1][1][0] = dp[l][r][0][0][0] = 1;
    return;
  }
  if(l > r) {
    return;
  }
  int h = 2e9;
  for(int i = l; i <= r; ++ i) {
    h = min(h, H[i]);
  }
  int who = 0;
  for(int i = l; i <= r; ++ i) if(H[i] == h) who = i;
  //cerr << l <<" " << r << " " << who << endl;
  solve(l, who - 1);
  solve(who + 1, r);
  if(l > who - 1) {
    //cerr << l <<" " << r <<" " << "in" << endl;
    for(int a = 0; a < 2; ++ a) {
      for(int b = 0; b < 2; ++ b) {
        for(int c = 0; c < 2; ++ c) {
          for(int d = 0; d < 2; ++ d) {
            Add(dp[l][r][d][b][(d == a) || c],
                dp[who + 1][r][a][b][c] * Pow(2 - c, get(who + 1, r) - h) % mod);
          }
        } 
      }
    }
    //cerr << l <<" " << r << " " << "out" << endl;
    return;
  }
  if(who == r) {
    //cerr << l <<" " << r << " in" << endl;
    for(int a = 0; a < 2; ++ a) {
      for(int b = 0; b < 2; ++ b) {
        for(int c = 0; c < 2; ++ c) {
          for(int d = 0; d < 2; ++ d) {
            Add(dp[l][r][a][d][(d == b) || c],
                dp[l][who - 1][a][b][c] * Pow(2 - c, get(l, who - 1) - h) % mod);
          }
        }
      }
    }
      //cerr << l <<" " << r <<" out" << endl;
    return;
  }
  //cerr << l << " " << r <<" in" << endl;
  for(int a = 0; a < 2; ++ a) {
    for(int b = 0; b < 2; ++ b) {
      for(int c = 0; c < 2; ++ c) {
        for(int d = 0; d < 2; ++ d) {
          for(int e = 0; e < 2; ++ e) {
            for(int f = 0; f < 2; ++ f) {
              for(int g = 0; g < 2; ++ g) {
                Add(dp[l][r][a][f][(d == b) || (d == e) || c || g],
                    dp[l][who - 1][a][b][c] * dp[who + 1][r][e][f][g] % mod * Pow(2 - c, get(l, who - 1) - h) % mod * Pow(2 - g, get(who + 1, r) - h) % mod);
              }
            }
          }
        }
      }
    }
  }
  //cerr << l << " " << r <<" out" << endl;
  return;
}

main() {
  cin >> n;
  int h = 2e9;
  for(int i = 1; i <= n; ++ i) cin >> H[i], h = min(h, H[i]);
  solve(1, n);
  //cerr << "HERE" << endl;
  int ans = 0;
  for(int a = 0; a < 2; ++ a)
    for(int b = 0; b < 2; ++ b)
      for(int c = 0; c < 2;++ c)
        Add(ans, dp[1][n][a][b][c] * Pow(2 - c, h - 1) % mod);
  
  cout << ans << endl;
}
