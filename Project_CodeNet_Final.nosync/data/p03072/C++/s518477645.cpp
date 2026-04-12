#include <bits/stdc++.h>

using namespace std;

int main () {

  int n, ans = 1;
  cin >> n;
  vector<int> v;
  while (n--) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  for (int i = 1; i < v.size(); i++) {
    bool is = true;
    for (int j = i - 1; j >= 0; j--) {
      if (!(v[j] <= v[i])) {
        is = false;
      }
    }
    if (is) {
      ans++;
    }
  }
  
  cout << ans << endl;

  return 0;
}