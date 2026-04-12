#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  int n;
  cin >> n;
  vector<int> d(n);
  for(int i = 0; i < n; ++i) cin >> d[i];

  bool ok = true;
  {
    int jump = 0;
    for(int i = 0; i < n; ++i) {
      if(jump < i * 10) {
        ok = false;
        break;
      }
      jump = max(jump, i * 10 + d[i]);
    }
  }
  reverse(d.begin(), d.end());
  {
    int jump = 0;
    for(int i = 0; i < n; ++i) {
      if(jump < i * 10) {
        ok = false;
        break;
      }
      jump = max(jump, i * 10 + d[i]);
    }
  }
  if(ok) cout << "yes\n";
  else cout << "no\n";
}
