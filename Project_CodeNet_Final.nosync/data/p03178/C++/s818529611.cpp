#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int mod = 1e9 + 7;

string K;
int D;

int64 dp[10000][100][2];

int64 rec(int idx, bool free, int sum) {
  if(idx == K.size()) return sum == 0;
  if(~dp[idx][sum][free]) return dp[idx][sum][free];
  int64 ret = 0;
  for(int i = free ? K[idx] - '0' : 9; i >= 0; i--) {
    ret += rec(idx + 1, free & (i == K[idx] - '0'), (sum + i) % D);
    ret %= mod;
  }
  return dp[idx][sum][free] = ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> K >> D;
  cout << (rec(0, true, 0) + mod - 1) % mod << endl;
}

