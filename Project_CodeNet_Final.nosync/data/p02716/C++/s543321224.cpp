#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;  // or pb_ds;

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#ifndef DEBUG
// #define endl "\n"
#endif
#define fff ff
#define sss ss.ff
#define ttt ss.ss
#define INF (1 << 30)
#define LLF (1ll << 60)
#define PRIME (1000000007)
#define FASTIO std::ios::sync_with_stdio(false)
#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define rep(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define FILE_INPUT                  \
  freopen("input.txt", "r", stdin); \
  freopen("output.txt", "w", stdout)

#define all(x) x.begin(), x.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<string> vs;

template <typename T, typename B = null_type>
using oset =
    tree<T, B, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order / order_of_key

const ld eps = 1e-12;

/*-----------------END TEMPLATE-----------------*/

const int N = 2e5 + 50;
int a[N];
int n;

ll pardp[N][2];
ll impardp[N];

ll solvePar(int i, int lastPairLeft) {
  if (i >= n) return 0;
  if (pardp[i][lastPairLeft] != -1) return pardp[i][lastPairLeft];

  if (!lastPairLeft) {
    ll sum = a[i + 1];
    return pardp[i][lastPairLeft] = sum + solvePar(i + 2, 0);
  }

  ll left = a[i];
  left += solvePar(i + 2, 1);

  ll right = a[i + 1];
  right += solvePar(i + 2, 0);

  return pardp[i][lastPairLeft] = max(left, right);
}

ll solveImpar(int i) {
  if (i >= n) return 0;
  if (impardp[i] != -1) return impardp[i];

  // not pick
  ll notPick = solvePar(i + 1, 1);

  // pick
  ll pick = a[i];
  pick += solveImpar(i + 2);

  return impardp[i] = max(notPick, pick);
}

void solve() {
  cin >> n;
  rep(i, 0, n) cin >> a[i];

  memset(pardp, -1, sizeof pardp);
  memset(impardp, -1, sizeof impardp);

  if (n % 2 == 1) {
    cout << solveImpar(0) << endl;
  } else {
    cout << solvePar(0, 1) << endl;
  }
}

int(((((((((((((((main)))))))))))))))() {
  FASTIO;
  int n;
  // cin >> n;
  n = 1;
  int i = 1;
  while (n--) {
    solve();
  }
}

/*


00100
00

*/