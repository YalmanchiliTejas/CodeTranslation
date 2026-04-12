#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, b, g;
  cin >> r >> b >> g;
 
  int rbg = r*100 + b*10 + g;
  
  if(rbg%4 != 0){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }

  return 0;
}
