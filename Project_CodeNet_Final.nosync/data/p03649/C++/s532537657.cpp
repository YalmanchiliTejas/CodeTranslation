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
const ll inf = 1e18 + 7;
const int N = 1e6 + 5;
const double eps = 1e-9;
ll a[N];

int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%lld", a+i);
  for (ll x = 0; x <= n; x++) {
    ll cnt = 0;
    for (int i = 0; i < n; i++)
      if (a[i]+x >= n)
        cnt += (a[i]+x-n) / (n+1) + 1;
    if (cnt <= x) {
      printf("%lld\n", x);
      return 0;
    }
  }
  ll lo = n+1, hi = inf;
  while (lo <= hi) {
    ll mi = (lo+hi) / 2;
    ll cnt = n;
    for (int i = 0; cnt <= mi && i < n; i++)
      cnt += (a[i]+mi-(ll)n)/(ll)(n+1);
    if (cnt <= mi)
      hi = mi - 1;
    else
      lo = mi + 1;
  }
  for (ll x = max((ll)n+1, lo - 4*n*n); x <= lo; x++) {
    ll cnt = n;
    for (int i = 0; i < n; i++)
      cnt += (a[i]+x-(ll)n)/(ll)(n+1);
    if (cnt <= x) {
      printf("%lld\n", x);
      return 0;
    }
  }
  printf("%lld\n", lo);
  return 0;
}
