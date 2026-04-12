#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> c;
  rep(i, n) {
    int a;
    cin >> a;
    int sz = c.size();
    if (!sz) {
      c.push_back(a);
      continue;
    }
    int j = lower_bound(c.begin(), c.end(), a) - c.begin() - 1;
    if (j < 0 || a == c[j]) {
      c.insert(c.begin(), a);
    } else {
      c[j] = a;
    }
  }
  cout << c.size() << endl;
  return 0;
}