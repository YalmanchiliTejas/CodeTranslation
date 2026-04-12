#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <regex>
#include <numeric>
#include <queue>
#include <set>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

ll lis(ll n, vector<ll> a)
{
  vector<ll> dp(n);
  dp[0] = 1;
  ll res = dp[0];
  for (ll i = 1; i < n; i++)
  {
    if (a[i] < a[i - 1])
    {
      dp[i] = 1;
    }
    else
    {
      dp[i] = dp[i - 1] + 1;
    }
    res = max(res, dp[i]);
  }
  return res;
}

int main(int argc, char const *argv[])
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n)
  {
    cin >> a[i];
    a[i] = -a[i];
  }
  multiset<ll> color;
  color.insert(a[0]);
  for (ll i = 1; i < n; i++)
  {
    auto it = color.upper_bound(a[i]);
    if (it == color.end())
    {
      color.insert(a[i]);
    }
    else
    {
      color.erase(it);
      color.insert(a[i]);
    }
  }
  cout << color.size() << endl;
  return 0;
}
