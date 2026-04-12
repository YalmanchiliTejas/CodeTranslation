//verma_ankit484

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const int mod = 998244353;

using namespace std;
//using namespace __gnu_pbds;

//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int dp[3001][3001];
int s, n;
vector<int> vc;

int rec(int idx, int sum) {
  if (sum > s) return 0;
  if (sum == s) {
    return n - idx + 1;
  }
  if (idx >= n) return 0;
  int &ans = dp[idx][sum];
  if (ans != -1) return ans;
  ans = 0;
  ans = rec(idx + 1, sum);
  // cout << ans << ' ' << ans % mod << endl;
  ans %= mod;
  ans += rec(idx + 1, sum + vc[idx]);
  ans %= mod;
  return ans;
}

int32_t main() {
  IOS
  #ifdef AV
  freopen("input.txt", "r", stdin);
  #endif
  cin >> n >> s;
  vc.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  memset(dp, -1, sizeof(dp));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += rec(i, 0);
    ans %= mod;
  }
  cout << ans << endl;
  // cout << rec(0, 0) << endl;
  return 0;
}
