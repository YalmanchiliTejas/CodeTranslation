#include <bits/stdc++.h>

using namespace std;

template< typename T >
struct BinaryIndexedTree {
  BinaryIndexedTree(size_t n) : n(n), v(n + 1) {}

  size_t n;
  vector< T > v;

  T sum(int k) {
    T ret = 0;
    for(; k; k -= k & -k) ret += v[k];
    return ret;
  }

  void add(int k, T x) {
    for(; k <= n; k += k & -k) v[k] += x;
  }
};

int main() {
  int n, k;
  cin >> n >> k;

  vector< int > x(n + 1), idx(n + 1, -1);
  for(int i = 1; i <= n; ++i) {
    cin >> x[i];
    idx[x[i]] = i;
  }

  BinaryIndexedTree< int > bit(n);
  vector< int > inv(n + 1);
  int64_t sum = 0;
  for(int i = 1; i <= n; ++i) {
    inv[x[i]] = i - bit.sum(x[i]) - 1;
    sum += inv[x[i]];
    bit.add(x[i], 1);
  }

  vector< int > ans(1), used(n + 1, 0);
  for(int i = 1; i <= n; ++i) {
    if(sum - k < inv[i]) break;
    ans.push_back(i);
    sum -= inv[i];
    used[i] = true;
  }


  int mini = 101010, last = -1;
  set< pair< int, int > > unused;
  for(int i = 1; i <= n; ++i) {
    if(!used[x[i]]) {
      int sz = (int) unused.size();
      unused.emplace(sz, x[i]);
    }
  }

  int64_t rest = sum - k;
  while(unused.size()) {
    auto it = unused.begin();
    int small = it->second;
    for(int j = 0; j <= rest; j++) {
      if(it == unused.end()) break;
      small = min(small, it->second);
      ++it;
    }
    it = unused.begin();
    for(int j = 0;; j++) {
      if(small == it->second) {
        rest -= j;
        ans.push_back(it->second);
        unused.erase(it);
        break;
      }
      ++it;
    }
  }


  for(int i = 1; i <= n; ++i) {
    cout << ans[i] << endl;
  }
}

