#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b, pro;
  cin >> r >> g >> b;
  
  pro = 100*r + 10*g + b;
  
  if (pro % 4 == 0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}