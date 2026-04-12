#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;

  int num = r * 100 + g * 10 + b;
  string ans;
  if (num % 4 == 0) {
    ans = "YES";
  } else {
    ans = "NO";
  }

  cout << ans << endl;
  return 0;
}