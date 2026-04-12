#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// #include "prettyprint.hpp"

int main() {
  int N;
  cin >> N;
  long long s[N];
  for (int i = 0; i < N; i++) cin >> s[i];

  long long dp[N];
  long long max = 0;
  for (int c = 1; c < N - 1; c++) {
    dp[0] = 0;
    for (int k = 1; k * c < N - 1; k++) {
      if ((N - 1) % c == 0 && 2 * (k + 1) > (N - 1) / c + 1) break;
      if (N - 1 - k * c <= c) break;

      dp[k] = dp[k - 1] + s[N - 1 - k * c] + s[k * c];

      if (dp[k] > max) max = dp[k];
    }
  }

  cout << max << endl;
  return 0;
}