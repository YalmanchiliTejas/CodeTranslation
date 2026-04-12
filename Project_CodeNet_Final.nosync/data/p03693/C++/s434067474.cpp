#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int r,g,b;
  cin >> r >> g >> b;
  int x=(100*r+10*g+b)%4;
  if (x==0){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}