#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
const long long MAXN = 1e3 + 10;


vector<vector<long long>> fact(MAXN, vector<long long> (MAXN, 0)), invFact(MAXN, vector<long long> (MAXN, 0));

long long gcdex(long long a, long long b, long long *x, long long *y)
{
  if(a == 0)
  {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long g = gcdex(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return g;
}

long long invMod(long long a)
{
  long long x, y;
  long long g = gcdex(a, MOD, &x, &y);
  assert(g == 1);
  long long ans = (x % MOD + MOD) % MOD;
  return ans;
}

void calc()
{
  fact[0][1] = invFact[0][1] = 1;
  for(long long i = 1; i < MAXN; i++)
  {
    fact[i][1] = (fact[i - 1][1] * i) % MOD;
    invFact[i][1] = invMod(fact[i][1]);
  }
  for(long long i = 2; i < MAXN; i++)
  {
    for(long long j =  0; j < MAXN; j++)
    {
      fact[j][i] = (fact[j][i - 1] * fact[j][1]) % MOD;
      invFact[j][i] = (invFact[j][i - 1] * invFact[j][1]) % MOD;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  calc();
  long long n;
  cin >> n;
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<vector<long long>> dp(n + 1, vector<long long> (b - a + 2, 0));
  dp[0][0] = 1;
  for(long long i = 1; i <= b - a + 1; i++)
  {
    for(int k = 0; k <= n; k++)
    {
      dp[k][i] += dp[k][i - 1];
    }
    long long box = i + a - 1;
    for(long long j = c; j <= d && (j * box) <= n; j++)
    {
      for(long long k = 0; k <= n; k++)
      {
        if(j * box + k <= n)
        {
          long long add = (fact[n - k][1] * invFact[n - k - j * box][1]) % MOD;
          (add *= invFact[box][j]) %= MOD;
          (add *= dp[k][i - 1]) %= MOD;
          (add *= invFact[j][1]) %= MOD;
          (dp[j * box + k][i] += add) %= MOD;
        }
      }
    }
  }
  cout << dp[n][b - a + 1] << endl;
  return 0;
}
