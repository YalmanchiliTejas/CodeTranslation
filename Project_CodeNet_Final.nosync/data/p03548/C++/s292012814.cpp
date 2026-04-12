#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y,z;
  cin >> x >> y >> z;
  for(int i=0;i<=pow(10,5);i++){
    if( ( x - i*(y+z) -z ) < 0 ){
      cout << i - 1 << endl;
      return 0;
    }
  }
  return 0;
}