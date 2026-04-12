#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r,g,b;
  cin >> r >> g >> b;

  if ((100*r+g*10+b)%4==0) {
    cout << "YES" << endl;
  }

  else {
    cout << "NO" << endl;
  }
  return 0;
}
