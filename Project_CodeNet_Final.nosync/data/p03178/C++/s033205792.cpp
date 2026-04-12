#include <bits/stdc++.h>

using namespace std;

const int K = 1e4 + 10;
const int D = 110;
const int mod = 1e9 + 7;

int dp[K][D];
int d;
string str;

int f(int x, int s) {
  if (x < 0) return s % d == 0 ? 1 : 0;
  int res = 0;
  for (int i = 0; i < str[x] - '0'; i++)
    res = (res + dp[x][(((-s - i) % d) + d) % d]) % mod;
  res = (res + f(x - 1, s + str[x] - '0')) % mod;
  return res;
}

int main() {
  cin >> str >> d;
  reverse(str.begin(), str.end());
  dp[0][0] = 1;
  for (int i = 1; i < K; i++)
    for (int j = 0; j < d; j++)
      for (int digit = 0; digit < 10; digit++)
        dp[i][j] = (dp[i][j] + dp[i - 1][((j - digit + d) % d + d) % d]) % mod;

  cout << (mod - 1 + f(str.size() - 1, 0)) % mod << endl;

  return 0;
}