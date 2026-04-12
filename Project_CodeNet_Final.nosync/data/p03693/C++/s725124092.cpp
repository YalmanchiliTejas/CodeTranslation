#include <bits/stdc++.h>
using namespace std;

int main() {
  int r,g,b;
  cin >> r >> g >> b;
  int x = 10 * g + b;
  cin >> x;
  
  if(x%4 == 0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  
}
