#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int r=0, g=0, b=0;
  
  cin >> r >> g >> b;
  
  int cul = g*10 + b;
  
  if(cul%4==0) {
    
    cout << "YES" <<endl;
    
  } else {
    
    cout << "NO" << endl;
    
  }
  
  return 0;
  
}