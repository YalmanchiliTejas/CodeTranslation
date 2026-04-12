#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int const N = 100 * 1000 + 16;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  int x = 0;
  for(int i = 0; i < 3; ++i) {
    int z;
    cin >> z;
    x = x*10 + z;
  }

  cout << (x % 4 == 0 ? "YES" : "NO") << endl;
}