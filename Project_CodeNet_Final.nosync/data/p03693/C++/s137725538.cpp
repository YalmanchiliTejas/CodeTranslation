#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b,n;
  cin >>r >> g >> b;
  n = 100*r + 10*g + b;
  cout << (n%4 ==0 ? "YES" : "NO" )<< endl;
}
  
  