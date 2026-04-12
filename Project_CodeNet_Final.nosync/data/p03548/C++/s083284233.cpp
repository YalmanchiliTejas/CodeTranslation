#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  x -= z;
  y += z;
  int cnt = 0;
  while(x>0){
    if(x>=y) cnt++;
    x -= y;
  }
  cout << cnt << endl;
}