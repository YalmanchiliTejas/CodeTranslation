#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, int> ipair;
#define int long long
#define pb push_back
#define ff first
#define INF INT_MAX
#define ss second
#define fr(i, j, a) for (int i = j; i < a; i++)
#define cnt_ones(x) __builtin_popcount(x)
#define all(x) x.begin(), x.end()
#define sz size()
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<ipair>
#define ar array
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

void init() {
  int n;
  cin >> n;
  const int mod = 1e9 + 7;
  vi a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vi pref(n);
  pref[0] = a[0];
  for (int i = 1; i < n; i++)
    pref[i] = (pref[i - 1] + a[i]) % mod;
  int ans = 0;
  // for(auto x:pref) cout<<x<<" ";
  for (int i = 1; i < n; i++) {
    ans = (ans % mod + (pref[i - 1] * a[i]) % mod) % mod;
  }
  cout << ans << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
