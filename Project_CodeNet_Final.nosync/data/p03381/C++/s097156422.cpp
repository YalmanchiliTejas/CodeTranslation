#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

namespace chrono = std::chrono;
using namespace std::literals;

[[gnu::constructor]]
void fast_iostream() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);
}

int main() {
  int n; cin >> n;
  std::vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  std::vector<int> ix(n);
  std::iota(ix.begin(), ix.end(), 0LL);
  std::sort(ix.begin(), ix.end(), [&](int i, int j) {
    return x[i] < x[j];
  });
  std::vector<int> ans(n);
  for (int i: ix) {
    if (x[i] <= x[ix[n/2 - 1]]) {
      ans[i] = x[ix[n/2]];
    } else {
      ans[i] = x[ix[n/2 - 1]];
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
  }
}
