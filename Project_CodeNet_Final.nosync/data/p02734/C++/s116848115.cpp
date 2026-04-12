//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define trav(x,a) for (const auto& x: a)
#define sz(x) (int)(x).size()
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int _i = 0; _i < (n); _i++) ni(a[_i])
#define nal(a, n) for (int _i = 0; _i < (n); _i++) nl(a[_i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int mod = 998244353;
const int inf = 1e9 + 7;
const int N = 6e3 + 5;
const double eps = 1e-9;
int a[N], dp[N][N];
int add(int x, int y) { return x+y < mod ? x+y : x+y-mod; }
int mul(int x, int y) { return x * 1ll * y % mod; }

int main() {
  int n, s; scanf("%d %d", &n, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= s; j++)
      dp[i][j] = dp[i-1][j];
    for (int j = a[i]; j <= s; j++)
      dp[i][j] = add(dp[i][j], dp[i-1][j-a[i]]);
    dp[i][a[i]] = add(dp[i][a[i]], i);
    ans = add(ans, dp[i][s]);
  }
  printf("%d\n", ans);
  return 0;
}
