// ABC154 E - Almost Everywhere Zero
// 問題URL
// https://atcoder.jp/contests/abc154/tasks/abc154_e

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <climits>
#include <iomanip>

using namespace std;

int main()
{
  string S;

  cin >> S;

  for (int i = 0; i < 2; i++) {
    if (S[i] != S[i + 1]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
