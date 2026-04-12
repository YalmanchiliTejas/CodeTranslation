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

const int N = 20005;
int a[N], n, m, k;
int cache[N][2][105];
string s;

int mod = 1e9 + 7;
inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x; }
inline int mul(int x, int y) { return (x * y) % mod; }
inline int powr(int a, int b) {
     int x = 1 % mod;
     while (b) {
          if (b & 1) x = mul(x, a);
          a = mul(a, a);
          b >>= 1;
     }
     return x;
}
inline int inv(int a) { return powr(a, mod - 2); }

int dp(int pos, int free, int m)
{
     if (pos == n)
          return m == 0;

     int &ans = cache[pos][free][m];
     if (ans != -1)
          return ans;

     ans = 0;
     if (!free)
     {
          for (int i = 0; i < s[pos] - '0'; i++)
               ans = add(ans, dp(pos + 1, 1, (m + i) % k));

          ans = add(ans, dp(pos + 1, 0, (m + s[pos] - '0') % k));
     }
     else
     {
          for (int i = 0; i < 10; i++)
               ans = add(ans, dp(pos + 1, 1, (m + i) % k));
     }

     return ans;
}

void solve()
{
     cin >> s >> k;
     n = sz(s);
     memset(cache, -1, sizeof cache);
     cout << sub(dp(0, 0, 0), 1);

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