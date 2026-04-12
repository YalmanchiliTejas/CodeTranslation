#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  std::vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int highest = h[0];
  int result  = 1;
  for (int hi = 1; hi < n; hi++) {
    if (h[hi] >= highest) {
      highest = h[hi];
      result++;
    }
  }
  cout << result << endl;
  return 0;
}
