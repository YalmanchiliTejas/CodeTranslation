#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define AB_BHI_NI_DEGI               \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);                    \
   cout.tie(NULL);
#define int long long
#define pb push_back
#define N 100009
#define inf 1e18
const double PI = 3.141592653589793238462643383279;
int mod = 1e9 + 7;
//int mod = 998244353;
#define P pair<int, int>
#define F first
#define S second
#define ll long long
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define ld long double
#define endl "\n"

#define ordered_set tree<P, null_type, less<P>, rb_tree_tag, tree_order_statistics_node_update>

int power(int a, int n, int m)
{
   int res = 1;
   int ans = 0;
   while (n)
   {
      if (n % 2)
         res = (res * a) % m;
      a = (a * a) % m;
      n = n / 2;
      ans += a;
   }
   return res;
}
int32_t main()
{
   AB_BHI_NI_DEGI
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
   //cout.precision(20);
   //cout << fixed;
   int T = 1;
   //cin >> T;
   int cnt = 1;
   //sieve();
   while (T--)
   {
      int n, x, m;
      cin >> n >> x >> m;
      int ans = x;
      int prev = x;
      map<int, int> mp;
      mp[x] = 1;
      int s = -1;
      int i;
      for (i = 1; i < n; i++)
      {
         int x = (prev * prev) % m;
         if (mp.count(x))
         {
            s = x;
            break;
         }
         mp[x]++;
         prev = x;
         ans += x;
      }
      if (s == -1)
      {
         cout << ans << "\n";
         continue;
      }
      ans = x;
      prev = x;
      for (i = 1; i < n; i++)
      {
         int x = (prev * prev) % m;
         if (x == s)
            break;
         ans += x;
         prev = x;
      }
      int cy = 0, cyl = 0;
      mp.clear();
      while (1)
      {
         int x = (prev * prev) % m;
         if (mp.count(x))
            break;
         cy += x;
         prev = x;
         mp[x]++;
         cyl++;
      }
      int len = n - i;
      int y = len / cyl;
      ans += y * cy;
      int rem = len % cyl;
      while (rem--)
      {
         int x = (prev * prev) % m;
         ans += x;
         prev = x;
      }
      cout << ans << "\n";
   }
   return 0;
}