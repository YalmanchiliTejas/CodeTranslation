#include<bits/stdc++.h>
using namespace std;

int main(){
  int r, g, b;
  cin >> r >> g >> b;
  
  string ans = "NO";
  
  if((100*r + 10*g + b) %4 == 0){
    ans = "YES";
  }
  
  cout << ans << endl;
  
}