#include <bits/stdc++.h>

using namespace std;
using Int = long long;

const int nax = 10005;

string s;
int D;

const int mod = int(1e9 + 7);

void add(int &a, int b) {
  a += b;
  if(a >= mod) a -= mod;
}

int dp[nax][101][2];

int rec(int pos, int sum, int cross) {
  if(pos == (int) s.length()) {
    return sum == 0;
  }
  if(dp[pos][sum][cross] != -1) {
    return dp[pos][sum][cross];
  }
  int x = 0;
  for(int d = 0; d < 10; ++d) {
    if(cross && d > (s[pos] - '0')) {
      break;
    }
    add(x, rec(pos + 1, (sum + d) % D, cross && d == (s[pos] - '0')));
  }
  return dp[pos][sum][cross] = x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s >> D;
  int res = 0;
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < (s[0] - '0'); ++i) {
    add(res, rec(1, i % D, 0));
  }
  add(res, rec(1, (s[0] - '0') % D, 1));
  cout << (res - 1 + mod) % mod << '\n';
  return 0;
}
