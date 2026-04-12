#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i=0; i<n; i++) cin >> h.at(i);
  int mh = h.at(0);
  int ans = 1;
  for (int i=1; i<n; i++) {
    if (h.at(i) >= mh) {
      ans++;
      mh = h.at(i);
    }
  }
  cout << ans << endl;
}
