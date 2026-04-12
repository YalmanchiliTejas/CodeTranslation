#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> d;
  for (auto e : a) {
    const auto i = upper_bound(d.begin(), d.end(), e, greater<int>()) - d.begin();
    if (i == d.size()) {
      d.push_back(e);
    } else {
      d[i] = e;
    }
  }
  cout << d.size() << endl;
  return 0;
}
