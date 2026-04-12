#include<bits/stdc++.h>
using namespace std;

int main(){
  int r, g, b;
  cin >> r >> g >> b;
  
  int c = 10*g + b;
  string re;
  
  if(c%4 == 0){
    re = "YES";
  } else {
    re = "NO";
  }
  
  cout << re << endl;
  
  return 0;
}