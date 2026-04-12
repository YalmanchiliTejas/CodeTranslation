#include<bits/stdc++.h>
using namespace std;

int main() {
  int r,g,b,t;
  
  cin >> r >> g >> b;
  
  t=r*100+g*10+b;
  if(t%4==0) cout << "YES"<<endl;
  else cout << "NO" << endl;
  return 0;
}
  
  