#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int ans;
int dp[10002][102][2];
char s[10002];
int d;

int main()
{
  cin >> (s + 1);
  cin >> d;
  int n = strlen(s + 1);
  reverse(s + 1,s + n + 1);
  dp[0][0][1] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < d; j++)
      for (int leq = 1; leq >= 0; leq--)
        for (int cif = 0; cif < 10; cif++) {
          int nextleq = (cif < s[i + 1] - '0' || (cif == s[i + 1] - '0' && leq));
          dp[i + 1][(j + cif) % d][nextleq] += dp[i][j][leq];
          dp[i + 1][(j + cif) % d][nextleq] %= mod;
        }
  cout << (dp[n][0][1] - 1 + mod) % mod;
  return 0;
}
