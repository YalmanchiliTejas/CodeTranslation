#include<bits/stdc++.h>
using namespace std;
int x, y, z;
int main(){
  cin >> x >> y >> z;
  int human = 0;
  x -= z;
  while(x >= y+z){
    x -= (y + z);
    human++;
  }
  cout << human << endl;
}
