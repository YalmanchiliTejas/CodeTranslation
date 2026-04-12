#include<bits/stdc++.h>
using namespace std;

int main () {
  int x, y, z; // 椅子の幅, 1人が使う幅, 人との隙間
  cin >> x >> y >> z;
  x -= z; // 左端を開ける
  int ans = 0;
  while (1) {
    x -= y + z;
    if (x < 0) break;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
