#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  deque<int> d;
  for (int i = 0; i < n; i++) {
    int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    // cout << "p:" << p << endl;
    if (p == 0) {
      d.push_front(a[i]);
    } else {
      d[p - 1] = a[i];
    }
    // for (int i = 0; i < d.size(); i++) {
    //   cout << d[i] << " ";
    // }
    // cout << endl;
  }
  cout << d.size() << endl;
  return 0;
}