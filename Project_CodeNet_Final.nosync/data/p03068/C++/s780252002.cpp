// Last Change: 04/20/2019 21:06:54.
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
  int N, K;
  string S;
  cin >> N >> S >> K;

  char tar = S[K - 1];
  for (int i = 0; i < N; ++i) {
    if (S[i] != tar) {
      S[i] = '*';
    }
  }

  cout << S << endl;

  //NS::LoopUntilZeroInpput();
}
