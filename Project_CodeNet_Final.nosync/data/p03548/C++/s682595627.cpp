#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int x, y, z;
  cin >> x >> y >> z;
  int ans = 0;
  while (z * 2 + y <= x) {
    ans++;
    x -= y + z;
  }
  cout << ans << endl;

  return 0;
}