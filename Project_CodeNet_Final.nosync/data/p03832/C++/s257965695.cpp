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
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e3 + 5;
const double eps = 1e-9;
int dp[N][N], C[N][N], fac[N], ifac[N], inv[N];
int n, a, b, c, d, cnt[N]; 
vi cur;
int ans = 0, cnt2[N][N];

int add(int x, int y) { return x+y < mod ? x+y : x+y-mod; }
int mul(int x, int y) { return x * 1ll * y % mod; }

int pw(int x, int y) {
  int r = 1;
  while (y > 0) {
    if (y & 1)
      r = mul(r, x), y--;
    else
      x = mul(x, x), y /= 2;
  }
  return r;
}

int main() {
  for (int i = 0; i < N; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = add(C[i-1][j], C[i-1][j-1]);
  }
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = mul(i, fac[i-1]);
    inv[i] = i == 1 ? 1 : (mod - mul(mod/i, inv[mod%i])) % mod;
    ifac[i] = mul(inv[i], ifac[i-1]);
  }
  scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
  for (int i = a-1; i < b; i++)
    dp[0][i] = 1;
  for (int i = c*a; i <= n; i++) {
    for (int j = a; j <= b; j++) {
      dp[i][j] = dp[i][j-1];
      for (int k = c; k <= d && i-k*j >= 0; k++) {
        int nx = mul(fac[i], ifac[i-k*j]);
        nx = mul(nx, ifac[k]);
        nx = mul(nx, pw(ifac[j], k));
        dp[i][j] = add(dp[i][j], mul(nx, dp[i-k*j][j-1]));
      }
    }
  }
  printf("%d\n", dp[n][b]);
  return 0;
}
