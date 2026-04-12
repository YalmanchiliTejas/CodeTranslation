// Last Change:                   12/09/2018 00:27:04.
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}

struct Barger {
  ll size;
  ll p;
};

int main() {
  ll N, X;
  Barger barger[50];
  cin >> N >> X;

  barger[0].size = barger[0].p = 1;
  for (int i = 1; i < N; i++) {
    barger[i].size = barger[i - 1].size * 2 + 3;
    barger[i].p = barger[i - 1].p * 2 + 1;
  }

  ll ans = 0, depth = N;
  while (X > 0 && depth > 0) {
    --X;
    --depth;

    if (X > barger[depth].size + 1) {
      X -= barger[depth].size + 1;
      ans += barger[depth].p + 1;
    } else if (X == barger[depth].size + 1) {
      X -= barger[depth].size + 1;
      ans += barger[depth].p + 1;
    }
    if (depth == 0 && X > 0) {
      ans++;
      X = 0;
    }
  }
  cout << ans << endl;
}
