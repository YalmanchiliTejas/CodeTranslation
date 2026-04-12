#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y,z,count = 1;
  cin >> x >> y >> z;
  x -= y + z + z;
  while(x >= 0){
    x -= y + z;
    count++;
  }
  cout << count - 1 << endl;
}
