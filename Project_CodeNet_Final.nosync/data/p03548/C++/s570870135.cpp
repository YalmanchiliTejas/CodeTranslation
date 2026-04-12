#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  
  int number = 0;
  
  number = x / (y+z);
  
  if(x % (y+z) < z)
    number--;
  
  cout << number << endl;
}