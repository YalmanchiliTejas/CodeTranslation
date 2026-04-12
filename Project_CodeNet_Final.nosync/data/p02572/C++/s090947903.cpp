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
   while (T--)
   {
      int n;
      cin >> n;
      int a[n];
      int sum = 0;
      for (int i = 0; i < n; i++)
         cin >> a[i], sum += a[i];
      int ans = 0;
      for (int i = 0; i < n - 1; i++)
      {
         sum -= a[i];
         ans += ((a[i] % mod) * (sum % mod)) % mod;
         ans %= mod;
      }
      cout << ans << "\n";
   }
   return 0;
}