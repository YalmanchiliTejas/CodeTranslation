#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>
#include <set>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll N, prev_max, ret;
  ret = 1;
  cin >> N;

  cin >> prev_max;
  for (auto i = 0; i < N - 1; i++) {
    ll x;
    cin >> x;
    if (prev_max <= x) {
      ret++;
    }
    prev_max = max(prev_max, x);
  }

  cout << ret << endl;

  return 0;
}
