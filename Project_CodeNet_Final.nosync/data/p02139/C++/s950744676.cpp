#include <bits/stdc++.h>
using namespace std;

int now = 0, k, n, m, ch;

int main() {
  int i;
  cin >> n >> m;
  for(i = 0; i < m; ++i) {
    cin >> ch >> k;
    if(ch) {
      now += k;
      now %= n;
    }
    else {
      cout << (now + k - 1) % n + 1 << endl;
    }
  }
  return 0;
}
