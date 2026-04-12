#include <algorithm>
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

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  string N;
  int K;
  cin >> N >> K;

  vector<int64_t> dpl(K + 1);
  int nonzero = 0;

  rep(i, N.size() + 1) {
    int d = N[i - 1] - '0';
    rrep(j, K + 1) {
      if (i == 0) {
        dpl[j] = 0;
      } else {
        dpl[j] = dpl[j];
        dpl[j] += (j > 0) ? 9 * dpl[j - 1] : 0;
        dpl[j] += (j == nonzero && d > 0) ? 1 : 0;
        dpl[j] += (j - 1 == nonzero && d > 0) ? d - 1 : 0;
      }
      cerr << dpl[j] << " ";
    }
    cerr << endl;
    if (d > 0) {
      nonzero++;
    }
  }

  cout << (nonzero == K ? 1 : 0) + dpl[K] << endl;

  return 0;
}