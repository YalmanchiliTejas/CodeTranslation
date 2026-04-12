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

int main()
{
  ll n;
  int x, m;
  cin >> n >> x >> m;
  vector<int> a;
  map<int, int> mp;
  int cnt = 0;
  ll tot = 0;
  while (mp.count(x) == 0)
  {
    a.push_back(x);
    mp[x] = cnt;
    tot += x;
    x = (ll)x * x % m;
    cnt++;
  }
  if (n <= cnt)
  {
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += a[i];
    }
    cout << ans << endl;
    return 0;
  }
  ll c = 0;
  for (int i = mp[x]; i < cnt; i++)
  {
    c += a[i];
  }
  ll ans = tot;
  int lp = cnt - mp[x];
  n -= cnt;
  ans += n / lp * c;
  n %= lp;
  for (int i = 0; i < n; i++)
  {
    ans += a[mp[x] + i];
  }
  cout << ans << endl;
}
