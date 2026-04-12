#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
ll INF = 1e18;

bool cmp(pll& a, pll& b) { return (a.second < b.second); }

int main() {
  //
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  vl b = a;
  sort(ALL(a));
  sort(ALL(b), greater<ll>());

  vl cnt(n, 0), cnt2(n, 0);
  rep(i, n - 1) {
    if ((i & 1) == 0) {
      cnt[i]--;
      cnt[i + 1]++;
      cnt2[i]++;
      cnt2[i + 1]--;
    } else {
      cnt[i]++;
      cnt[i + 1]--;
      cnt2[i]--;
      cnt2[i + 1]++;
    }
  }
  sort(ALL(cnt));
  sort(ALL(cnt2));

  int i = 0;
  ll ans = 0, ans2 = 0;
  for (auto& c : cnt) {
    ans += c * a[i];
    i++;
  }
  i = 0;
  for (auto& c : cnt2) {
    ans2 += c * a[i];
    i++;
  }

  cout << max(ans, ans2) << endl;
  return 0;
}
