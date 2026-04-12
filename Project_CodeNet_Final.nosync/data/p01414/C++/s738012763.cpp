#include <bits/stdc++.h>
#define len 4
#define inf 1e9
using namespace std;

struct data {
  int h, w;
};

long long n;
vector<long long> dp;
vector<data> v;
vector<string> c;
vector<vector<int>> num;

int calc(char x) {
  if(x == 'R') return 0;
  if(x == 'G') return 1;
  return 2;
}
long long solve(long long bit);

int main() {
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; ++i) cin >> v[i].h >> v[i].w;
  c.resize(len);
  for(int i = 0; i < len; ++i) cin >> c[i];
  num.assign(len, vector<int>(len, 0));
  for(int i = 0; i < len; ++i)
    for(int j = 0; j < len; ++j) num[i][j] = calc(c[i][j]);
  dp.assign(1 << (len * len), -1);
  dp[(1 << (len * len)) - 1] = 0;
  cout << solve(0) << endl;
  return 0;
}

long long solve(long long bit) {
  if(dp[bit] != -1) return dp[bit];
  long long res = inf;
  for(int i = 0; i < n; ++i)
    for(int col = 0; col < 3; ++col)
      for(int x = -3; x < len; ++x)
        for(int y = -3; y < len; ++y) {
          long long nextbit = bit;
          bool ch = 1;
          if(x + v[i].h <= 0 || y + v[i].w <= 0) continue;
          for(int j = 0; j < v[i].h; ++j)
            if(ch && x + j < len)
              for(int k = 0; k < v[i].w; ++k) {
                if(y + k >= len) break;
                if(x + j < 0 || y + k < 0) continue;
                int id = (x + j) * len + y + k;
                if(!(nextbit >> id & 1) &&
                   col == num[x + j][y + k])
                  nextbit += 1LL << id;
                if(!(nextbit >> id & 1) &&
                   col != num[x + j][y + k]) {
                  ch = 0;
                  break;
                }
              }
          if(nextbit == bit || !ch) continue;
          res = min(res, solve(nextbit));
        }

  return dp[bit] = res + 1;
}
