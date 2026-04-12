#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,g,b,ans;
  cin >> r >> g >> b;
  g = g*10;
  ans = g+b;
  if((g+b)%4 != 0) cout << "NO" << endl;
  else if(g == 0 && b==0) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}
