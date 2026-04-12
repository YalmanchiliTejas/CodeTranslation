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
  for (int i = 0; i < n; i++) {
    b[i % 2 == 0 ? l++ : r--] = a[n-i-1];
  }
  for (int x: b) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
