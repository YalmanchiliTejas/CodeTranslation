/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : 2019-12-06 04:11:28
**/

#include <iostream>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
#include <bitset>
#include <cassert>
#include <cctype>
#include <functional>
#include <iomanip>
#include <random>
#include <utility>

using namespace std;

using int64 = long long;
#define debug(_) cerr << #_ << ": " << (_) << '\n'
template<class T> ostream& operator<<(ostream& os, vector<T>& _) { os << '{'; for (T& x : _) { os << x; if (&x != &_.back()) os << ','; } os << '}'; return os; }
template<class T, class U> ostream& operator<<(ostream& os, pair<T, U>& p) { return os << '{' << p.first << " " << p.second << '}'; }

constexpr int INF = 1e9 + 5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  reverse(a.begin(), a.end());

  vector<int> dp(n, INF);

  for (int i = 0; i < n; ++i) {
    *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }

  //debug(dp);

  cout << distance(dp.begin(), lower_bound(dp.begin(), dp.end(), INF)) << endl;

  return 0;
}