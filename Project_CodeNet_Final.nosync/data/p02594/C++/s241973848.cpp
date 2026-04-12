#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U> void cmax(T &a, U b) { if (a < b) a = b; }
template<typename T, typename U> void cmin(T &a, U b) { if (a > b) a = b; }

signed main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int X;
  cin >> X;
  cout << ((X >= 30) ? "Yes" : "No") << "\n";
}