#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<int> a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  vector<int> ans;
  // ans.push_back(a[0]);
  for (int i = 0; i < n; i++) {
    auto it = upper_bound(ans.begin(), ans.end(), -a[i]);
    if (it == ans.end()) {
      ans.push_back(-a[i]);

    } else {
      *it = -a[i];
    }
    // sort(ans.begin(), ans.end());
  }
  cout << ans.size() << endl;
  return 0;
}