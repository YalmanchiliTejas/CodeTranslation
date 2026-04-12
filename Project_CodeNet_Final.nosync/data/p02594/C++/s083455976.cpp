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
  cout << (n >= 30 ? "Yes" : "No") << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
#ifdef MULTIPLE_TEST_CASES
  cin >> t;
#endif
  while (t--)
    solve();
}