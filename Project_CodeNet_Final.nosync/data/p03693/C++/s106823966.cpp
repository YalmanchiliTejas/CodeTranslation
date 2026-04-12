#include <bits/stdc++.h>

using namespace std;

int main() {
  int r,g,b;
  int ans = 0;

  cin >> r >> g >> b;
  ans += r * 100;
  ans += g * 10;
  ans += b;
  if(ans % 4 == 0) cout <<"YES"<<endl;
  else cout <<"NO"<<endl;
}
