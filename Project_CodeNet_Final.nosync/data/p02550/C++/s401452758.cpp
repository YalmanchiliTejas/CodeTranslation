#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vs){
  for (const T& v : vs) os << v << " ";
  return os;
}
int main() {
  LL N, X, M; cin >> N >> X >> M;
  map<LL, int> m = {{X, 0}};
  vector<LL> v = {X};

  bool loop = false;
  int i = 1;
  for (; i < N; ++i) {
    X = (X*X) % M;
    if (m.count(X)) {
      loop = true;
      break;
    }
    m[X] = i;
    v.push_back(X);
  }

  LL sum = 0;
  if (loop) {
    LL sum_head = 0, sum_loop = 0, sum_tail = 0;
    LL loop_size = i - m[X];
    LL loop_head = m[X];
    LL loop_num = (N-m[X])/loop_size;
    LL loop_tail = N - loop_head - loop_size * loop_num;

    for (int j = 0; j < m[X]; ++j) sum_head += v[j];
    for (int j = 0; j < loop_tail; ++j) sum_tail += v[loop_head + j];
    for (int j = m[X]; j <= i; ++j) sum_loop += v[j];

    sum = sum_head + sum_loop * loop_num + sum_tail;
  } else {
    for (auto [X, j] : m) sum += X;
  }
  cout << sum << endl;
}
