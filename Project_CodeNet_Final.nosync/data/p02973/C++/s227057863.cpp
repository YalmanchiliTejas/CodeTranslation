#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  reverse(a.begin(), a.end());
  int ans = 1;
  vector<int> p;
  p.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    int x = upper_bound(p.begin(), p.end(), a[i]) - p.begin();
    if (x >= p.size()) {
      p.push_back(a[i]);
      ans++;
    }
    else {
      p[x] = a[i];
    }
  }
  cout << ans << endl;
  return 0;
}