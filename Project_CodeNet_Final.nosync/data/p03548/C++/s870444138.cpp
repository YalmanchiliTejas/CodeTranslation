#include<iostream>
using namespace std;
int main(){
  int x,y,z;
  int t;
  cin >> x >> y >> z;
  
  t=y+z;
  x-=z;
  
  cout << x/t << endl;
  return 0;
}
