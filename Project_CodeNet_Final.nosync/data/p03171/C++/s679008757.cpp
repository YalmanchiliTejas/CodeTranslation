#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REPvec(itr, mp) for (auto itr = mp.begin(); itr != mp.end(); itr++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007  // 1e9+7
using namespace std;
typedef long long ll;
typedef vector<bool> vecbool;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef vector<string> vecstr;
typedef vector<vecint> vec2int;
typedef vector<vecbool> vec2bool;
int dx[4]{-1, +1, 0, 0};
int dy[4]{0, 0, -1, +1};
void init() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}
int n;
vecint a;
vector<vecll> memo;
ll dfs(int l, int r) {
  if (memo[l][r] != -1) return memo[l][r];
  ll res;
  if (r - l == 0) {
    res = a[r];
  } else if (r - l == 1) {
    res = max(a[l], a[r]);
  } else {
    // ll al, ar;
    // if (dfs(l + 2, r) <= dfs(l + 1, r - 1)) {
    //   al = dfs(l + 2, r);
    // } else {
    //   al = dfs(l + 1, r - 1);
    // }
    // if (dfs(l, r - 2) <= dfs(l + 1, r - 1)) {
    //   ar = dfs(l + 2, r);
    // } else {
    //   ar = dfs(l + 1, r - 1);
    // }
    ll al = min(dfs(l + 2, r), dfs(l + 1, r - 1));
    ll ar = min(dfs(l, r - 2), dfs(l + 1, r - 1));
    res = max(a[l] + al, a[r] + ar);
  }
  memo[l][r] = res;
  return res;
}
int main() {
  init();
  cin >> n;
  a.resize(n);
  ll sum = 0;
  for (auto& e : a) {
    cin >> e;
    sum += e;
  }
  memo = vector<vecll>(n, vecll(n, -1));
  ll x = dfs(0, n - 1);
  cout << 2 * x - sum << endl;
}
