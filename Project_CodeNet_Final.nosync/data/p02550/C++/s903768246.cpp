#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using i64 = int64_t;
#define rep(i, s, n) for (i64 i = (s); i < (n); ++i)

void run() {
  i64 n, x, m;
  cin >> n >> x >> m;
  vector<i64> i_pre(m, -1);
  vector<i64> ret_pre(m, 0);
  i64 i{0};
  i64 ret{0};
  x %= m;
  while(0 < n){
    --n;
    i_pre[x] = i++;
    ret_pre[x] = ret;
    ret += x;
    x = (x*x)%m;
    if(0 <= i_pre[x]){
      i64 w{i - i_pre[x]};
      ret += (ret - ret_pre[x])*(n/w);
      n %= w;
    }
  }
  cout << ret << endl;
}

int main() {
  cin.tie(nullptr);
  run();
  return 0;
}
