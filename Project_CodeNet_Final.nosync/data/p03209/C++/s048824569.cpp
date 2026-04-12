#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int64_t N, X;
  cin >> N >> X;

  vector<int64_t> lengths(N);
  vector<int64_t> cnts(N);
  lengths[0] = 1; cnts[0] = 1;
  for (int64_t n = 1; n < N; ++n) {
    lengths[n] = lengths[n-1] * 2 + 3;
    cnts[n] = cnts[n-1] * 2 + 1;
  }

  int64_t res = 0;
  for (int n = N-1; n >= 0; --n) {
    --X;  // B on back
    if (X >= lengths[n] * 2 + 1) {
      res += cnts[n] * 2 + 1;
      break;
    } else if (X >= lengths[n]) {
      res += cnts[n];
      X -= lengths[n];
      if (X > 0) {
        ++res; --X;
      }
    }
    if (X == 0) break;
  }
  cout << res << endl;
  
  return 0;
}
