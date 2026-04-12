#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;
constexpr int64_t MOD = 1e9 + 1;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  int64_t N,X,M;
  cin >> N >> X >> M;
  unordered_set<int64_t> us;
  int64_t pre = 1;
  int64_t a = X;
  int64_t sum = a;
  us.insert(a);
  int64_t head = -1;
  for (pre = 2; pre <= N; pre++) {
    a *= a;
    a %= M;
    //cout << pre << "," << a  <<"," << sum << endl;
    if (us.count(a) == 0) {
      us.insert(a);
      sum += a;
    } else {
      head = a;
      break;
    }
  }

  if (pre == N + 1) {
    cout << sum << endl;
    return 0;
  }

  int64_t looplen = 1;
  int64_t loopsum = head;
  for (pre = pre + 1; pre <= N; pre++) {
    a *= a;
    a %= M;
    if (a != head) {
      loopsum += a;
      //loopsum %= M;
      looplen++;
    } else {
      break;
    }
  }

  sum += loopsum;
  //sum %= M;
  int64_t num_loop = (N - pre) / looplen;
  int64_t res = (N - pre) % looplen;
  sum += num_loop * loopsum;
  //sum %= M;
  a = head;
  for (pre = N - res; pre <= N; pre++) {
    sum += a;
    //sum %= M;
    a *= a;
    a %= M;
  }

  cout << sum << endl;


  return 0;
}