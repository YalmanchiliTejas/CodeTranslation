/*

  "With age, comes wisdom. With travel, comes understanding.
   Remember that happiness is a way of travel – not a destination"

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
     int x = 1;
     while (b)
     {
          if (b & 1) x *= a;
          a *= a;
          b >>= 1;
     }
     return x;
}

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 3005;
int a[N], n, m, k;
int cache[N][N][2];

int dp(int i, int j, int who)
{
     if (i > j)
          return 0;
     int &ans = cache[i][j][who];
     if (ans != -1)
          return ans;

     if (who)
     {
          ans = dp(i + 1, j, who ^ 1) - a[i];
          ans = min(ans, dp(i, j - 1, who ^ 1) - a[j]);
     }
     else
     {
          ans = dp(i + 1, j, who ^ 1) + a[i];
          ans = max(ans, dp(i, j - 1, who ^ 1) + a[j]);
     }
     return ans;

}

void solve()
{
     cin >> n;
     for (int i = 1; i <= n; i++)
          cin >> a[i];

     memset(cache, -1, sizeof cache);
     cout << dp(1, n, 0);

}

int32_t main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cout << setprecision(9) << fixed;
     clock_t z = clock();
     solve();
     cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

     return 0;
}