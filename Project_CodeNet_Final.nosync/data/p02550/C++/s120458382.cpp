#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <time.h>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define all(c) (c).begin(), (c).end()
#define P pair<int, int>
#define chmin(x, y) x = min(x, y)

const int p = 998244353;

int in_vec(vector<ll> vec, ll y)
{
  ll ret = -1;
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i] == y)
    {
      ret = i;
    }
  }
  return ret;
}

int main()
{
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> vec;
  vec.push_back(x);
  ll y = (x * x) % m;
  while (in_vec(vec, y) == -1)
  {
    vec.push_back(y);
    y = (y * y) % m;
  }
  ll lp_init = in_vec(vec, y);
  ll lp = vec.size() - lp_init;
  ll lp_init_sum = 0;
  for (int i = 0; i < lp_init; i++)
  {
    lp_init_sum += vec[i];
  }
  ll lp_sum = 0;
  for (int i = 0; i < lp; i++)
  {
    lp_sum += vec[lp_init + i];
  }

  ll ans = 0;
  if (n < lp_init)
  {
    for (int i = 0; i < n; i++)
    {
      ans += vec[i];
    }
  }
  else
  {
    ans = lp_init_sum + ((n - lp_init) / lp) * lp_sum;
    for (int i = 0; i < (n - lp_init) % lp; i++)
    {
      ans += vec[lp_init + i];
    }
  }
  cout << ans << endl;
}
