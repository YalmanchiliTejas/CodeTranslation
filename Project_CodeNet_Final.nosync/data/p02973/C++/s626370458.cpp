#include <algorithm>
#include <iostream>
#include <vector>

#define int long long int
using namespace std;

void solve() {
  int N;
  cin >> N;

  vector<int> v;

  while (N--) {
    int A;
    cin >> A;

    auto itr = upper_bound(v.begin(), v.end(), A, std::greater<int>());
    if (itr == v.end()) {
      v.push_back(A);
    } else {
      *itr = A;
    }
  }
  cout << v.size() << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
