#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;

  int x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    x += 800;
    if(i % 15 == 0) {
      y += 200;
    }
  }
  cout << x - y << '\n';
}
