#include <bits/stdc++.h>
using namespace std;

int main(){
  int r, g, b, i;
  
  cin >> r >> g >> b;
  
  i = r * 100 + g * 10 + b;
  
  if(i % 4 == 0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}