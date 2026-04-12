#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  if((b+10*g)%4==0)
    cout << "YES"<< endl;
  else
    cout << "NO" << endl;
}
