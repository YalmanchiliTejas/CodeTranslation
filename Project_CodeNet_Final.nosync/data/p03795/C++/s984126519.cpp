#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()

using namespace std;

int main() {
  int n;
  cin >> n;

  int pay = 0;
  for (int i = 1; i <= n; ++i) {
    pay += 800;
    if (i % 15 == 0) pay -= 200;
  }

  cout << pay << endl;

  return 0;
}