#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

bool flag[3001][3001] = {};
int n;
ll dp[3001][3001] = {};
ll a[3000] = {};

// [i,j)
ll memo(int i, int j)
{
  if (i >= j)
    return 0;
  if (flag[i][j])
    return dp[i][j];
  if (abs(j - i) % 2 == n % 2)
    dp[i][j] = max(a[i] + memo(i + 1, j), a[j - 1] + memo(i, j - 1));
  else
    dp[i][j] = min(-a[i] + memo(i + 1, j), -a[j - 1] + memo(i, j - 1));
  flag[i][j] = true;
  return dp[i][j];
}

int main()
{
  cin >> n;
  REP(i, n)
  {
    cin >> a[i];
  }

  cout << memo(0, n) << endl;
}
