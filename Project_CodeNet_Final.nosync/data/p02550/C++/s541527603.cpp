#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define ii pair<int, int>
#define OK (cerr << "OK" << endl)
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int, int, int>
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<int, int>>>
#define Mat(n, m, v) vector<vector<int>>(n, vector<int>(m, v))
#define endl '\n'

constexpr int INF = 2e18;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e5 + 3;

// #define MULTIPLE_TEST_CASES
void solve() {
  int n;
  cin >> n;
  int cur;
  cin >> cur;
  int m;
  cin >> m;
  int it = 0;

  // int vans = 0;
  // {
  //   int c = cur;
  //   int no = n;
  //   while (no--) {
  //     vans += c;
  //     // debug(cur);
  //     c = c * c % m;
  //   }
  // }

  int x = cur;
  int ans = 0;
  int no = n;
  int last = -1;
  vi vis(m + 1, -1);
  vi t(m + 1, -1);
  while (cur != 0 && vis[cur] == -1 && n--) {
    vis[cur] = ans;
    t[cur] = it;
    ans += cur;
    last = cur;
    cur = cur * cur % m;
    ++it;
  }
  if (cur == 0 || n == -1) {
    cout << ans << endl;
    return;
  }
  // debug(cur);
  // debug(last);
  // debug(ans);
  int sz = it - t[cur];
  int ini = it - sz;
  no -= ini;
  int v1 = 0;
  // debug(ini);
  while (ini--) {
    v1 += x;
    x = x * x % m;
  }
  // debug(v1);
  ans -= v1;
  ans = ans * (no / sz);
  no %= sz;
  // debug(no);
  while (no--) {
    ans += cur;
    cur = cur * cur % m;
  }
  ans += v1;
  // debug(ans);
  // debug(vans);
  // assert(vans == ans);
  cout << ans << endl;
}

signed main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int t = 1;
#ifdef MULTIPLE_TEST_CASES
  cin >> t;
#endif
  while (t--)
    solve();
}