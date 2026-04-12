#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  
  string res ;
  
 
  
  if((100*r+10*g+b) % 4 == 0){
    res = "YES";
  }
  
  else{
    res = "NO";
  }
  
  cout << res << endl;

}