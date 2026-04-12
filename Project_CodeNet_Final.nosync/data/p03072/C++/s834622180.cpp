#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> h(n);
  int ans = 1;

  for(int i = 0; i < n; i++) { cin >> h.at(i); }

  int t = h.at(0);

  for(int i = 1; i < n; i++) {
    if(t <= h.at(i)) {
      ans++;
    }
    t = max(t, h.at(i));
  }
  cout << ans << endl;
}