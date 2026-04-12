#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < n; i++)

using namespace std;

void solve() {
  long N;
  cin >> N;
  vector<long> A(N);
  rep (i, N) cin >> A[i];
  reverse(A.begin(), A.end());

  multiset<long> foo;
  for (long num: A) {
    auto it = foo.upper_bound(num);
    if (it == foo.end()) foo.insert(num);
    else {
      foo.erase(it);
      foo.insert(num);
    }
  }

  cout << foo.size() << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
