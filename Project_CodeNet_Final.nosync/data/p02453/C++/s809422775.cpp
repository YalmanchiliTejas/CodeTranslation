#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  cin >> v.at(i);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    auto itr = lower_bound(v.begin(), v.end(), k);
    cout << itr - v.begin() << endl;
  }
}
