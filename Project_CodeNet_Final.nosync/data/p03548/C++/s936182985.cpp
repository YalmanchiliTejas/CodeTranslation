#include<iostream>
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >>z;
  

  int res = 0;
  while((y+z)*res+z <= x) res++; 

  cout << res-1 << endl;
}
