#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> s;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      s.push_back(tmp);
    }
    sort(s.begin(), s.end());
    int ans = accumulate(s.begin() + 1, s.end() - 1, 0) / (n - 2);
    cout << ans << endl;
  }
  return 0;
}