#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <assert.h>

using namespace std;

#define ll long long
#define rep(i, n) for (i = 0; i < n; i++)

const ll p = 998244353;

int main()
{
  ll N, S;
  cin >> N >> S;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  vector<ll> dp(S + 1, 0), dp_prev(S + 1);
  ll ans = 0;

  if (A[0] <= S)
    dp[A[0]] = 1;
  for (ll i = 0; i < N; i++)
  {
    ans += dp[S] * (N - i);
    ans %= p;
    if (i == N - 1)
      break;
    dp_prev = dp;
    dp_prev[S] = 0;
    dp.assign(S + 1, 0);
    if (A[i + 1] <= S)
    {
      dp[A[i + 1]] = i + 2;
      for (ll j = 0; j < A[i + 1]; j++)
      {
        dp[j] += dp_prev[j];
      }
      for (ll j = A[i + 1]; j <= S; j++)
      {
        dp[j] += dp_prev[j] + dp_prev[j - A[i + 1]];
      }
    }
    else
    {
      for (ll j = 0; j <= S; j++)
      {
        dp[j] += dp_prev[j];
      }
    }
    for (ll j = 0; j <= S; j++)
    {
      dp[j] %= p;
    }
  }

  cout << ans << endl;
}
