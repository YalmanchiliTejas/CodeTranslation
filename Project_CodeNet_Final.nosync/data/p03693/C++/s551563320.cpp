#include<bits/stdc++.h>
using namespace std;
int main () {
  int r, g, b;
  cin >> r >> g >> b;
  int rgb = 100*r + 10* g + b;
  
  if(rgb %4 == 0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}