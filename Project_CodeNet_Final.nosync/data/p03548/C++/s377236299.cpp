#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int t = x - z;
  int d = y + z;
  int ans = t / d;
  cout << ans << endl;
  return 0;
}