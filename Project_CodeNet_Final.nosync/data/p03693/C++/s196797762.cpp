#include<bits/stdc++.h>
using namespace std;

int main(void){
  int r, g, b, su=0;
  cin >> r >> g >> b;
  su = g*10 + b;
  if(su%4==0) cout << "YES\n";
  else cout << "NO\n";
}