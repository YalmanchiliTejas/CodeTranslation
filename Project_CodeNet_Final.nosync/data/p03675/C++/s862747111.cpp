#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  int l = 0, r = n - 1;
  bool isleft = true;
  for (int i = n - 1; i >= 0; i--) {
    b[isleft ? l++ : r--] = a[i];
    isleft = !isleft;
  }
  for (int x: b) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
