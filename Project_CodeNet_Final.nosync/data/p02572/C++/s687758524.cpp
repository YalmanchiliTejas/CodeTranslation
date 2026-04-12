#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;

  ll nums[n];
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  ll all_sum = 0;
  ll num_sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    all_sum += nums[i] * num_sum;
    all_sum %= MOD;

    num_sum += nums[i];
    num_sum %= MOD;
  }

  cout << all_sum << endl;

  return 0;
}
