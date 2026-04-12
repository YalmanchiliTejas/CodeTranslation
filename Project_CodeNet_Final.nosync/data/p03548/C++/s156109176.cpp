#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int x,y,z;
  cin >> x >> y >> z;
  
  int a = 0,count = 0;
  
  while( a <= x ){
    count++;
    a = y * count + z * ( count + 1 );
  }
  
  count--;  
  
  cout << count << endl;
   
}