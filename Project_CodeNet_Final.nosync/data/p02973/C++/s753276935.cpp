#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  vector<int> color(n, -1);
  for (int x : a) {
    auto it = lower_bound(color.begin(), color.end(), x);
    assert(it != color.begin());
    it = prev(it, 1);
    *it = x;
  }
  auto it = upper_bound(color.begin(), color.end(), -1);
  cout << color.end() - it << '\n';
  return 0;
}
