#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  int cnt = 0, x;
  for (int i = 0; i < n; i++) {
    cin >> h.at(i);
    x = 0;
    for (int j = 0; j < i; j++) {
      if (h.at(i) < h.at(j)) {
        x = 1;
        break;
      }
    }
    if (x == 0) cnt++;
  }
  cout << cnt << endl;
}