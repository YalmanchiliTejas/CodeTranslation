// Last Change: 04/13/2019 21:05:04.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

int main() {
  int N, maxHight;
  cin >> N;
  maxHight = 0;

  int ipt, ans = 0;
  for (int i = 0; i < N; ++i) {
    cin >> ipt;
    if (ipt >= maxHight) {
      ++ans;
    }
    maxHight = max(maxHight, ipt);
  }

  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}
