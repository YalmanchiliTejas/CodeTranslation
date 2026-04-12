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
  ll n, x, m;
  cin >> n >> x >> m;
  vector<int> a;
  map<int, int> mp;
  int cnt = 0;
  ll tot = 0;
  while (mp.count(x) == 0)
  {
    a.push_back(x);
    mp[x] = cnt;
    cnt++;
    tot += x;
    x = x * x % m;
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
  ll ans = tot;
  ll s = 0; // 1ループの数値和
  for (int i = mp[x]; i < cnt; i++)
  {
    s += a[i];
  }
  ll t = cnt - mp[x];   // 1ループの長さ
  ll u = (n - cnt) / t; // ループの周回数
  ans += s * u;
  for (int i = mp[x]; i < n - (u + 1) * t; i++)
  {
    ans += a[i];
  }
  cout << ans << endl;
}
