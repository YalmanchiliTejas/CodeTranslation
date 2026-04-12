#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int i=0;
  while(1){
    ++i;
    if(z+i*(y+z)>x) break;
  }
  cout << i-1 << endl;
  return 0;
}