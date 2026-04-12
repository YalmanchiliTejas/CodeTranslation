#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <utility>
#include <numeric>
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define FOR(i, m, n) for (int i = (int)m; i < (int)n; i++)
#define REPvec(itr, mp) for (auto itr = mp.begin(); itr != mp.endl(); itr++)
#define REPe(e, mp) for (auto& e : mp)
#define all(x) x.begin(), x.end()
#define MOD 1000000007  // 1e9+7
using namespace std;
using ll = long long int;
using vecint = vector<int>;
using vecll = vector<ll>;
using vec2int = vector<vector<int>>;
using P = pair<int, int>;
////////////////////////////////////////////////
////////////////////////////////////////////////
int main() {
  ////////////////////////////////////////////////
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ////////////////////////////////////////////////
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  int X = 1e5;
  if (k == 0) {
    ans = (ll)n * (ll)n;
    cout << ans << endl;
    return 0;
  }
  FOR(i, k + 1, n + 1) {
    ll m = (ll)(n / i);
    ans += (m * (ll)(i - k)) + (ll)max(n % i - k + 1, 0);
    // cout << i << "  " << (m * (ll)(i - k)) << " " << (ll)max(n % i - k + 1, 0)
    //      << endl;
  }
  cout << ans << endl;
}
