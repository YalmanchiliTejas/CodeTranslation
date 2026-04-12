#include <algorithm>
#include <bitset>
#include <boost/rational.hpp>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) { cin >> a[i]; }
  sort(a.begin(), a.end());

  int64_t result = 0;
  if (N % 2 == 0) {
    result += a[N / 2] - a[N / 2 - 1];
    rep(i, N / 2 - 1) { result += 2 * (a[N / 2 + i + 1] - a[i]); }
  } else {
    int64_t cand1 = a[N / 2] + a[N / 2 + 1];
    int64_t cand2 = -a[N / 2] - a[N / 2 - 1];

    rep(i, N / 2 - 1) {
      cand1 += 2 * a[N - 1 - i];
      cand2 -= 2 * a[i];
    }
    rep(i, N / 2) {
      cand1 -= 2 * a[i];
      cand2 += 2 * a[N - 1 - i];
    }
    result = max(cand1, cand2);
  }
  cout << result << endl;

  return 0;
}
